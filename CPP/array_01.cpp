#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int GenerateRandomNumber(int min, int max)
{
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}



int main()
{
    // initialize an array size and array
    int arrSize = 5;
    int arrRandom[arrSize];

    // Set Random Seed
    srand(static_cast<unsigned int>(time(0)));

    // Add random Elements into the array
    for(int i = 0; i < arrSize; i++){
        arrRandom[i] = GenerateRandomNumber(1,100);
    } 

    cout << "Array elements: ";
    for(int i = 0; i < arrSize; i++){
        cout << arrRandom[i] << " ";
    }
    cout << endl;

    // Manipulate several elements
    arrRandom[2] = 30;
    arrRandom[3] = 64;

    // Access each element again
    cout << "Array elements: ";
    // If didn't intialize the size, we use sizeof(arr)/sizeof(*arr) to find array size
    for(int i = 0; i < arrSize; ++i)
        cout << arrRandom[i] << " ";
    cout << endl;

    return 0;
}