//
//  Main.h

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>

double speed = 1.0; //скорость
int kolsn = 4; //изначальное количетсво кубиков у змейки
int w = 800;
int h = 600;
int sizesnake = 20;
int startgame = 0;
double Timego = 60.0;
int score = 0;

struct tagSpart
{
    double x,y; //координаты кубика
    int id; // направление кубиков id=1 налево ;id=2 направо ;id=3 прямо; id=4 вниз;
}Spart[100];//структура змеи max 100

struct tagfruit
{
    double x,y;//координаты фруктов
}fruit[5]; //структура фруктов max 5


