#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library

class House {
public:
	void SetHouse(GLfloat xx, GLfloat zz, GLfloat l, GLfloat w, GLfloat h);//создание дома
	void SetColor(GLfloat r, GLfloat g, GLfloat b);//установка цвета для дома
	GLfloat getX();
	GLfloat getZ();
	GLfloat getLength();
	GLfloat getWidth();
	GLfloat getHeight();
	GLfloat getRed();
	GLfloat getGreen();
	GLfloat getBlue();
private:
	GLfloat x;//координата по горизонтали
	GLfloat z;//координата углубления
	GLfloat length;//длина
	GLfloat width;//ширина
	GLfloat height;//высота
	GLfloat red;//
	GLfloat green;//
	GLfloat blue;//
};
class Map {
public:
	Map(int n);
	void CreateHouse(GLfloat xx, GLfloat zz, GLfloat l, GLfloat w, GLfloat h);//создание дома
	void DrawHouse(House house);//отрисовка одного дома
	void DrawAll();//отрисовка всех домов
	House *city;//массив домов
private:	
	int max_num;//макс кол-во домов в городе 
	int num;//кол-во добавленных домов
};

