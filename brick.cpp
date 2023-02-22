#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//..........Prototypes.......//
void mainlogo();
void frontheader();
void maze();
void printCharacter(int playerX, int playerY);
void removeCharacter(int playerX, int playerY);
/*void printenemy1(int x, int y);
void printenemy2(int x, int y);
void printenemy3(int x, int y);*/

void addscore();

void printEnemy();
void removeEnemy();
void bulletCollionWithEnemy();
void moveEnemy();

void removeBullet();
void enemy();
void gotoxy(int x, int y);
void generateBullet();
char getCharAtxy(short int x, short int y);

void generateBullet();
void moveBullet();
void bulletPrint(int x, int y);
void removebullet(int x, int y);
void makeBulletInactive(int index);

void printEnemyHealth();
void printCharacterHealth();

void generateEnemyBullet();
void printEnemyBullet(int x, int y);
void eraseEnemyBullet(int x, int y);
void moveEnemyBullet();
void makeEnemyBulletInactive(int index);

void printFizz();
void moveFizz();
void eraseFizz();
void bulletCollionWithFizz();

void printJames();
void moveJames();
void eraseJames();
void bulletCollionWithJames();

void printEnemyHealth();
void printCharacterHealth();

void eraseEnemyHealth();
void eraseCharacterHealth();


void printScore();
void loginoption();
void options();
void Keys();
void bulletInactive();
void presskey();
//----------------------------------------//

//::::::::::::::Global_Varibales::::::::::::::::://
string choice;
int playerX = 5;
int playerY = 36;

int enemyX = 15;
int enemyY = 20;

int JamesX = 25;
int JamesY = 20;

int FizzX = 45;
int FizzY = 20;

int JamesTimer=3 ;
int EnemyTimer=3; 
int FizzTimer=3; 

string enemyDirection = "Up";
string JamesDirection="Left";
string FizzDirection="Up";
int score = 0;
int enemyHealth = 100;
int characterHealth = 100;

int bulletCount = 0;


//::::::Global Arrays:::::://
int enemyBulletX[1000];
int enemyBulletY[1000];
bool isEnemyBulletActive[1000];
int enemyBulletCount = 0;

char box = 219;

char face2=15,leg1=94;
char face3=147,leg2=94;

char enemy1[6] = {' ', ' ', ' ', '-', '-', '-'};
char enemy2[6] = {'<', '=', '=', '(', '0', ')'};
char enemy3[6] = {' ', ' ', ' ', '\\', '@', '/'};
char enemy4[6] = {' ', ' ', ' ', '*', '*', '*'};

char Fizz1[5]={'<','=','=',' ',face2};
char Fizz2[6]={' ',' ',' ', '(',' ',')'};
char Fizz3[6]={' ',' ',' ',' ',leg1,' '};

char James1[5]={'<','=','=',' ',face3};
char James2[6]={' ',' ',' ', '[',' ',']'};
char James3[6]={' ',' ',' ',' ',leg2,' '};

int bulletX[1000];
int bulletY[1000];
bool isbulletActive[1000];

//:::::::::Global Array::::::://

main()
{
    int timer = 0;
    system("cls");
    frontheader();
    Sleep(1000);
    mainlogo();
    loginoption();
    while (choice != "0")
    {
        cout << "Enter your choice :";
        cin >> choice;
        if (choice == "1")
        {
            system("cls");
            maze();

            printCharacter(playerX, playerY);
            printEnemy();
            printJames();
            printFizz();
            

            while (true)
            {
                printScore();
                if (enemyHealth <= 0)
                {
                    removeEnemy();
                    cout << "Game Over !";
                    break;
                }
                if (characterHealth <= 0)
                {
                    removeCharacter(playerX, playerY);
                    break;
                }
                 
                 printCharacterHealth();
                if (GetAsyncKeyState(VK_LEFT))
                {
                    char nextlocation = getCharAtxy(playerX - 1, playerY);
                    if (nextlocation != '*')
                    {
                        removeCharacter(playerX, playerY);
                        playerX = playerX - 1;
                        printCharacter(playerX, playerY);
                        nextlocation = getCharAtxy(playerX - 1, playerY);
                    }
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    char nextlocation = getCharAtxy(playerX + 3, playerY);
                    if (nextlocation != '*')
                    {
                        removeCharacter(playerX, playerY);
                        playerX = playerX + 1;
                        printCharacter(playerX, playerY);
                        nextlocation = getCharAtxy(playerX + 1, playerY);
                    }
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generateBullet();
                }
       if(EnemyTimer==3)
      {
        moveEnemy();
        EnemyTimer=0;
      }
       if(FizzTimer==3)
      {
        moveFizz();
        FizzTimer=0;
      }
       if(JamesTimer==3)
      {
        moveJames();
        JamesTimer=0;
      }
      moveBullet();
      moveEnemyBullet();
      bulletCollionWithEnemy();
      EnemyTimer++;
      bulletCollionWithFizz();
      FizzTimer++;
      bulletCollionWithJames();
      JamesTimer++;  
    Sleep(90);
    printEnemyHealth();
            }
        }

        else if (choice == "2")
        {
            options();
            cout << "Enter your choice :" << endl;
            cin >> choice;
            if (choice == "3")
            {
            }
        }
    }
    loginoption();
    options();
    Keys();
}

void mainlogo()
{
    system("cls");
    cout << "\t\t"
         << "***********************************************************************************************" << endl;
    cout << "\t\t"
         << "*  @@@@@@@@@@@@@@@@@@     #@@@@@@@@@@@@@@@@@@*    .@@@@@@@@@@@@@@@@@@@-    =@@@@@@@@@@@@@@@@@ *" << endl;
    cout << "\t\t"
         << "*  @@@@@@@@@@@@@@@@@@     #@@@@@@@@@@@@@@@@@@*    .@@@@@@@@@@@@@@@@@@@-    =@@@@@@@@@@@@@@@@@ *" << endl;
    cout << "\t\t"
         << "*  ==================     -==================-     ===================.    :================= *" << endl;
    cout << "\t\t"
         << "*                                                                                             *" << endl;
    cout << "\t\t"
         << "*          :@@@@@@@@@@@@@@@@@@@:    +@@@@@@@@@@@@@@@@@@@@     #@@@@@@@@@@@@@@@@@=             *" << endl;
    cout << "\t\t"
         << "*          :@@@@@@@@@@@@@@@@@@@:    +@@@@@@@@@@@@@@@@@@@@     #@@@@@@@@@@@@@@@@@=             *" << endl;
    cout << "\t\t"
         << "*           :::::::::::::::::::     ---------------------     ::::::::::::::::::              *" << endl;
    cout << "\t\t"
         << "*                                                                                             *" << endl;
    cout << "\t\t"
         << "*                      ....................      ....................                         *" << endl;
    cout << "\t\t"
         << "*                      @@@@@@@@@@@@@@@@@@@@-    =@@@@@@@@@@@@@@@@@@@@#                        *" << endl;
    cout << "\t\t"
         << "*                      @@@@@@@@@@@@@@@@@@@@-    =@@@@@@@@@@@@@@@@@@@@#                        *" << endl;
    cout << "\t\t"
         << "*                                                                                             *" << endl;
    cout << "\t\t"
         << "*                                          .-=--.                                             *" << endl;
    cout << "\t\t"
         << "*                                        =%@@@@@@%-                                           *" << endl;
    cout << "\t\t"
         << "*                                       +@@@@@@@@@@=                                          *" << endl;
    cout << "\t\t"
         << "*                                        =@@@@@@@@=                                           *" << endl;
    cout << "\t\t"
         << "*                                          :===-:                                             *" << endl;
    cout << "\t\t"
         << "*                                                                                             *" << endl;
    cout << "\t\t"
         << "*          -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%                                                *" << endl;
    cout << "\t\t"
         << "***********************************************************************************************" << endl;
    presskey();
}
void frontheader()
{
    system("cls");
    system ("Color 0B");
    cout << " 88888888ba   88888888ba   88    ,ad8888ba,   88      a8P       88888888ba   88888888ba   88888888888         db         88      a8P   88888888888  88888888ba   " << endl;
    cout << " 88       8b  88       8b  88   d8        8b  88    ,88         88       8b  88       8b  88                 d88b        88    ,88     88           88       8b  " << endl;
    cout << " 88      ,8P  88      ,8P  88  d8             88  ,88           88      ,8P  88      ,8P  88                d8 `8b       88  ,88       88           88      ,8P  " << endl;
    cout << " 88aaaaaa8P'  88aaaaaa8P'  88  88             88,d88'           88aaaaaa8P'  88aaaaaa8P'  88aaaaaaaaa      d8'  `8b      88,d88'       88aaaaa      88aaaaaa8P'  " << endl;
    cout << " 88      8b,  88    88     88  88             8888 88,          88      8b,  88    88     88              d8YaaaaY8b     8888 88,      88           88    88     " << endl;
    cout << " 88      `8b  88    `8b    88  Y8,            88P   Y8b         88      `8b  88    `8b    88             d8        8b    88P   Y8b     88           88    `8b    " << endl;
    cout << " 88      a8P  88     `8b   88   Y8a.    .a8P  88      88,       88      a8P  88     `8b   88            d8'        `8b   88      88,   88           88     `8b   " << endl;
    cout << " 88888888P    88      `8b  88      Y8888Y     88       Y8b      88888888P    88      `8b  88888888888  d8'          `8b  88       Y8b  88888888888  88      `8b  " << endl;
    loginoption();
}

void loginoption()
{
    cout << "   MENU    " << endl;
    cout << "_______________________________" << endl;
    cout << " 1 - Start  " << endl;
    cout << " 2 - Option " << endl;
    cout << " 3 - Exit   " << endl;
}

void options()
{
    system("cls");
    cout << "1- Keys." << endl;
    cout << "2- Instructions" << endl;
    cout << "3 - Exit" << endl;
}

void Keys()
{
    cout << " Keys " << endl;
    cout << "______________________________" << endl;
    cout << "1-UP           GO UP" << endl;
    cout << "2-DOWN         GO DOWN" << endl;
    cout << "3-LEFT         GO LEFT" << endl;
    cout << "4-RIGHT        GO RIGHT" << endl;
    cout << "5-LEFT         FIRE USER" << endl;
    cout << "6-ESC          EXIT GAME" << endl;
}

void presskey()
{
    cout << "Enter any key to continue......." << endl;
    getch();
}

void maze()
{
    system("cls");
    gotoxy(0, 6);

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);



    cout << "***********************************************************************************************" << endl;
    cout << "*   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  *" << endl;
    cout << "*    _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _    *" << endl;
    cout << "*  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   *" << endl;
    cout << "*   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  *" << endl;
    cout << "*    _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _    *" << endl;
    cout << "*  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   *" << endl;
    cout << "*    _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _    *" << endl;
    cout << "*  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "*                                                                                             *" << endl;
    cout << "***********************************************************************************************" << endl;

 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void printCharacter(int playerX, int playerY)
{

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);           

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);

    gotoxy(playerX, playerY);
    cout << " ^" << endl;
    gotoxy(playerX, playerY + 1);
    cout << " |" << endl;
    gotoxy(playerX, playerY + 2);
    cout << " |" << endl;
    gotoxy(playerX, playerY + 3);
    cout << box << box << box;

SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


}

void removeCharacter(int playerX, int playerY)
{
    gotoxy(playerX, playerY);
    cout << "  " << endl;
    gotoxy(playerX, playerY + 1);
    cout << "  " << endl;
    gotoxy(playerX, playerY + 2);
    cout << "  " << endl;
    gotoxy(playerX, playerY + 3);
    cout << "   " << endl;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void generateBullet()
{
    bulletX[bulletCount] = playerX;
    bulletY[bulletCount] = playerY - 1;
    isbulletActive[bulletCount] = true;
    gotoxy(playerX, playerY - 1);
    cout << '.';
    bulletCount++;
}
void bulletInactive(int index)
{
    isbulletActive[index] = false;
}
void moveBullet()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isbulletActive[i] == true)
        {
            char next = getCharAtxy(bulletX[i], bulletY[i] - 1);
            if (next != ' ' && next != '*' && next != '_')
            {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletInactive(i);
                score++;
            }
            else if (next == '*')
            {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletInactive(i);
            }
            else if (next == '_')
            {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletY[i] = bulletY[i] - 1;
                bulletPrint(bulletX[i], bulletY[i]);
                 eraseBullet(bulletX[i], bulletY[i]);
                 score++;
            }
            else
            {
                eraseBullet(bulletX[i], bulletY[i]);
                bulletY[i] = bulletY[i] - 1;
                bulletPrint(bulletX[i], bulletY[i]);
            }
        }
    }
}
void bulletPrint(int x, int y)
{
    gotoxy(x, y);
    cout << '.';
}

void printEnemy()
{

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                 

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    gotoxy(enemyX, enemyY);
    for (int i = 0; i < 6; i++)
    {
        cout << enemy1[i];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int i = 0; i < 6; i++)
    {
        cout << enemy2[i];
    }
    gotoxy(enemyX, enemyY + 2);
    for (int i = 0; i < 6; i++)
    {
        cout << enemy3[i];
    }
    gotoxy(enemyX, enemyY + 3);
    for (int i = 0; i < 6; i++)
    {
        cout << enemy4[i];
    }

SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void removeEnemy()
{
    gotoxy(enemyX, enemyY);
    for (int i = 0; i < 6; i++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int i = 0; i < 6; i++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 2);
    for (int i = 0; i < 6; i++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 3);
    for (int i = 0; i < 6; i++)
    {
        cout << " ";
    }
}

void moveEnemy()
{
    if (enemyDirection == "Up")
    {
        char next = getCharAtxy(enemyX, enemyY - 1);
        if (next == ' ')
        {
            removeEnemy();
            enemyY--;
            printEnemy();
            //generateEnemyBullet();
        }
        else if (next == '_' || next == '*')
        {
            enemyDirection = "Down";
        }
    }

    if (enemyDirection == "Down")
    {
        char next = getCharAtxy(enemyX, enemyY + 4);
        if (next == ' ')
        {
            removeEnemy();
            enemyY++;
            printEnemy();
            //generateEnemyBullet();
        }
        else if (next == '*')
        {
            enemyDirection = "Up";
        }
    }
}
void bulletCollionWithEnemy()
{
    for(int x=0 ; x < bulletCount; x++)
    {
        if(isbulletActive[x])
        {
        
            if(bulletX[x]+1==enemyX && (bulletY[x]==enemyY|| bulletY[x]==enemyY+2 || bulletY[x]== enemyY +3))
            {
               addscore();
               eraseEnemyHealth();
               enemyHealth = enemyHealth -5;
            }
            if(enemyX-1 == bulletX[x]&& enemyY+1==bulletY[x])
            {
                addscore();
                eraseEnemyHealth();
                enemyHealth = enemyHealth - 5;
            }
        }
    }
}


void generateEnemyBullet()
{
    enemyBulletX[enemyBulletCount] = enemyX -7;
    enemyBulletY[enemyBulletCount] = enemyY +1;
    isEnemyBulletActive[enemyBulletCount] = true;
    gotoxy(enemyBulletX[enemyBulletCount], enemyBulletY[enemyBulletCount]);
    cout << "-";
    enemyBulletCount++;
}

void moveEnemyBullet()
{
    for (int i = 0; i < enemyBulletCount; i++)
    {
        if (isEnemyBulletActive[i] == true)
        {
            char next = getCharAtxy(enemyBulletX[i] - 1, enemyBulletY[i]);
            if (next != ' ')
            {
                eraseEnemyBullet(enemyBulletX[i], enemyBulletY[i]);
                makeEnemyBulletInactive(i);
            }
            else
            {
                eraseEnemyBullet(enemyBulletX[i], enemyBulletY[i]);
                enemyBulletX[i]--;
                printEnemyBullet(enemyBulletX[i], enemyBulletY[i]);
            }
        }
    }
}


void printEnemyBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}

void eraseEnemyBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void makeEnemyBulletInactive(int index)
{
    isEnemyBulletActive[index] = false;
}

void addscore()
{
    score++;
}

void printScore()
{
    gotoxy(110, 20);
    cout << "Score is:" << score;
}
void printFizz()
{

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);               

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);


     gotoxy(FizzX,FizzY);
    for(int idx=0;idx<5;idx++)
    {
        cout<<Fizz1[idx];
    }
     gotoxy(FizzX,FizzY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout<<Fizz2[idx];
    }
     gotoxy(FizzX,FizzY+2);
    for(int idx=0;idx<6;idx++)
    {
        cout<<Fizz3[idx];
    }

SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void moveFizz()
{
    if(FizzDirection=="Up")
    {
        char next=getCharAtxy(FizzX,FizzY-1);
        if(next==' ')
        {
          eraseFizz();
          FizzY--;
          printFizz();
        }
        else if(next=='_'|| next == '*')
        {
            FizzDirection="Down";
        }
    }
    if(FizzDirection=="Down")
    {
        char next=getCharAtxy(FizzX,FizzY+4);
        if(next==' ')
        {
            eraseFizz();
            FizzY++;
            printFizz();
        }
        if(next=='*')
        {
            FizzDirection="Up";
        }
    }
   
}

void eraseFizz()
{
    gotoxy(FizzX,FizzY);
    for(int idx=0;idx<5;idx++)
    {
        cout<<" ";
    }
    gotoxy(FizzX,FizzY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout<<" ";
    }
    gotoxy(FizzX,FizzY+2);
    for(int idx=0;idx<6;idx++)
    {
        cout<<" ";
    }
}

void bulletCollionWithFizz()
{
    for(int x=0 ; x < bulletCount; x++)
    {
        if(isbulletActive[x]==true)
        {
        
            if(bulletX[x]+1==FizzX && (bulletY[x]==FizzY|| bulletY[x]==FizzY+2))
            {
                addscore();
            }
            if(FizzX-1 == bulletX[x]&& FizzY+1==bulletY[x])
            {
                addscore();
            }
        }
    }
}

void printJames()
{

 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                 // This is used to give Green color to Shifu

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);



     gotoxy(JamesX,JamesY);
    for(int idx=0;idx<5;idx++)
    {
        cout<<James1[idx];
    }
     gotoxy(JamesX,JamesY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout<<James2[idx];
    }
     gotoxy(JamesX,JamesY+2);
    for(int idx=0;idx<6;idx++)
    {
        cout<<James3[idx];
    }

SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_BLUE);


}

void moveJames()
{
    if(JamesDirection=="Right")
    {
        char next=getCharAtxy(JamesX+10,JamesY);
        if(next == ' ')
        {
          eraseJames();
          JamesX++;
          printJames();
        }
        if(next=='*')
        {
            JamesDirection="Left";
        }
    }
    if(JamesDirection=="Left")
    {
        char next=getCharAtxy(JamesX-1,JamesY);
        if(next==' ')
        {
            eraseJames();
            JamesX--;
            printJames();
        }
        if(next=='*')
        {
            JamesDirection="Right";
        }
    }
}
void eraseJames()
{
    gotoxy(JamesX,JamesY);
    for(int idx=0;idx<5;idx++)
    {
        cout<<" ";
    }
    gotoxy(JamesX,JamesY+1);
    for(int idx=0;idx<6;idx++)
    {
        cout<<" ";
    }
    gotoxy(JamesX,JamesY+2);
    for(int idx=0;idx<6;idx++)
    {
        cout<<" ";
    }
}

void bulletCollionWithJames()
{
    for(int x=0 ; x < bulletCount; x++)
    {
        if(isbulletActive[x]==true)
        {
        
            if(bulletX[x]+1==JamesX && (bulletY[x]==JamesY|| bulletY[x]==JamesY+2))
            {
                addscore();
            }
            if(JamesX-1 == bulletX[x]&& JamesY+1==bulletY[x])
            {
                addscore();
            }
        }
    }
}


void eraseEnemyHealth()
{
    gotoxy(110, 15);
    cout << "                                               ";
}
void printEnemyHealth()
{
    if (enemyHealth >= 0)
    {
        gotoxy(110, 15);
        cout << "Enemy1 Health: " << enemyHealth;
    }
}

void printCharacterHealth()
{
    if (characterHealth >= 0)
    {
        gotoxy(110, 10);
        cout << "Character Health: " << characterHealth;
    }
}

void eraseCharacterHealth()
{
    gotoxy(110, 10);
    cout << "                  ";
}

