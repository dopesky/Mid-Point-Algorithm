#include <iostream>
#include <Windows.h>
#include <GL/glut.h>
#include <algorithm>

using namespace std;

int x00 = 0;
int y00 = 0;
int radius;

void bres()
{
	//Draw the first Point
	glPointSize(5.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x00, radius + y00);
	glEnd();
	//Calculate Initial Decision Parameter
	int p = 1 - radius;
	//Initialize x and y
	int x = 0, y = radius;
	while (x <= y) {
		x++;
		if (p < 0) {
			//if p < 0 then plot (x++,y) and p+1 = p + 2 * x + 3
			p = 2 * x + 3 + p;
			glBegin(GL_POINTS);
			glVertex2i(x + x00, y + y00);
			glVertex2i(-x + x00, y + y00);
			glVertex2i(x + x00, -y + y00);
			glVertex2i(-x + x00, -y + y00);
			glVertex2i(y + x00, x + y00);
			glVertex2i(-y + x00, x + y00);
			glVertex2i(y + x00, -x + y00);
			glVertex2i(-y + x00, -x + y00);
			glEnd();
		} else {
			//if p >= 0 then plot (x++,y--) and p+1 = p + 2 * x - 2 * y + 5
			p = p + 2 * x - 2 * y + 5;
			glBegin(GL_POINTS);
			glVertex2i(x + x00, --y + y00);
			glVertex2i(-x + x00, y + y00);
			glVertex2i(x + x00, -y + y00);
			glVertex2i(-x + x00, -y + y00);
			glVertex2i(y + x00, x + y00);
			glVertex2i(-y + x00, x + y00);
			glVertex2i(y + x00, -x + y00);
			glVertex2i(-y + x00, -x + y00);
			glEnd();
		}
	}
}

void display()
{
	//clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	bres();
	glFlush();//enable fast execution of statements

}

int main(int argc, char* argv[])
{
	cout << "Enter the Coordinates for Circle Center: \nX: ";
	cin >> x00;
	cout << "Y: ";
	cin >> y00;

	//Get circle radius from user
	cout << "Enter the Radius of the circle (Number between 0 and 400)\nradius: ";
	cin >> radius;

	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Bresenham's Algorithm!");

	//Initialize color used to clear color buffer
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//Initialize the draw area
	gluOrtho2D(-400, 400, -400, 400);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}