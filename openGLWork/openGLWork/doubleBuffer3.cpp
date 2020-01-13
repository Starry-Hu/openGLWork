#include "pch.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define DEG_TO_RAD 0.017453
static GLfloat theta = 0.0;
// 设置三角形初始颜色
GLfloat r = 1.0;
GLfloat g = 1.0;
GLfloat b = 1.0;
int doubleb;

void doubleBufferDisplay();

void displayd()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	r = r - 0.002;
	g = g + 0.002;
	b = b + 0.001;
	if (r < 0.001) {
		r = 1.0;
		g = 0.0;
		b = 0.0;
	}
	glBegin(GL_POLYGON);
	glVertex2f(cos(DEG_TO_RAD*theta), sin(DEG_TO_RAD*theta));
	glVertex2f(cos(DEG_TO_RAD*theta + DEG_TO_RAD * 120), sin(DEG_TO_RAD*theta + DEG_TO_RAD * 120));
	glVertex2f(cos(DEG_TO_RAD*theta + DEG_TO_RAD * 240), sin(DEG_TO_RAD*theta + DEG_TO_RAD * 240));
	glEnd();
	glutSwapBuffers();//交换两个缓冲区指针,实现双缓冲 - 如果是单缓冲则是glFlush刷新缓冲
}

// 三角形转动弧度设置
void SpinDisplay(void)
{
	theta = theta + 0.01;
	if (theta > 360.0)
		theta = theta - 360.0;

	glutSetWindow(doubleb);
	glutPostWindowRedisplay(doubleb);
}

// 鼠标定义
void mouse(int btn, int state, int x, int y)
{
	// 鼠标左键按下继续旋转
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(SpinDisplay);
	// 鼠标中键按下暂停旋转
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
	// 鼠标右键按下退出
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0);
}
// 键盘定义q/Q退出
void mykey(unsigned char key, int x, int y)
{
	if (key == 'Q' || key == 'q') exit(0);
}
// 主函数
void doubleBufferDisplay()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(310, 0);
	doubleb = glutCreateWindow("3 - 双缓冲区三角形");
	glClearColor(1.0, 1.0, 1.0, 1.0);// 调整背景颜色
	glutDisplayFunc(displayd);
	glutIdleFunc(SpinDisplay);//回调旋转的方法
	glutMouseFunc(mouse);//鼠标定义
	glutKeyboardFunc(mykey);//键盘定义

	glutMainLoop();
}

