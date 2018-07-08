//Курсовая работа
//Игра "Змейка"
//основной файл main.cpp

#include "Main.h"
#include <unistd.h>

void Starttext()
{
    const char *p ;
    glRasterPos2i(400, 400);
    for(p = "Start";*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *p);
    }
    glRasterPos2i(390, 380);
    for(p = "Press Enter";*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *p);
    }
    glFlush(); //отрисовываем на экране
    glutSwapBuffers();
}


void GameOverText()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1, 1, 1);
    const char *p ;
    glRasterPos2i(390, 400);
    for(p = "GAMEOVER";*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *p);
    }
    glRasterPos2i(390, 380);
    for(p = "Press Enter";*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *p);
    }

    startgame = 0;
}
void TimeText()
{
    const char *p ;
    char chislo[2];
     glColor3d(1,1,1);
    sprintf(chislo, "%f",Timego);
    glRasterPos2i(10, 580);
    for(p = "Time:";*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
    }
    glRasterPos2i(10, 550);
    for(p = chislo;*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
    }
}
void ScoreText()
{
    const char *p ;
    char chislo[2];
    glColor3d(1,1,1);
    sprintf(chislo, "%i",score);
    glRasterPos2i(735, 580);
    for(p = "Score:";*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
    }
    glRasterPos2i(760, 550);
    for(p = chislo;*p;p++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
    }
}


void IfGameOver()
{
    if((Spart[0].x >= w)||(Spart[0].y >= h) ||(Spart[0].y <=0)||(Spart[0].x <=0))
    {
        if(startgame!=0)
        {
            GameOverText();
        }
    }
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}//???


void drawfield()
{
    glLineWidth(25);       // ширину линии
    glBegin(GL_LINES);
    glColor3d(1,2,0);     // красный цвет
    glVertex3d(0,0,0); // первая линия
    glVertex3d(0,600,0);
    glEnd();
    
    
    //__________________________
    glLineWidth(5);       // ширину линии
    glBegin(GL_LINES);
    glColor3d(1,2,0);     // красный цвет
    glVertex3d(70,540,0); // первая линия
    glVertex3d(70,600,0);
    glEnd();
    glLineWidth(5);       // ширину линии
    glBegin(GL_LINES);
    glColor3d(1,2,0);     // красный цвет
    glVertex3d(70,540,0); // первая линия
    glVertex3d(0,540,0);
    glEnd();
    //__________________________
    
    //__________________________
    glLineWidth(5);       // ширину линии
    glBegin(GL_LINES);
    glColor3d(1,2,0);     // красный цвет
    glVertex3d(730,540,0); // первая линия
    glVertex3d(730,600,0);
    glEnd();
    glLineWidth(5);       // ширину линии
    glBegin(GL_LINES);
    glColor3d(1,2,0);     // красный цвет
    glVertex3d(730,540,0); // первая линия
    glVertex3d(800,540,0);
    glEnd();
    //__________________________
    
    
    glLineWidth(25);       // ширину линии
    glColor3d(1,2,0);     // красный цвет
    glBegin(GL_LINES);
    //glColor3d(0,0.1,0.5);     // красный цвет
    glVertex3d(0,600,0); // первая линия
    glVertex3d(800,600,0);
    glEnd();
    glBegin(GL_LINES);
    //glColor3d(0,0.1,0.5);     // красный цвет
    glVertex3d(800,600,0); // первая линия
    glVertex3d(800,0,0);
    glEnd();
    glBegin(GL_LINES);
    //glColor3d(0,0.1,0.5);     // красный цвет
    glVertex3d(800,0,0); // первая линия
    glVertex3d(0,0,0);
    glEnd();
}
void drawsquare()    //функция рисования кубика
{
    
    for (int i = 0; i < kolsn; i++) // цикл отрисовки.
    {
        
        //glBegin(GL_QUADS); //начать рисование квадрата
        glColor3f(0.1, 1.0, 0.0);  //цвет верхнего левого угла
        glRectd(Spart[i].x, Spart[i].y, Spart[i].x+sizesnake, Spart[i].y-sizesnake); //создаем кубик змеи с размерами 15х15
        glLineWidth(1);       // ширину линии
        // устанавливаем 1
        glBegin(GL_LINES);
        glColor3d(1,0,0);     // красный цвет
        glVertex3d(Spart[i].x, Spart[i].y,0); // первая линия
        glVertex3d(Spart[i].x+sizesnake, Spart[i].y,0);
        glEnd();
        glBegin(GL_LINES);
        //glColor3d(0,0.1,0.5);     // красный цвет
        glVertex3d(Spart[i].x+sizesnake, Spart[i].y,0); // первая линия
        glVertex3d(Spart[i].x+sizesnake, Spart[i].y-sizesnake,0);
        glEnd();
        glBegin(GL_LINES);
        //glColor3d(0,0.1,0.5);     // красный цвет
        glVertex3d(Spart[i].x+sizesnake, Spart[i].y-sizesnake,0); // первая линия
        glVertex3d(Spart[i].x, Spart[i].y-sizesnake,0);
        glEnd();
        glBegin(GL_LINES);
        //glColor3d(0,0.1,0.5);     // красный цвет
        glVertex3d(Spart[i].x, Spart[i].y-sizesnake,0); // первая линия
        glVertex3d(Spart[i].x, Spart[i].y,0);
        glEnd();
    }
}

void drawfruit()
{
    for (int i = 0; i < 5; i++) // цикл отрисовки фрукта
    {
    glColor3f(0.0, 1.0, 1.0);
    glRectd(fruit[i].x, fruit[i].y , fruit[i].x+10,fruit[i].y-10);
    }
}
void randomfruit(int i)
{
        fruit[i].x=(rand()%40+1)*15; //создаем новый фрукт по координате Х от 10 до 780
        fruit[i].y=(rand()%30+1)*15;  //создаем новый фрукт по координате Х от 10 до 580
}



void move() //функция движения змеи
{
    int i;
    for(i=kolsn;i>0;--i) //цикл приравнивание каждого кубика змеи предыдущим
    {
    Spart[i].x=Spart[i-1].x;
    Spart[i].y=Spart[i-1].y;
    }
    switch (Spart[0].id) { // подсчет следующей координаты первого куба
        case 1:
            Spart[0].x-=speed*15;
            break;
        case 2:
            Spart[0].x+=speed*15;
            break;
        case 3:
            Spart[0].y+=speed*15;
            break;
        case 4:
            Spart[0].y-=speed*15;
            break;
    }
    for(i=0;i<5;i++)
    {
        if((Spart[0].x >= fruit[i].x)&&(Spart[0].x <= fruit[i].x+10))//фрукт съедается
        {
            if((Spart[0].y >= fruit[i].y)&&(Spart[0].y <= fruit[i].y+10))//
               {
                   kolsn++; //увеличение размера змеи
                   randomfruit(i); //создание нового фрукта
                   score++;
               }
        }
    }
}
void restart()
{
    memset(&Spart, 0, sizeof(Spart));
    Spart[0].x = 400;
    Spart[0].y = 300;
    Spart[0].id = 3;
    kolsn = 4;
    int i;
    for(i=0;i<5;i++) //создаем 5 фруктов
    {
        randomfruit(i);
        fruit[4].x = 400;
        fruit[4].y = 400;
    }
    Timego = 60;
    score = 0;
    
}

void display() //функция отрисовки
{
    glClear(GL_COLOR_BUFFER_BIT); //очищаем окно
    glLoadIdentity();
    //цикл отрисовки
    if(startgame == 1)
    {
        drawfield();
        drawsquare(); //рисуем квадраты
        drawfruit();
        IfGameOver();
        TimeText();
        ScoreText();
        Timego-=0.1;
    }
    else
    {
        Starttext();
    }
    //закончить
    
    glFlush(); //отрисовываем на экране
    
    glutSwapBuffers();
    
}

void processSpecialKeys(int key, int x, int y)  //отработка направления змеи при нажатии клавиш
{
    int id=3,i;
    switch(key) {
        case GLUT_KEY_LEFT :
            id = 1;
            break;
        case GLUT_KEY_RIGHT :
            id = 2;
            break;
        case GLUT_KEY_UP :
            id = 3;
            break;
        case GLUT_KEY_DOWN :
            id = 4;
            break;
    }
    for(i=0;i<kolsn;i++)
    {
        Spart[i].id = id; //присваивание всем кубикам направление
    }
}

void processNormalKeys(unsigned char key, int x, int y) { //отработка выхода из игры за счет клавиши ESC
    
    if (key == 27)
        exit(0);
    if(key == 13)
    {
        startgame = 1;
        restart();
    }
}

void timer(int = 0) // Таймер игры(промежуток времени, в котором будет производится все процессы)
{
    if(startgame == 1)
    {
        display(); // Вызов функций отрисовки
        move(); //функция движения
    }
    glutTimerFunc(100, timer, 0); // новый вызов таймера( 100 - промежуток времени(в милисекундах), через который он будет вызыватся, timer - вызываемый паблик)
}

int main (int argc, char * argv[])
{
    int i;
    //задаем изначальные координаты первых трех
    Spart[0].x = 40;
    Spart[0].y = 30;
    Spart[0].id = 3;
    
    
    for(i=0;i<5;i++) //создаем 5 фруктов
    {
        randomfruit(i);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    
    glutInitWindowSize(800, 600); //размеры окна
    glutCreateWindow("Snake"); //название окна
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    
    Starttext();
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    //процесс отбработки нажатой клавиши
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    //цикл обработки окна по времени
    glutTimerFunc(50, timer, 0);
    
    glutMainLoop();
    
    return 0;
}
