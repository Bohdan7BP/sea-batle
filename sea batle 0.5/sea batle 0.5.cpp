#include <iostream>
#include "Ship.h"
#include "conio.h"
using namespace std;



int main()
{
    Scene scene;
    char** battleField = new char* [scene.k];
    for (size_t i = 0; i < scene.k; i++)
    {
        battleField[i] = new char[scene.k];
    }
    Ship flagShip{ 3, 4, 4,true };
    Ship cruiser{ 3, 4, 3,true };
    Ship smin{ 3, 4, 2,true };
    Ship cuter{ 3, 4, 1,true };


    initPole(scene);
    savepole(scene, battleField);
    position(scene, flagShip, battleField);
    savepole(scene, battleField);
    position(scene, cruiser, battleField);
    savepole(scene, battleField);
    position(scene, cruiser, battleField);

    savepole(scene, battleField);
    position(scene, smin, battleField);
    savepole(scene, battleField);
    position(scene, smin, battleField);
    savepole(scene, battleField);
    position(scene, smin, battleField);

    savepole(scene, battleField);
    position(scene, cuter, battleField);
    savepole(scene, battleField);
    position(scene, cuter, battleField);
    savepole(scene, battleField);
    position(scene, cuter, battleField);
    savepole(scene, battleField);
    position(scene, cuter, battleField);
    showPole(scene);

}