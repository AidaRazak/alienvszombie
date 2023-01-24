#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include <conio.h> //for press any key
#include <stdlib.h>
using namespace std;

class AVZ
{
private:
    vector<vector<char> > map_; // convention to put trailing underscore
    int numX_, numY_;          // to indicate private data
public:
    AVZ(int rows = 5, int col = 15, int zombie = 2); // constructor with number of rows and columns
    void initArray();                                // function to intialize the array
    void displayArray() const;                       // function to display the array
    void displaySettings() const;                    // to display default game settings
    void insertRandomCharacter(char ch);
    int getDimX() const;
    int getDimY() const;
    void setRows(int rows);
    void setCol(int col);
    void setZombie(int zombie);
    void init(int numX,int numY);
    int rows_, col_;
    int zombie_;
};

AVZ::AVZ(int rows, int col, int zombie)
{
    rows_ = rows;
    col_ = col;
    zombie_ = zombie;
    map_.resize(rows_);
    for (int i = 0; i < rows_; i++)
    {
        map_[i].resize(col_);
    }
}

//void AVZ::init(int numX, int numY)
//{
 //   char objects[] = {' ', ' ', ' ', ' ', ' ', 'r', '^', '>', '<', 'v', 'p', 'h', '1', '2'};
 //   int noOfObjects = 14;

  //  map_.resize(map_.size());
    //for(int i=0; i < map_.size(); ++i)
    //{/
      //  map_[i].resize(map_[i].size());
    //}

    // for (int i = 0; i < map_.size(); ++i)
    //{
      //  for (int j = 0; j < map_[i].size(); ++j)
        //{
          //  int objNo = rand() % noOfObjects;
            //map_[i][j] = objects[objNo];
        //}
    //}
//}

void AVZ::initArray() // initialize array with some values
{
    char characters[] = {' ', ' ', ' ', ' ', ' ', 'r', '^', '>', '<', 'v', 'p', 'h', '1', '2'};
    int noOfObjects = 14;

    for (int i = 0; i < map_.size(); i++)
    {
        for (int j = 0; j < col_; j++)
        {
            map_[i][j] = characters[rand() % 5];
        }
    }

     for (int i = 0; i < map_.size(); i++)
    {
        for (int j = 0; j < col_; j++)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = characters[objNo];
        }
    }
}

void AVZ::displayArray() const
{
    cout << "+=====================================+ " << endl; 
    cout << " ᕙ(`▿´)ᕗ+. Alien Vs Zombie .+ᕙ(`▿´)ᕗ " << endl;
    cout << "+=====================================+ " << endl; 
    // for each row
    for (int i = 0; i < map_.size(); ++i)
    {
        // display upper border of the row
        cout << " ";
        cout << " ";
        for (int j = 0; j < col_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setfill(' ') << (rows_ -i) << " ";
        // display cell content and border of each column
        for (int j = 0; j < col_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    cout << " ";
    for (int j = 0; j < col_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    cout << " ";
    for (int j = 0; j < col_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout  << digit;
    }
    cout << endl;
    cout << " ";
    cout << " ";
    for (int j = 0; j < col_; ++j)
    {
        cout << " " << (j + 1) % 10 ;
    }
    cout << endl
         << endl;
}

void AVZ::insertRandomCharacter(char ch)
{
    for (int i = 0; i < map_.size(); i++)
    {
        for (int j = 0; j < map_[i].size(); j++)
        {
            //if (rand() % 2 == 0)
            //{
               // map_[i][j] = ch;
            //}
        }
    }
}

void AVZ::displaySettings() const
{
    cout << "Board Rows   : " << rows_ << endl;
    cout << "Board Columns: " << col_ << endl;
    cout << "Zombie Count : " << zombie_ << endl;
}

void AVZ::setRows(int rows)
{
    rows_ = rows;
}

void AVZ::setCol(int col)
{
    col_ = col;
}

void AVZ::setZombie(int zombie)
{
    zombie_ = zombie;
}

int main()
{
    AVZ game; // create object of AVZ class with default number of rows and columns

    char characters[] = {' ', ' ', ' ', ' ', ' ', 'r', '^', '>', '<', 'v', 'p', 'h', '1', '2', 'A'};
    game.initArray();
    for (int i = 0; i < 14; i++)
    {
        game.insertRandomCharacter(characters[i]);
    }
    srand(time(NULL));
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    cout << "Default game setting:" << endl;
    cout << "---------------------" << endl;
    game.displaySettings();
    cout << " " << endl;
    cout << "Do you wish to change the game settings (y/n)?: ";
    char choice;
    cin >> choice;
    int rows_, col_, zombie_;
    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the number of rows: ";
        cin >> rows_;
        cout << "Enter the number of columns: ";
        cin >> col_;
        cout << "Enter number of zombies: ";
        cin >> zombie_;
        cout << "Press any key to continue... " << endl;
        //getch();
        game.setRows(rows_);
        game.setCol(col_);
        game.setZombie(zombie_);
        game = AVZ(rows_, col_, zombie_);
        game.initArray();
        for (int i = 0; i < 14; i++)
        {
            game.insertRandomCharacter(characters[i]);
        }
        game.displayArray();
    }
    else
    {
        cout << "Press any key to continue..." << endl;
        getch();
        game.initArray();
        for (int i = 0; i < 14; i++)
        {
            game.insertRandomCharacter(characters[i]);
        }
        game.displayArray();
    }
    return 0;
}