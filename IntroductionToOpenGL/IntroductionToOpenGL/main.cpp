#include <windows.h>
#include <glew.h>
#include <freeglut.h>

static int w = 0, h = 0;

void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

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

void solidCube()
{
	glColor3f(0.47, 0.26, 0.23);
	glutSolidCube(0.5);
}

void triangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.9);
	glVertex2f(0.25f, 0.25f);
	glVertex2f(-0.25f, 0.25f);
	glVertex2f(0.0f, 0.5f);
	glEnd();
}

void triangleWithDifferentVertex()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);	glVertex2f(0.25f, -0.25f);
	glColor3f(0.0, 1.0, 0.0);	glVertex2f(-0.25f, -0.25f);
	glColor3f(0.0, 0.0, 1.0);	glVertex2f(0.0f, -0.5f);
	glEnd();
}

void update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	solidCube();
	triangle();
	rectangle();
	triangleWithDifferentVertex();

	glFlush();
	glutSwapBuffers();
}


//Сункц§ вызываема§ при изменении размеров окна
void reshape(int width, int height)
{
	w = width;
	h = height;
}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Introduction to OpenGL");		
	glutDisplayFunc(update);					
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}
