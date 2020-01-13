#include "pch.h"
#include <GL/glut.h>
void lineDisplay();

void lineDisplay()
{
	//glClearColor(1.0f, 0.0f, 0.0f, 0.0f);// 清除屏幕所用的颜色
	glClear(GL_COLOR_BUFFER_BIT);//清除屏幕颜色，若有新的颜色则用新的颜色，默认是黑色

	// ---- 测试直线 ---	
	glLineWidth(10.0f);//指定线宽
	glBegin(GL_LINES); //在下面2个点之间画一条线段
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glEnd();
	
	// ---- 测试直线 （宽度颜色改变） ---	
	glLineWidth(20.0f); //线宽改变
	glColor3f(0.5f, 0.5f, 0.5f); //图元颜色改变
	glBegin(GL_LINES);
	glVertex2f(-0.5f, 0.25f);
	glVertex2f(0.5f, 0.25f);
	glEnd(); 

	// ---- 测试折线（不闭合） ---
	glLineWidth(10.0f);
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(0.5f, 0.0f); 
	glVertex2f(0.35f, 0.10f);
	glEnd();

	// ---- 测试折线（闭合） ---
	glLineWidth(10.0f);
	glColor3f(0.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(0.6f, -0.4f);
	glVertex2f(0.25f, -0.16f);
	glEnd();

	// ---- 测试虚线 ---
	glEnable(GL_LINE_STIPPLE);//启动虚线模式，使用glDisable(GL_LINE_STIPPLE)可以关闭
	glLineStipple(2, 0x0F0F);//设置虚线的样式
	glLineWidth(10.0f);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glFlush();
	// 保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）
	// OpenGL指令不是立即执行的。它们首先被送到指令缓冲区，然后才被送到硬件执行。
	// glFlush都是强制将命令缓冲区的内容提交给硬件执行。
}
