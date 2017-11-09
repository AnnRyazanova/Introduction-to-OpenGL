#include <windows.h>
#include <glew.h>
#include <freeglut.h>
#include <ctime>
#include <vector>

using std::vector;

struct Color
{
	float R;
	float G;
	float B;
};

int index = 0;
static Color color;
static int w = 0, h = 0;
bool firstShow = true;

// �-�� ���������� ����� ���������� � ������� ����
void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	color.R = color.G = color.B = 0.0f;
}

// �-�� ��������� ���������� �����
void changeColor()
{
	color.R = rand() % 256 / 255.0;
	color.G = rand() % 256 / 255.0;
	color.B = rand() % 256 / 255.0;
}

// �-�� ���������� �������������� (����-������� ��������)
void rectangle()
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(-0.1f, 0.1f);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.1f, -0.1f);
	glEnd();
}

// �-�� ���������� ����������� ����������:

void solidCube()
{ 
	glutSolidCube(0.5); 
}

// �-�� ���������� ������� ����
void wireCube()
{
	glutWireCube(0.5);
}

// �-�� ���������� ������� �������
void wireTeapot()
{
	glutWireTeapot(0.5);
}

// �-�� ���������� ������� ����
void wireTorus()
{
	glutWireTorus(0.3, 0.5, 4, 5);
}

// �-�� ���������� ������� ��������� 
void wireTetrahedron()
{
	glutWireTetrahedron();
}

// �-�� ���������� ������� ���������
void wireIcosahedron()
{
	glutWireIcosahedron();
}

// �-�� ���������� ������������
void triangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.9);
	glVertex2f(0.25f, 0.25f);
	glVertex2f(-0.25f, 0.25f);
	glVertex2f(0.0f, 0.5f);
	glEnd();
}

// �-�� ���������� ������������, ����������� � ��������� �����
void triangleWithDifferentVertex()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);	glVertex2f(0.25f, -0.25f);
	glColor3f(0.0, 1.0, 0.0);	glVertex2f(-0.25f, -0.25f);
	glColor3f(0.0, 0.0, 1.0);	glVertex2f(0.0f, -0.5f);
	glEnd();
}


typedef void(*callback_t)(void);
vector<callback_t> allPrimitives = { solidCube, wireCube, wireTeapot, wireTorus,
									 wireTetrahedron, wireIcosahedron };

// �-�� ��������� ��������� �� ������ ����
void mouseChangePrimitive(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		firstShow = false;
		changeColor();
		index = rand() % allPrimitives.size();
	}
}


// �-��, ���������� ������ ����
void update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	if (firstShow)
	{
		glColor3f(1.0, 0.26, 0.23);
		solidCube();
		triangle();
		rectangle();
		triangleWithDifferentVertex();
	}
	else 
	{
		// ��������� ��������� �� ������ ����
		glColor3f(color.R, color.G, color.B);
		allPrimitives[index]();
	}

	glFlush();
	glutSwapBuffers();
}

// �-��, ���������� ��� ��������� ������� ����
void reshape(int width, int height)
{
	w = width;
	h = height;
}



int main(int argc, char * argv[])
{
	srand(time(0));
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Introduction to OpenGL");		
	glutDisplayFunc(update);					
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseChangePrimitive);
	init();
	glutMainLoop();
	return 0;
}
