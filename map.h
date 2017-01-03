#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library

class House {
public:
	void SetHouse(GLfloat xx, GLfloat zz, GLfloat l, GLfloat w, GLfloat h);//�������� ����
	void SetColor(GLfloat r, GLfloat g, GLfloat b);//��������� ����� ��� ����
	GLfloat getX();
	GLfloat getZ();
	GLfloat getLength();
	GLfloat getWidth();
	GLfloat getHeight();
	GLfloat getRed();
	GLfloat getGreen();
	GLfloat getBlue();
private:
	GLfloat x;//���������� �� �����������
	GLfloat z;//���������� ����������
	GLfloat length;//�����
	GLfloat width;//������
	GLfloat height;//������
	GLfloat red;//
	GLfloat green;//
	GLfloat blue;//
};
class Map {
public:
	Map(int n);
	void CreateHouse(GLfloat xx, GLfloat zz, GLfloat l, GLfloat w, GLfloat h);//�������� ����
	void DrawHouse(House house);//��������� ������ ����
	void DrawAll();//��������� ���� �����
	House *city;//������ �����
private:	
	int max_num;//���� ���-�� ����� � ������ 
	int num;//���-�� ����������� �����
};

