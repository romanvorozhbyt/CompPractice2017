#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void) {
    int maxball, ballsno;
    cout << "Max ball number? ";
    cin >> maxball;
    cout << "How many balls? ";
    cin >> ballsno;
    srand(time(NULL));
    int *array = new int[ballsno];
    int val;
    bool diff = false;
    for(int i = 0; i < ballsno; i++)
    {
        do
        {
            val = rand() % maxball + 1;
            for(int j = 0; j < i; j++)
            {
                if(array[j] == val)
                {
                    diff = true;
                    break;
                }
                diff = false;
            }
        }while(diff);
        array[i] = val;
    }
    for(int i = 0; i < ballsno; i++)
        cout << array[i] << "   ";
    delete [] array;
    return 0;
    }
