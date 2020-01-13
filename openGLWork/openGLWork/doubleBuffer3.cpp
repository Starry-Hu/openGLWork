#include "pch.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define DEG_TO_RAD 0.017453
static GLfloat theta = 0.0;
// ���������γ�ʼ��ɫ
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
	glutSwapBuffers();//��������������ָ��,ʵ��˫���� - ����ǵ���������glFlushˢ�»���
}

// ������ת����������
void SpinDisplay(void)
{
	theta = theta + 0.01;
	if (theta > 360.0)
		theta = theta - 360.0;

	glutSetWindow(doubleb);
	glutPostWindowRedisplay(doubleb);
}

// ��궨��
void mouse(int btn, int state, int x, int y)
{
	// ���������¼�����ת
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(SpinDisplay);
	// ����м�������ͣ��ת
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
	// ����Ҽ������˳�
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0);
}
// ���̶���q/Q�˳�
void mykey(unsigned char key, int x, int y)
{
	if (key == 'Q' || key == 'q') exit(0);
}
// ������
void doubleBufferDisplay()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(310, 0);
	doubleb = glutCreateWindow("3 - ˫������������");
	glClearColor(1.0, 1.0, 1.0, 1.0);// ����������ɫ
	glutDisplayFunc(displayd);
	glutIdleFunc(SpinDisplay);//�ص���ת�ķ���
	glutMouseFunc(mouse);//��궨��
	glutKeyboardFunc(mykey);//���̶���

	glutMainLoop();
}

