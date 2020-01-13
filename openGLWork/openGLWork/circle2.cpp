/*
正四边形，正五边形，正六边形，……，直到正n边形，当n越大时，这个图形就越接近圆
当n大到一定程度后，人眼将无法把它跟真正的圆相区别
这时我们已经成功的画出了一个“圆”
*/
#include "pch.h"
#include "circle2.h"
#include <GL/glut.h>
#include <math.h>
void circleDisplay();

const int n = 1000;
const GLfloat R = 0.5f;
const GLfloat PI = 3.1415926536f;
void circleDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++) {
		glVertex2f(R*cos(2 * PI / n * i), R*sin(2 * PI / n * i));
	}
	glEnd();
	glFlush();
}