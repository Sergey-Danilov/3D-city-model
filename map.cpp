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
	GLfloat len = house.getLength();//первый размер, большее значение
	GLfloat hei = house.getHeight();//второй размер, большее значение
	GLfloat wid = house.getWidth();//третий размер, большее значение
	GLfloat r = house.getRed();
	GLfloat g = house.getGreen();
	GLfloat b = house.getBlue();  
	glTranslatef(firstKoor,0.0,secondKoor);          //Устанавиваем расположение дома
	//glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
	for (int floor = 0; floor < hei; floor++)//отрисовка по этажам
	{
		for (int side = 0; side < wid; side++)//отрисовка боковых частей
		{
			for (int front = 0; front < len; front++)//отрисовка основной части
			{
				glBegin(GL_QUADS);			// Рисуем куб
				glColor3f(r, g, b);		// цвет дома

				glVertex3f( 1 + front, 1 + floor, side);		// Право верх квадрата (Верх)
				glVertex3f( front, 1 + floor, side);		// Лево верх
				glVertex3f( front, 1 + floor, 1 + side);		// Лево низ
				glVertex3f( 1 + front, 1 + floor, 1 + side);		// Право низ

				glVertex3f( 1 + front, floor, 1 + side);		// Верх право квадрата (Низ)
				glVertex3f( front, floor, 1 + side);		// Верх лево
				glVertex3f( front, floor, 1 + side);		// Низ лево
				glVertex3f( 1 + front, floor, side);		// Низ право

				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, 1 + side);		// Верх право квадрата (Перед)
				glTexCoord2f(0.0f, 1.0f); glVertex3f( front, 1 + floor, 1 + side);		// Верх лево
				glTexCoord2f(0.0f, 0.0f); glVertex3f( front, floor, 1 + side);		// Низ лево
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1 + front, floor, 1 + side);		// Низ право

				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1 + front, floor, side);		// Верх право квадрата (Зад)
				glTexCoord2f(1.0f, 0.0f); glVertex3f( front, floor, side);		// Верх лево
				glTexCoord2f(1.0f, 1.0f); glVertex3f( front, 1 + floor, side);		// Низ лево
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, side);		// Низ право

				glTexCoord2f(1.0f, 1.0f); glVertex3f( front, 1 + floor, 1 + side);		// Верх право квадрата (Лево)
				glTexCoord2f(0.0f, 1.0f); glVertex3f( front, 1 + floor, side);		// Верх лево
				glTexCoord2f(0.0f, 0.0f); glVertex3f( front, floor, side);		// Низ лево
				glTexCoord2f(1.0f, 0.0f); glVertex3f( front, floor, 1 + side);		// Низ право

				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, side);		// Верх право квадрата (Право)
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1 + front, 1 + floor, 1 + side);		// Верх лево
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1 + front, floor, 1 + side);		// Низ лево
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1 + front, floor, side);		// Низ право

				glEnd();				// Закончили квадраты
			}
		}
	}
	glTranslatef(-firstKoor,0.0,-secondKoor);//возвращаем центр системы координат в (0;0)
};
void Map::DrawAll()
{
	for (int i = 0; i < num; i++)
	{
		DrawHouse(city[i]);
	}
}