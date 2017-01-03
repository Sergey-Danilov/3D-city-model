#include "map.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>	// Header File For The Glaux Library

void House::SetHouse(GLfloat xx, GLfloat zz, GLfloat l, GLfloat w, GLfloat h)
{
	x = xx;
	z = zz;
	length = l;
	width = w;
	height = h;
	red = 1;//red = GLfloat(rand()%101) / 100;
	green = 1;//green = GLfloat(rand()%101) / 100;
	blue = 1;//blue = GLfloat(rand()%101) / 100;
};
void House::SetColor(GLfloat r, GLfloat g, GLfloat b)
{
	red = r;
	green = g;
	blue = b;
};
GLfloat House::getX()	{ return x; }
GLfloat House::getZ()	{ return z; }
GLfloat House::getLength()	{ return length; }
GLfloat House::getWidth()	{ return width; }
GLfloat House::getHeight()	{ return height; }
GLfloat House::getRed()		{ return red; }
GLfloat House::getGreen()	{ return green; }
GLfloat House::getBlue()	{ return blue; }
Map::Map(int n)
{
	max_num = n;
	city = new House[n];
	num = 0;
};
void Map::CreateHouse(GLfloat xx, GLfloat zz, GLfloat l, GLfloat w, GLfloat h)
{
	city[num].SetHouse(xx, zz, l, w, h);
	num++;
};
void Map::DrawHouse(House house)
{
	GLfloat firstKoor = house.getX();
	GLfloat secondKoor = house.getZ();
	GLfloat len = house.getLength();//������ ������, ������� ��������
	GLfloat hei = house.getHeight();//������ ������, ������� ��������
	GLfloat wid = house.getWidth();//������ ������, ������� ��������
	GLfloat r = house.getRed();
	GLfloat g = house.getGreen();
	GLfloat b = house.getBlue();  
	glTranslatef(firstKoor,0.0,secondKoor);          //������������ ������������ ����
	//glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
	for (int floor = 0; floor < hei; floor++)//��������� �� ������
	{
		for (int side = 0; side < wid; side++)//��������� ������� ������
		{
			for (int front = 0; front < len; front++)//��������� �������� �����
			{
				glBegin(GL_QUADS);			// ������ ���
				glColor3f(r, g, b);		// ���� ����

				glVertex3f( 1 + front, 1 + floor, side);		// ����� ���� �������� (����)
				glVertex3f( front, 1 + floor, side);		// ���� ����
				glVertex3f( front, 1 + floor, 1 + side);		// ���� ���
				glVertex3f( 1 + front, 1 + floor, 1 + side);		// ����� ���

				glVertex3f( 1 + front, floor, 1 + side);		// ���� ����� �������� (���)
				glVertex3f( front, floor, 1 + side);		// ���� ����
				glVertex3f( front, floor, 1 + side);		// ��� ����
				glVertex3f( 1 + front, floor, side);		// ��� �����

				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, 1 + side);		// ���� ����� �������� (�����)
				glTexCoord2f(0.0f, 1.0f); glVertex3f( front, 1 + floor, 1 + side);		// ���� ����
				glTexCoord2f(0.0f, 0.0f); glVertex3f( front, floor, 1 + side);		// ��� ����
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1 + front, floor, 1 + side);		// ��� �����

				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1 + front, floor, side);		// ���� ����� �������� (���)
				glTexCoord2f(1.0f, 0.0f); glVertex3f( front, floor, side);		// ���� ����
				glTexCoord2f(1.0f, 1.0f); glVertex3f( front, 1 + floor, side);		// ��� ����
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, side);		// ��� �����

				glTexCoord2f(1.0f, 1.0f); glVertex3f( front, 1 + floor, 1 + side);		// ���� ����� �������� (����)
				glTexCoord2f(0.0f, 1.0f); glVertex3f( front, 1 + floor, side);		// ���� ����
				glTexCoord2f(0.0f, 0.0f); glVertex3f( front, floor, side);		// ��� ����
				glTexCoord2f(1.0f, 0.0f); glVertex3f( front, floor, 1 + side);		// ��� �����

				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, side);		// ���� ����� �������� (�����)
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, 1 + side);		// ���� ����
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1 + front, floor, 1 + side);		// ��� ����
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1 + front, floor, side);		// ��� �����

				glEnd();				// ��������� ��������
			}
		}
	}
	glTranslatef(-firstKoor,0.0,-secondKoor);//���������� ����� ������� ��������� � (0;0)
};
void Map::DrawAll()
{
	for (int i = 0; i < num; i++)
	{
		DrawHouse(city[i]);
	}
}