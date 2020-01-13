#include "pch.h"
#include <GL/glut.h>

void triangleDisplay();

void triangleDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); //清除颜色

	//画4个不同颜色的三角形
	glBegin(GL_TRIANGLES);
	glColor3f(0.2f, 0.4f, 0.8f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.0f, 1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9f, 0.9f, 0.0f);  
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(1.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);  
	glVertex2f(0.5f, -0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, -1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9f, 0.5f, 0.9f);  
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-1.0f, 0.0f);
	glEnd();

	//中间嵌入白色正方形
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);//这个函数只能画正的正方形

	glFlush();
}