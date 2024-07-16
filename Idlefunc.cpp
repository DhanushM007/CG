#include<GL/glut.h>
#include<cmath>

float x, y, r = 50;
float angle = 0;
bool re = false;


void init()
{
	gluOrtho2D(-100, 100, -100, 100);

}

void idle()
{
	if (re)
	{
			angle += 1.0;
			if (angle >= 360)
			{
				angle = 0.0;
			}

	}
	glutPostRedisplay();

}

void display()
{

	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	x = r * cos(angle * 3.14 / 180);
	y = r * sin(angle * 3.14 / 180);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(-1*y, x);
	glVertex2f(-1*x, -1*y);
	glVertex2f(y,-1*x);
	glEnd();
	glutSwapBuffers();



}
void mouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
		re = true;
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
		re = false;

	
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("IDLE FUNC");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
		glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}