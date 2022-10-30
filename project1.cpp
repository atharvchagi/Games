
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cmath>
using namespace std;

int main()
{

  int length;

  // list of shapes
  enum Shapes
  {
    Rectangle = 1,
    Triangle = 2,
    Pentagon = 3,
    // Sentence = 4,
    Quit = 4
  };
  Shapes myShape;
  char doAgain;
  // random ascii
  srand(time(NULL));

  do
  {
    cout << "Enter a length:\n";
    cin >> length;
    if (length % 2 == 0)
    {
      cout << "You must enter an odd number." << endl;
    }
  } while (length % 2 == 0);

  do
  {

    int asciiNum = rand() % 34 + 31;
    char asciiChar;
    string sentence;

    // inital user input
    int shapeInput;
    cout << "Which shape do you want to generate?:" << endl;
    cout << "1.Rectangle\n"
         << "2.Triangle\n"
         << "3.Pentagon\n"
         << "4.Quit\n";
    cin >> shapeInput;

    myShape = static_cast<Shapes>(shapeInput);
    asciiChar = asciiNum;
    // switch case for user input
    system("cls");
    switch (myShape)
    {
    case Rectangle:
      // generate shape
      for (int k = 1; k <= length; ++k)
      {

        for (int i = 1; i <= k; ++i)
        {

          for (int j = 0; j < k; ++j)
          {
            cout << asciiChar;
          }
          cout << endl;
        }
        sleep(1);
        if (k == length)
        {
          break;
        }
        system("cls");
      }

      break;

    case Triangle:
      for (int i = 1; i <= length; ++i)
      {
        for (int j = i; j < length; ++j)
        {
          cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; ++k)
        {
          cout << asciiChar;
        }
        cout << endl;
        sleep(1);
      }
      break;

    case Pentagon:
      for (int i = 1; i <= length; ++i)
      {
        for (int j = i; j < length; ++j)
        {

          cout << " ";
        }

        for (int j = 1; j <= (2 * i - 1); ++j)
        {
          cout << asciiChar;
        }
        cout << endl;
        sleep(1);
      }
      for (int i = 0; i < length - 1; ++i)
      {
        for (int j = 0; j < 2 * length - 1; ++j)
        {

          cout << asciiChar;
        }
        cout << endl;
        sleep(1);
      }

      break;

      // case Sentence:
      //   cout << "Enter a sentence:";
      //   cin.ignore();
      //   getline(cin, sentence);
      //   for (int i = 0; i < sentence.length(); ++i)
      //   {

      //     int count = 0;
      //     for (int i = 0; i < sentence.length(); ++i)
      //     {

      //       if (isdigit(sentence.at(i)))
      //       {
      //         ++count;
      //       }
      //     }
      //     for (int j = 0; j < count; ++j)
      //     {
      //       for (int t = 0; t < j; ++t)
      //       {
      //         cout << endl;
      //       }
      //       for (int k = 0; k < sentence.length(); ++k)
      //       {

      //         if (isdigit(sentence.at(k)))
      //         {
      //           sentence.erase(k, 1);
      //           break;
      //         }
      //       }
      //       cout << sentence;

      //       sleep(1);
      //       system("clear");
      //     }
      //   }
      //   break;

    case Quit:
      cout << "Goodbye." << endl;
      exit(0);
      break;

    default:
      cout << "Wrong Choice." << endl;
      break;
    }
    cout << "Do you want to repeat Y/N?";
    cin >> doAgain;
  } while (toupper(doAgain) == 'Y');
}