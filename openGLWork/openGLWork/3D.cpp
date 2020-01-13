#include "pch.h"
#include <stdlib.h>
#include <GL/glut.h>
GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},
										 {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},{1.0,-1.0,1.0},
										 {1.0,1.0,1.0}, {-1.0,1.0,1.0} };
static GLfloat theta[] = { 0.0,0.0,0.0 };//�����᷽�����ת�Ƕ�
static GLint axis = 2; //��¼ÿ�β�����theta�±�
static GLdouble viewer[] = { 0.0, 0.0, 5.0 };//�����������

void display3d();

/* ���ƶ���� */
void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[a]);  glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);  glVertex3fv(vertices[d]);
	glEnd();
}
/* ���������θ������ɫ */
void colorcube()
{
	//��ǰ��
	glColor3f(1, 1, 1);     polygon(4, 5, 6, 7);
	//������
	glColor3f(1.0, 0, 0);   polygon(0, 3, 2, 1);

	glColor3f(0, 1, 0);     polygon(2, 3, 7, 6);
	glColor3f(0, 0, 1);     polygon(0, 4, 7, 3);
	glColor3f(1, 1, 0);     polygon(1, 2, 6, 5);
	glColor3f(0, 1, 1);     polygon(0, 1, 5, 4);
}
/* ��ʾ���� */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1);       
	glLoadIdentity();//���ص�λ����  
	//�����ӵ�λ��
	gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//��ת��ʽ���ǶȺ�������xyz�ᣬ��Ϊ0��Ϊ�������ᣬ����Ϊ��ʱ��
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0); /* ��ת������ */
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	colorcube();
	glutSwapBuffers();
} 
/* �� x, X, y, Y, z, and Z �� �ƶ��ӵ� */
void keys(unsigned char key, int x, int y)
{
	if (key == 'x') viewer[0] -= 1.0;
	if (key == 'X') viewer[0] += 1.0;
	if (key == 'y') viewer[1] -= 1.0;
	if (key == 'Y') viewer[1] += 1.0;
	if (key == 'z') viewer[2] -= 1.0;
	if (key == 'Z') viewer[2] += 1.0;
	display();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //��ͶӰ����Ӧ�����ľ������
	glLoadIdentity(); //���glMatrixModeһ��ʹ�ã��ѵ�ǰ��������Ϊ��λ����
	if (w <= h) {
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
			2.0* (GLfloat)h / (GLfloat)w, 2.0, 20.0); //����ǰ������һ��͸�Ӿ�����ˣ��ѵ�ǰ����ת���͸�Ӿ���
	}
	else{
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat)w / (GLfloat)h,
			2.0* (GLfloat)w / (GLfloat)h, 2.0, 20.0);
	}
		
	/* ������gluPerspective(45.0, w/h, 1.0, 10.0); */
	glMatrixMode(GL_MODELVIEW);
}
/* ��궨�� */
void mouse2(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
	theta[axis] -= 8.0;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	display();
}

/* ������ */
void display3d()
{
	//glutInit(&argc, argv);    
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D������");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);//�ı䴰�ڴ�Сʱ����ͼ�α���
	glutMouseFunc(mouse2); //��궨��
	glutKeyboardFunc(keys); //���̶���

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
