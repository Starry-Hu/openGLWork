#include "pch.h"
#include "line1.h" //1.绘制直线
#include "triangle2.h" //2.1画三角形
#include "polygon2.h" //2.2画多边形
#include "circle2.h" //2.3画圆
#include "doubleBuffer3.h" //3双缓冲区三角形
#include "3D.h" //实验二：3D显示
#include <GL/glut.h>

int main(int argc, char *argv[])
{
	/*对GLUT进行初始化*/
	glutInit(&argc, argv);
	/*设置显示方式：RGB颜色，单缓冲*/
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	/*设置在窗口的中心位置*/
	glutInitWindowPosition(100, 100);
	/*设置窗口大小*/
	glutInitWindowSize(500, 500);

	//创建多个窗口并对每个窗口设置一个函数*/
	/*glutCreateWindow("1 - 直线");
	glutDisplayFunc(lineDisplay);

	glutCreateWindow("2.1 - 三角形");
	glutDisplayFunc(triangleDisplay);

	glutCreateWindow("2.2 - 多边形");
	glutDisplayFunc(polygonDisplay);

	glutCreateWindow("2.3 - 圆");
	glutDisplayFunc(circleDisplay);*/

	/*glutCreateWindow("3 - 双缓冲区三角形");
	glutDisplayFunc(doubleBufferDisplay);*/

	glutCreateWindow("实验二：3D展示");
	glutDisplayFunc(display3d);

	/*进行一个消息循环*/
	glutMainLoop();
	return 0;
}