
#include<GL/glut.h> 
#include<cmath>
#include<stdio.h>



void init()
{
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);

}
void setpixel(int x,int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void bresenham(int x0, int y0, int xend, int yend)
{
	int dx = fabs(xend - x0), dy = fabs(yend - y0);
	int twody = 2 * dy;
	int p = 2 * (dy)-dx;
	int twodyminusdx = 2 * (dy - dx);
	int x, y;
	if (x0 > xend)
	{
		x = xend;
		y = yend;
		xend = x0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	setpixel(x, y);
	while (x < xend)
	{
		x++;
		if (p < 0)
		{
			p += twody;
		}
		else
		{
			y++;
			p += twodyminusdx;
		}
		setpixel(x, y);
	}
}


void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	int x0, y0, xend, yend;
	printf("enter x,y,xend,yend");
	scanf_s("%d%d%d%d", &x0, &y0, &xend, &yend);
	
	bresenham(x0, y0, xend, yend);
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(700, 100);
	glutCreateWindow("bresenham");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
