#include "pch.h"
#include <stdlib.h>
#include <GL/glut.h>
GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},
										 {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},{1.0,-1.0,1.0},
										 {1.0,1.0,1.0}, {-1.0,1.0,1.0} };
static GLfloat theta[] = { 0.0,0.0,0.0 };//各个轴方向的旋转角度
static GLint axis = 2; //记录每次操作的theta下标
static GLdouble viewer[] = { 0.0, 0.0, 5.0 };//照相机的坐标

void display3d();

/* 绘制多边形 */
void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[a]);  glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);  glVertex3fv(vertices[d]);
	glEnd();
}
/* 绘制正方形各面的颜色 */
void colorcube()
{
	//正前面
	glColor3f(1, 1, 1);     polygon(4, 5, 6, 7);
	//正背面
	glColor3f(1.0, 0, 0);   polygon(0, 3, 2, 1);

	glColor3f(0, 1, 0);     polygon(2, 3, 7, 6);
	glColor3f(0, 0, 1);     polygon(0, 4, 7, 3);
	glColor3f(1, 1, 0);     polygon(1, 2, 6, 5);
	glColor3f(0, 1, 1);     polygon(0, 1, 5, 4);
}
/* 显示函数 */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1);       
	glLoadIdentity();//加载单位矩阵  
	//更新视点位置
	gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//自转方式：角度和依靠的xyz轴，不为0的为依靠的轴，且正为逆时针
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0); /* 旋转立方体 */
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	colorcube();
	glutSwapBuffers();
} 
/* 用 x, X, y, Y, z, and Z 键 移动视点 */
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
	glMatrixMode(GL_PROJECTION); //对投影矩阵应用随后的矩阵操作
	glLoadIdentity(); //配合glMatrixMode一起使用，把当前矩阵设置为单位矩阵
	if (w <= h) {
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
			2.0* (GLfloat)h / (GLfloat)w, 2.0, 20.0); //将当前矩阵与一个透视矩阵相乘，把当前矩阵转变成透视矩阵
	}
	else{
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat)w / (GLfloat)h,
			2.0* (GLfloat)w / (GLfloat)h, 2.0, 20.0);
	}
		
	/* 或者用gluPerspective(45.0, w/h, 1.0, 10.0); */
	glMatrixMode(GL_MODELVIEW);
}
/* 鼠标定义 */
void mouse2(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
	theta[axis] -= 8.0;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	display();
}

/* 主函数 */
void display3d()
{
	//glutInit(&argc, argv);    
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("3D正方形");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);//改变窗口大小时保持图形比例
	glutMouseFunc(mouse2); //鼠标定义
	glutKeyboardFunc(keys); //键盘定义

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
