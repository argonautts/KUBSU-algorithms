#include <iostream>
#include <ctime>
using namespace std;

void main()
{
    setlocale(LC_ALL,"Ru");
    srand(time(0));
    int counter = 0; 
    cout << "n" << "  " << "counter" << "     " << "T(n)" << endl;
    cout << "-------------------------------------------" << endl;
    for (int n = 2; n <= 30; n++) {

        int** FirstArray; FirstArray = new int* [n];
        int** SecondArray; SecondArray = new int* [n];
        int** ThirdArray; ThirdArray = new int* [n];
        for (int i = 0; i < n; i++)          
        {
            FirstArray[i] = new int[n];
            SecondArray[i] = new int[n];
            ThirdArray[i] = new int[n];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                FirstArray[i][j] = rand() % 15 + 3;
                SecondArray[i][j] = rand() % 15 + 3;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ThirdArray[i][j] = FirstArray[i][j] * SecondArray[j][i];
                counter += n + (n - 1);
            }
        }
        cout << n << "  ";
        cout << counter << "     ";
        cout<< "T(" << n << ")=" << "k(3)*" << n * n * n << "*k(2)*" << n * n << "*k(1)" << endl;
        counter = 0;
    }
    system("pause>nul");
}
