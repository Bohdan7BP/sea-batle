#include "Ship.h"
#include <conio.h>

void initPole(Scene& obj)
{
	char** pole = new char* [obj.k];
	for (int i = 0; i < obj.k; i++)
	{
		pole[i] = new char[obj.k];
	}
	for (int i = 0; i < obj.k; i++)
	{
		for (int j = 0; j < obj.k; j++)
		{
			pole[i][j] = '~';
		}
	}
	obj.pole = pole;
}

void showPole(const Scene& obj)
{
	int b = 97;
	for (int n = 0; n < obj.k + 1; n++)
	{
		cout << n << " ";
	}
	cout << endl;
	for (int i = 0; i < obj.k; i++)
	{
		cout << (char)b++ << " ";
		for (int j = 0; j < obj.k; j++)
		{
			cout << obj.pole[i][j] << " ";
		}
		cout << endl;
	}
}
void revers(Ship& obj);
void insertShip(Scene& scene, Ship& obj)
{
	int N = obj.sizeShip;
	if (obj.vertical == true)
	{
		for (int i = 0; i < N; i++)
		{
			scene.pole[obj.yShip + i][obj.xShip] = '0';
		}
	}
	else if (obj.vertical == false)
	{
		for (int i = 0; i < N; i++)
		{
			scene.pole[obj.yShip][obj.xShip + i] = '0';
		}
	}
}


void revers(Ship& obj)
{
	if (obj.vertical == true) {

		if (obj.poleSize.k - obj.xShip < obj.sizeShip)
		{
			return;
		}
		else
		{
			obj.vertical = false;
		}
	}
	else if (obj.vertical == false)
	{
		if (obj.poleSize.k - obj.yShip < obj.sizeShip)
		{
			return;
		}
		else
		{
			obj.vertical = true;
		}
	}

}

void savepole(Scene& obj, char** battlefield)
{
	for (size_t i = 0; i < obj.k; i++)
	{
		for (size_t j = 0; j < obj.k; j++)
		{
			battlefield[i][j] = obj.pole[i][j];
		}
	}
}

void redo(Scene& obj, char** battlefield)
{
	for (size_t i = 0; i < obj.k; i++)
	{
		for (size_t j = 0; j < obj.k; j++)
		{
			obj.pole[i][j] = battlefield[i][j];
		}
	}
}

void position(Scene& scene, Ship& obj, char** battlefield)
{
	int key;
	while (true) {
		redo(scene, battlefield);
		insertShip(scene, obj);
		showPole(scene);
		key = _getch();
		switch (key)
		{
		case 114:revers(obj);
			break;
		case 77:obj.moveRight();
			break;
		case 75:obj.moveLeft();
			break;
		case 80:obj.moveDown();
			break;
		case 72:obj.moveUp();
			break;
		case 102:system("cls");
			system("cls");
			return;
		}
		system("cls");
	}
}
