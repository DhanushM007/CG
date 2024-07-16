#include<GL/glut.h>
#include<cmath>

float rot1 = 0, rot2 = 0, rot3 = 0, movex = 0, movey = 0, movez = 0;
float s = 0.9;
void init()
{
	glMatrixMode(GL_MODELVIEW);;
	glEnable(GL_DEPTH_TEST);

}

void face(float p[8][3], int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glVertex3fv(p[a]);
	glVertex3fv(p[b]);
	glVertex3fv(p[c]);
	glVertex3fv(p[d]);
	glEnd();

}

void cube(float tx,float ty,float tz,float rx,float ry,float rz,float scale,float c)
{
	float vertices[8][3] = {
		{-1,-1,-1},
		{-1,-1,1},
		{1,-1,1},
		{1,-1,-1},
		{-1,1,-1},
		{-1,1,1},
		{1,1,1},
		{1,1,-1}
	};

	rx += rot1;
	ry += rot2;
	rz += rot3;

	rx = rx * 3.14 / 180.0;
	ry = ry * 3.14 / 180.0;
	rz = rz * 3.14 / 180.0;

	for (int i = 0;i < 8;i++)
	{
		float x = vertices[i][0];
		float y = vertices[i][1];
		float z = vertices[i][2];

		x = x * scale + tx;
		y = y * scale + ty;
		z = z * scale + tz;

		//rot about x
		float t, k;
		t = y * cos(rx) - z * sin(rx);
		z = y * sin(rx) + z * cos(rx);
		y = t;
		
		//rot about y
		t = z * cos(ry) - x * sin(ry);
		x = z * sin(ry) + x * cos(ry);
		z = t;
		
		//rot about z
		t = x * cos(rz) - y * sin(rz);
		y = x * sin(rz) + y * cos(rz);
		x = t;
	

		x += movex;
		y += movey;
		z += movez;

		vertices[i][0] = x;
		vertices[i][1] = y;
		vertices[i][2] = z;

	}
	glColor3f(c, 0, 0);
	face(vertices, 0, 1, 2, 3);

	glColor3f(0, c, 0);
	face(vertices, 4, 5, 6, 7);

	glColor3f(0, 0, c);
	face(vertices, 2, 3, 7, 6);

	glColor3f(c, c, 0);
	face(vertices, 0, 1, 5, 4);

	glColor3f(0, c, c);
	face(vertices, 1,2,6,5);

	glColor3f(c, 0, c);
	face(vertices, 0,3,7,4);




}


void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	cube(0, 0, 0, 0, 0, 0, 1, 1);
	glutSwapBuffers();

}

void keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 'x':rot1++;
		break;
	case 'X':rot1--;
		break;

	case 'y':rot2++;
		break;
	case 'Y':rot2--;
		break;


	case 'z':rot3++;
		break;
	case 'Z':rot3--;
		break;

	case 'l':movex+=0.05;
		break;
	case 'L':movex-=0.05;
		break;

	case 'k':movey+=0.05;
		break;
	case 'K':movey-=0.05;
		break;

	case 'j':movez+=0.05;
		break;
	case 'J':movez-=0.05;
		break;




	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3d");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}


