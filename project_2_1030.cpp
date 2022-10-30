#include <iostream>
#include <ctime>
using namespace std;
 
const int ROW = 10;
const int COL = 10;
 
//email format function
bool isWrongFormat(string email)
{
    bool boolean = true;
    int atCount= 0;
    int periodCount = 0;
    int emailLeng = email.length();
    int periodIndex;
    int atIndex;
    for( int i= 0; i < emailLeng-1; ++i)
    {
       
            if(email.at(i) == '@')
            {
                atCount +=1;
                atIndex = i;
            }
            if(email.at(i)== '.')
            {
                periodCount+=1;
                periodIndex = i;
            }
       
    }
 
    if(periodIndex > atIndex && atCount == 1 && periodCount ==1)
    {
        boolean = false;
    }
    else
    {
        boolean = true;
    }
    //if the bool is false, it is right format
    //if bool is true, it is wrong format
    return boolean;
}
 
//array display function
void display(int array[][COL], int userRow, int userCol)
{
    for(int i = 0; i < userRow; ++i)
    {
        for(int j = 0; j < userCol; ++j)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}
 
//array initializing function
void initialize(int (&dispArray)[][COL], int (&numArray)[][COL],int num = -1)
{
    srand(time(NULL));
    if(num == -1)
    {
        for(int i = 0; i < ROW; ++i)
        {
            for(int j = 0; j < COL; ++j)
            {
                dispArray[i][j] = -1;
            }
        }
    }
    if(num!=-1)
    {
 
        for(int i = 0; i < ROW; ++i)
        {
            for(int j = 0; j < COL; ++j)
            {
                numArray[i][j] = rand() % 20 +1;
            }
        }
    }
}
 
//move repeat function
bool checkRepeat(int array[][2], int xMove, int yMove, int x)
{
 
    for(int i = 0; i < x; ++i)
    {
        if(xMove == array[i][0] && yMove == array[i][1])
        {
            return true;
        }
    }
    return false;
   
}
int main()
{
    int dispArray[ROW][COL];
    int numArray[ROW][COL];
 
    int userRow;
    int userCol;
    bool arrayDimensionBool;
   
   
        cout << "Enter the number of rows:";
        cin >> userRow;
        cout << "Enter the number of columns:";
        cin >> userCol;
   
        cout << endl;
 
//user input dimensions of matrix
   do{
        if((userRow > 10 || userRow < 1) || (userCol > 10 || userCol < 1))
        {
            cout << "Wrong dimensions try again." << endl;
 
            cout << "Enter the number of rows:";
            cin >> userRow;
            cout << "Enter the number of columns:";
            cin >> userCol;
            cout << endl;
 
            arrayDimensionBool = true;
        }
        else
        {
            arrayDimensionBool = false;
        }
   }
   while(arrayDimensionBool);
 
    string email;
 
    //checking if valid email
    bool invalidEmail;
    int emailLeng = email.length();
   
    do
    {
        cout<< "Enter your email:";
        cin.ignore();
        getline(cin, email);
 
        invalidEmail = isWrongFormat(email);
    }while(invalidEmail);
 
    initialize(dispArray, numArray); //initializing dispArray
    initialize(dispArray, numArray, 0); //initialzing numArray
   
   display(dispArray,userRow,userCol);
   
    int x;
    int y;
    int points = 10;
    bool doAgainBool;
 
    //start of the game - do while loop with user made bool condition
    do
    {
        cout << "Enter x coordinate:" << endl;
        cin >> x;
        cout << "Enter y coordinate:" << endl;
        cin >> y;
        int movesArray[10][2];
        int moveArrayCount = 0;
        //need a count that iterates for k, INCREMENT AT THE END
        movesArray[moveArrayCount][0] = x;
        movesArray[moveArrayCount][1] = y;
        moveArrayCount+=1;
        dispArray[x][y] = numArray[x][y];
        display(dispArray, userRow, userCol);
 
        int xMatch;
        int yMatch;
        bool sameMove;
        do
        {
        cout << "Enter a coordinate to match." << endl;
        cout << "X coordinate:" << endl;
        cin >> xMatch;
        cout << "Y coordinate:" << endl;
        cin >> yMatch;
 
        sameMove = checkRepeat(movesArray, xMatch, yMatch, moveArrayCount);
        if(sameMove)
        {
            cout<< "Try again." << endl;
        }
 
        }while(sameMove);
 
        dispArray[xMatch][yMatch] = numArray[xMatch][yMatch];
        display(dispArray, userRow, userCol);
        if(dispArray[x][y] == dispArray[xMatch][yMatch])
        {
            cout << "You found a match!" << endl;
            points+=2;
            cout << "Points:" << points << endl;
        }
        if (dispArray[x][y] != dispArray[xMatch][yMatch])
        {
            cout << "No match found" << endl;
            points-=1;
            cout << "Points:" << points << endl;
        }
 
        char doAgainChar;
        cout << "Do you want to try again?(y/n)";
        cin >> doAgainChar;
 
        if(tolower(doAgainChar) == 'y')
        {
            doAgainBool = true;
        }
        else
        {
            doAgainBool = false;
        }
        //changing the arrays for the next round
        initialize(dispArray, numArray); //initializing dispArray
        initialize(dispArray, numArray, 0); //initialzing numArray
        display(dispArray, userRow, userCol);
        if(points == 0)
        {
            break;
        }
    }while(doAgainBool);
// end of do while loop
cout << "Results will be emailed to " << email << "." << endl;
cout << "Goodbye!!!";
}
