#include "pch.h"
#include "line1.h" //1.����ֱ��
#include "triangle2.h" //2.1��������
#include "polygon2.h" //2.2�������
#include "circle2.h" //2.3��Բ
#include "doubleBuffer3.h" //3˫������������
#include "3D.h" //ʵ�����3D��ʾ
#include <GL/glut.h>

int main(int argc, char *argv[])
{
	/*��GLUT���г�ʼ��*/
	glutInit(&argc, argv);
	/*������ʾ��ʽ��RGB��ɫ��������*/
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	/*�����ڴ��ڵ�����λ��*/
	glutInitWindowPosition(100, 100);
	/*���ô��ڴ�С*/
	glutInitWindowSize(500, 500);

	//����������ڲ���ÿ����������һ������*/
	/*glutCreateWindow("1 - ֱ��");
	glutDisplayFunc(lineDisplay);

	glutCreateWindow("2.1 - ������");
	glutDisplayFunc(triangleDisplay);

	glutCreateWindow("2.2 - �����");
	glutDisplayFunc(polygonDisplay);

	glutCreateWindow("2.3 - Բ");
	glutDisplayFunc(circleDisplay);*/

	/*glutCreateWindow("3 - ˫������������");
	glutDisplayFunc(doubleBufferDisplay);*/

	glutCreateWindow("ʵ�����3Dչʾ");
	glutDisplayFunc(display3d);

	/*����һ����Ϣѭ��*/
	glutMainLoop();
	return 0;
}