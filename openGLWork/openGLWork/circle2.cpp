/*
���ı��Σ�������Σ��������Σ�������ֱ����n���Σ���nԽ��ʱ�����ͼ�ξ�Խ�ӽ�Բ
��n��һ���̶Ⱥ����۽��޷�������������Բ������
��ʱ�����Ѿ��ɹ��Ļ�����һ����Բ��
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