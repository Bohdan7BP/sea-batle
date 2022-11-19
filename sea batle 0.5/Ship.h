#pragma once
#include<iostream>
using namespace std;
struct Scene {
	int k = 10;
	char** pole;
};

struct Ship {
	// initial coordinate y
	int yShip;
	// initial coordinate x
	int xShip;
	// size ship
	int sizeShip;
	// orientation
	bool vertical;
	//char* ship;
	Scene poleSize;

	void moveRight() {
		if (vertical)
		{
			xShip += 1;
			if (xShip > poleSize.k - 1) {
				xShip -= 1;
			}
		}
		else
		{
			xShip += 1;
			if (xShip > poleSize.k - sizeShip) {
				xShip -= 1;
			}
		}
	}
	void moveLeft() {
		xShip -= 1;
		if (xShip < 0) {
			xShip += 1;
		}
	}
	void moveDown() {
		if (vertical)
		{
			yShip += 1;
			if (yShip > poleSize.k - sizeShip) {
				yShip -= 1;
			}
		}
		else
		{
			yShip += 1;
			if (yShip > poleSize.k - 1) {
				yShip -= 1;
			}
		}
	}
	void moveUp() {
		yShip -= 1;
		if (yShip < 0) {
			yShip += 1;
		}
	}
};

void initPole(Scene& obj);
void showPole(const Scene& obj);
void insertShip(Scene& scene, Ship& obj);
void revers(Ship& obj);
void savepole(Scene& obj, char** battlefield);
void redo(Scene& obj, char** battlefield);
void position(Scene& scene, Ship& obj, char** battlefield);