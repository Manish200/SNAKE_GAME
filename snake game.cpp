#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include<windows.h>

using namespace std;
bool gameover;
enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
string name;

 class Manish
 {
    public :

    const int width = 20 , heigth = 20;
    int x,y,fruitX,fruitY,score=0;
    int tailx[400],taily[400];
    int ntail;

    void setup()
    {
        gameover = false;
        dir = STOP;
        x = width/2;
        y = heigth/2;
        fruitX = rand() % width;
        fruitY = rand() % heigth;
        score = 0;
    }

     void draw()
    {
        system("cls");

        for(int i=0;i<width+2;i++)
            cout << "#";
        cout << endl;

        for(int i=0;i<heigth;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(j == 0)
                    cout  << "#";
                if(i == y && j == x)
                    cout << "O";
                else if(i == fruitY && j == fruitX )
                    cout << "F";
                else
                {  bool print = false;
                    for(int k=0;k<ntail;k++)
                    {
                        if( tailx[k] == j && taily[k] == i )
                        {
                            cout << "*";
                            print = true;
                        }
                    }
                    if(!print)
                        cout << " ";
                }
                if(j == (width-1))
                    cout << "#";
            }
            cout << endl;
        }

        for(int i=0;i<width+2;i++)
            cout << "#";

        cout << endl;

        cout << "SCORE FOR " << name << " IS -  " <<score;
    }

     void input()
    {
        if(_kbhit())
        {
            switch(_getch())
                {
                case 'a':
                    dir = LEFT;
                    break;
                case 'w':
                    dir = UP;
                    break;
                case 'd':
                    dir = RIGHT;
                    break;
                case 's':
                    dir = DOWN;
                    break;
                case 'x':
                    gameover = true;
                    break;
                }
        }
    }

     void logic()
    {
        int prevx = tailx[0];
        int prevy = taily[0];
        int prev2x,prev2y;
        tailx[0] = x;
        taily[0] = y;
        for(int i=1;i<ntail;i++)
        {
            prev2x = tailx[i];
            prev2y = taily[i];
            tailx[i] = prevx;
            taily[i] = prevy;
            prevx = prev2x;
            prevy = prev2y;
        }
        switch(dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }
        if(x > width || x < 0 || y > heigth || y < 0)
            gameover = true;

        for(int h=0;h<ntail;h++)
            if(tailx[h] == x && taily[h] == y)
                gameover = true;

        if(x == fruitX && y == fruitY)
        {
            score+= 10;
            fruitX = rand() % width;
            fruitY = rand() % heigth;
            ntail++;
        }
    }

};


int main()
{
    cout << "ENTER YOUR NAME " << endl;

    cin >> name;

    cout << "Do you want to play snake game enter y else n" << endl;

    char ch;

    int sp;

    cin >> ch;

    if(ch == 'y' || ch == 'Y')
    {
      ch = 'n';
       do
        {
            Manish m;

            cout << "ENTER THE SNAKE SPEED 1 , 2 , 3 , 4 , 5" << endl;

            cin >> sp;

                 m.setup();

              while(!gameover)
            {
                m.draw();
                m.input();
                m.logic();
                Sleep(100/sp);
            }

            cout << endl;

            cout << "CONGRATULATION "<< name << " YOUR SCORE WAS : " << m.score << endl;

            cout << endl;

            //if(m.score > maxscore)
              //  maxscore = m.score;

            cout << "Do you want to play snake game enter y else n" << endl;

            cin >> ch;

        } while(ch == 'y' || ch == 'Y');
    }

                    //cout << "CONGRATULATION YOUR HIGH SCORE IN THIS SESSION  : " << maxscore << endl;
    return 0;
}
