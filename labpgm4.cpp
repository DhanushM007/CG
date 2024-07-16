
//labpgm4-2D using built in

#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

float angle = 0.0;
float tx = 0.0, ty = 0.0;
float scale = 1.0;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(tx, ty, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(scale, scale, 1.0);


	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex2f(0, 0.5);

		glColor3f(0, 1, 0);
		glVertex2f(0.5, -0.5);

		glColor3f(0, 0, 1);
		glVertex2f(-0.5, -0.5);
	glEnd();
	glFlush();


}
void reshape(int w, int h)
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);

	if (w > h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-1.0 * (float)w / (float)h, 1.0 * (float)w / (float)h, -1.0, 1.0);
		glMatrixMode(GL_MODELVIEW);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-1.0, 1.0, -1.0 * (float)h / (float)w, 1.0 * (float)h / (float)w);
		glMatrixMode(GL_MODELVIEW);
	}
	glutPostRedisplay();
}


void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		ty += 0.1;
		break;
	case 'a':
		tx += 0.1;
		break;
	case 's':
		ty -= 0.1;
		break;
	case 'd':
		tx -= 0.1;
		break;
	case'+':
		scale += 0.1;
		if (scale > 2.0) scale = 2.0;
		reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

		break;
	case '-':
		scale -= 0.1;
		if (scale < 1.0) scale = 1.0;
		reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	case 'r':
		angle += 5.0;
		break;
	case 'l':
		angle -= 5.0;
		break;
	case 27:exit(0);
	}
	glutPostRedisplay();
}





int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2D");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);
	
	glutMainLoop();
	return 0;
}