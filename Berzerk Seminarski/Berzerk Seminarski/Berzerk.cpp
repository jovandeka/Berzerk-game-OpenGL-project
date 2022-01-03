
//Igrica Berzerk (uproscena verzija)

#include <math.h>		
#include <stdio.h>
#include <stdlib.h>		
#include "Glut.h"
#include "Berzerk_header.h"

const double Xmin = 0.0, Xmax = 3.0;
const double Ymin = 0.0, Ymax = 3.0;

double iks = 0.2;
double ipsilon = 1.7;
double neprijatelj1x = 0.5;
double neprijatelj1y = 2.5;
double neprijatelj2x = 1.5;
double neprijatelj2y = 0.8;
double neprijatelj3x = 2.5;
double neprijatelj3y = 1;

int stanje1 = 1;
int stanje2 = 1;
int stanje3 = 1;

bool udar = false;
bool pobeda = false;

void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(1);
	case 'a':
		if (iks >= 0.12) {
			if (iks >= 0.95 && iks <= 1.12 && ipsilon >= 1 && ipsilon <= 3 || iks >= 1.95 && iks <= 2.13 && ipsilon <= 2.3 && ipsilon >= 0) { udar = true; }
			else iks -= 0.03;
		}break;
	case 'd':
		if (iks >= 2.82 && ipsilon >= 1.3 && ipsilon <= 1.8)
		{
			pobeda = true;
			iks += 1.5;
		}
		if (iks <= 2.82) {
			if (iks >= 0.90 && iks<= 1 && ipsilon >= 1 && ipsilon <=3 || iks>=1.90 && iks <= 2 && ipsilon<=2.3 && ipsilon >= 0) { udar = true; }
			else iks += 0.03;
		}break;
	case 's':
		if (ipsilon >= 0.4) {
			if (iks >= 1.92 && iks <= 2.11 && ipsilon <= 2.33 && ipsilon >= 0) { udar = true; }
			else ipsilon -= 0.03;
		}break;
	case 'w':
		if (ipsilon <= 2.9) {
			if (iks >= 0.93 && iks <= 1.1 && ipsilon >= 0.96 && ipsilon <= 3 ) { udar = true; }
			else ipsilon += 0.03;
		}break;
	}
}

	void mySpecialKeyFunc(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		if (iks >= 0.12) {
			if (iks >= 0.95 && iks <= 1.12 && ipsilon >= 1 && ipsilon <= 3 || iks >= 1.95 && iks <= 2.13 && ipsilon <= 2.3 && ipsilon >= 0) { udar = true; }
			else iks -= 0.03;
		}break;
	case GLUT_KEY_RIGHT:
		if (iks >= 2.82 && ipsilon >= 1.3 && ipsilon <= 1.8)
		{
			pobeda = true;
		}
		if (iks <= 2.82) {
			if (iks >= 0.90 && iks <= 1 && ipsilon >= 1 && ipsilon <= 3 || iks >= 1.90 && iks <= 2 && ipsilon <= 2.3 && ipsilon >= 0) { udar = true; }
			else iks += 0.03;
		}break;
	case GLUT_KEY_DOWN:
		if (ipsilon >= 0.4) {
			if (iks >= 1.92 && iks <= 2.11 && ipsilon <= 2.33 && ipsilon >= 0) { udar = true; }
			else ipsilon -= 0.03;
		}break;
	case GLUT_KEY_UP:
		if (ipsilon <= 2.9) {
			if (iks >= 0.93 && iks <= 1.1 && ipsilon >= 0.96 && ipsilon <= 3) { udar = true; }
			else ipsilon += 0.03;
		}break;
	}
}


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//igrac
	glTranslatef(iks, ipsilon, 0.0);
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.05, 0.0, 0.0);
	glVertex3f(0.05, -0.05, 0.0);
	glVertex3f(0.0, -0.05, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.03, -0.05, 0.0);
	glVertex3f(0.08, -0.05, 0.0);
	glVertex3f(0.08, -0.2, 0.0);
	glVertex3f(-0.03, -0.2, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.3, 0.0);
	glVertex3f(-0.02, -0.3, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.03, -0.2, 0.0);
	glVertex3f(0.07, -0.2, 0.0);
	glVertex3f(0.07, -0.3, 0.0);
	glVertex3f(0.03, -0.3, 0.0);
	glEnd();
	glTranslatef(-iks, -ipsilon, 0.0);
	//neprijatelj1
	switch (stanje1)
	{
	case 1:
		neprijatelj1y -= 0.0005;
		if (neprijatelj1y <= 0.8) { stanje1 = 2; }
		break;
	case 2:
		neprijatelj1y += 0.0005;
		if (neprijatelj1y >= 2.1) { stanje1 = 1; }
		break;
	}
	glTranslatef(neprijatelj1x, neprijatelj1y, 0.0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.05, 0.0, 0.0);
	glVertex3f(0.05, -0.05, 0.0);
	glVertex3f(0.0, -0.05, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.03, -0.05, 0.0);
	glVertex3f(0.08, -0.05, 0.0);
	glVertex3f(0.08, -0.2, 0.0);
	glVertex3f(-0.03, -0.2, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.3, 0.0);
	glVertex3f(-0.02, -0.3, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.03, -0.2, 0.0);
	glVertex3f(0.07, -0.2, 0.0);
	glVertex3f(0.07, -0.3, 0.0);
	glVertex3f(0.03, -0.3, 0.0);
	glEnd();
	glTranslatef(-neprijatelj1x, -neprijatelj1y, 0.0);
	//neprijatelj2
	switch (stanje2)
	{
	case 1:
		neprijatelj2x -= 0.0005;
		if (neprijatelj2x <= 0.5) { stanje2 = 2; }
		break;
	case 2:
		neprijatelj2x += 0.0005;
		if (neprijatelj2x >= 1.8) { stanje2 = 1; }
		break;
	}
	glTranslatef(neprijatelj2x, neprijatelj2y, 0.0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.05, 0.0, 0.0);
	glVertex3f(0.05, -0.05, 0.0);
	glVertex3f(0.0, -0.05, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.03, -0.05, 0.0);
	glVertex3f(0.08, -0.05, 0.0);
	glVertex3f(0.08, -0.2, 0.0);
	glVertex3f(-0.03, -0.2, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.3, 0.0);
	glVertex3f(-0.02, -0.3, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.03, -0.2, 0.0);
	glVertex3f(0.07, -0.2, 0.0);
	glVertex3f(0.07, -0.3, 0.0);
	glVertex3f(0.03, -0.3, 0.0);
	glEnd();
	glTranslatef(-neprijatelj2x, -neprijatelj2y, 0.0);
	//neprijatelj3
	switch (stanje3)
	{
	case 1:
		neprijatelj3y += 0.0005;
		if (neprijatelj3y >= 2.5) { stanje3 = 2; }
		break;
	case 2:
		neprijatelj3x -= 0.0005;
		if (neprijatelj3x <= 1.5) { stanje3 = 3; }
		break;
	case 3:
		neprijatelj3x += 0.0005;
		if (neprijatelj3x >= 2.5) { stanje3 = 4; }
		break;
	case 4:
		neprijatelj3y -= 0.0005;
		if (neprijatelj3y <= 1.0) { stanje3 = 1; }
		break;
	}
	glTranslatef(neprijatelj3x, neprijatelj3y, 0.0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.05, 0.0, 0.0);
	glVertex3f(0.05, -0.05, 0.0);
	glVertex3f(0.0, -0.05, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.03, -0.05, 0.0);
	glVertex3f(0.08, -0.05, 0.0);
	glVertex3f(0.08, -0.2, 0.0);
	glVertex3f(-0.03, -0.2, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.2, 0.0);
	glVertex3f(0.02, -0.3, 0.0);
	glVertex3f(-0.02, -0.3, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.03, -0.2, 0.0);
	glVertex3f(0.07, -0.2, 0.0);
	glVertex3f(0.07, -0.3, 0.0);
	glVertex3f(0.03, -0.3, 0.0);
	glEnd();
	glTranslatef(-neprijatelj3x, -neprijatelj3y, 0.0);
	//zidovi
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.02, 2.98, 0.0);
	glVertex3f(0.06, 2.98, 0.0);
	glVertex3f(0.06, 1.8, 0.0);
	glVertex3f(0.02, 1.8, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.03, 1.8, 0.0);
	glVertex3f(0.05, 1.8, 0.0);
	glVertex3f(0.05, 1.3, 0.0);
	glVertex3f(0.03, 1.3, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.02, 1.3, 0.0);
	glVertex3f(0.06, 1.3, 0.0);
	glVertex3f(0.06, 0.02, 0.0);
	glVertex3f(0.02, 0.02, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.02, 2.98, 0.0);
	glVertex3f(2.98, 2.98, 0.0);
	glVertex3f(2.98, 2.94, 0.0);
	glVertex3f(0.02, 2.94, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.02, 0.06, 0.0);
	glVertex3f(2.98, 0.06, 0.0);
	glVertex3f(2.98, 0.02, 0.0);
	glVertex3f(0.02, 0.02, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(2.94, 2.98, 0.0);
	glVertex3f(2.98, 2.98, 0.0);
	glVertex3f(2.98, 1.8, 0.0);
	glVertex3f(2.94, 1.8, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	if (pobeda == true) {
		glColor3f(0.0, 1.0, 0.0);
	}
	glVertex3f(2.95, 1.8, 0.0);
	glVertex3f(2.97, 1.8, 0.0);
	glVertex3f(2.97, 1.3, 0.0);
	glVertex3f(2.95, 1.3, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(2.94, 1.3, 0.0);
	glVertex3f(2.98, 1.3, 0.0);
	glVertex3f(2.98, 0.02, 0.0);
	glVertex3f(2.94, 0.02, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.02, 2.98, 0.0);
	glVertex3f(1.06, 2.98, 0.0);
	glVertex3f(1.06, 1.0, 0.0);
	glVertex3f(1.02, 1.0, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(2.02, 2.0, 0.0);
	glVertex3f(2.06, 2.0, 0.0);
	glVertex3f(2.06, 0.02, 0.0);
	glVertex3f(2.02, 0.02, 0.0);
	glEnd();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void initRendering()
{
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}

void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	glViewport(0, 0, w, h);

	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;
	if ((Xmax - Xmin) / w < (Ymax - Ymin) / h) {
		scale = ((Ymax - Ymin) / h) / ((Xmax - Xmin) / w);
		center = (Xmax + Xmin) / 2;
		windowXmin = center - (center - Xmin)*scale;
		windowXmax = center + (Xmax - center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax - Xmin) / w) / ((Ymax - Ymin) / h);
		center = (Ymax + Ymin) / 2;
		windowYmin = center - (center - Ymin)*scale;
		windowYmax = center + (Ymax - center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(windowXmin, windowXmax, windowYmin, windowYmax, -1, 1);

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(10, 60);
	glutInitWindowSize(360, 360);

	glutCreateWindow("Berzerk game");

	initRendering();

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyFunc);


	glutReshapeFunc(resizeWindow);


	glutDisplayFunc(drawScene);

	glutMainLoop();

	return(0);
}

