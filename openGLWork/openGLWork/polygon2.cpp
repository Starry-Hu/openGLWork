#include "pch.h"
#include <GL/glut.h>

void polygonDisplay();

void polygonDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.3f, 0.1f);
	glVertex2f(0.1f, 0.3f);
	glVertex2f(0.4f, 0.6f);
	glEnd();
	glFinish();
}