
#include<GL/glut.h>
#include<math.h>
float tx = 0.0, ty = 0.0, tz = 0.0;
float anglex = 0.0, angley = 0.0, anglez = 0.0;
float scale = 1.0;

void init()
{
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}


void cube()
{
	//front face
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(-0.5,0.5,0.5);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(-0.5,-0.5,0.5);

	//back face
	glColor3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	

	//right face
	glColor3f(0, 0, 1);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);

	//left face
	glColor3f(1, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//top face
	glColor3f(0, 1, 1);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//bottom face
	glColor3f(1, 0, 1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
}

void display()
{

	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(tx,ty,tz);
	glRotatef(anglex,1.0,0.0,0.0);
	glRotatef(angley,0.0,1.0,0.0);
	glRotatef(anglez,0.0,0.0,1.0);
	glScalef(scale,scale,scale);

	cube();
	glutSwapBuffers();


}


void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'x':
			anglex += 5.0;
			break;
		case 'X':
			anglex -= 5.0;
			break;
		case 'y':
			angley += 5.0;
			break;

		case 'Y':
			angley -= 5.0;
			break;
		case 'z':
			anglez += 5.0;
			break;
		case 'Z':
			anglez -= 5.0;
			break;

		case '+':
			scale += 0.1;
			if (scale >2) scale = 2.0;
			break;
		case '-':
			scale -= 0.1;
			if (scale <1) scale = 1.0;
			break;
		case 'u':
			tx += 0.1;
			break;
		case 'U':
			tx -= 0.1;
			break;
		case 'v':
			ty += 0.1;
			break;
		case 'V':
			ty -= 0.1;
			break;
		case 'w':
			tz += 0.1;
			break;
		case 'W':
			tz -= 0.1;
			break;

	}
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D");
	init();
	glutDisplayFunc(display);
	
	glutKeyboardFunc(Keyboard);

	glutMainLoop();
	return 0;
}