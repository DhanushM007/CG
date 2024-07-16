//basic geometric on 2d objects
#include<GL/glut.h>
#include<math.h>
float tx = 0, ty = 0;
float sx = 1, sy = 1;
float angle = 0;

float vertices[3][2] =
{
	{0,0.5},{0.5,-0.5},{-0.5,-0.5}
};

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

	glBegin(GL_TRIANGLES);
		for(int i = 0;i < 3;i++)
		{
			float x = vertices[i][0];
			float y = vertices[i][1];

			x += tx;
			y += ty;

			x *= sx;
			y *= sy;

			float rad = angle * 3.14 / 180;
			float x_rot = x * cos(rad) - y * sin(rad);
			float y_rot = x * sin(rad) + y * cos(rad);

			x = x_rot;
			y = y_rot;

			glVertex2f(x, y);

		}
	glEnd();
	glFlush();
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
			sx += 0.1;
			sy += 0.1;
			if (sx > 2) sx = 2;
			if (sy > 2) sy = 2;
			break;
		case '-':
			sx -= 0.1;
			sy -= 0.1;
			if (sx < 1) sx = 1;
			if (sy < 1) sy = 1;
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

void reshape(int w, int h)
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);

	if (w > h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-1*(float)w/(float)h, 1*(float)w/(float)h, -1, 1);
		glMatrixMode(GL_MODELVIEW);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-1, 1, -1*(float)h/(float)w, 1*(float)h/(float)w);
		glMatrixMode(GL_MODELVIEW);
	}
	glutPostRedisplay();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2D");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}