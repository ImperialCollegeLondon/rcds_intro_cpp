// Chapter 8. Solving problems.
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>

// Function declarations:
// Generate a vector of random numbers.
std::vector<int> GenerateRandVec(int numOfnums, int min, int max);
// Bubble sort. Receive the reference to a vector, to change it directly.
void BubbleSort(std::vector<int>& theVec);
// Get factorials.
int Factorial(int numumber);

int main()
{
    std::cout << "Chapter 8\n";
    std::cout << "\n";
    
    // Problem 1. Bubble sort.
    std::cout << "Problem 1. Bubble Sort\n";
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    BubbleSort(vecVals);
    for(auto x: vecVals)
    {
        std::cout << x << "\n";
    }

    // Problem 2. Recursion and calculating factorials.
    std::cout << "\nProblem 2. Recursion & Factorials\n";
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Factorial" << num << " = " << Factorial(num) << "\n";

    return 0;
}

std::vector<int> GenerateRandVec(int numOfnums, int min, int max)
{
    std::vector<int> vecValues;
    srand(time(NULL));
    int i = 0;
    int randVal = 0;
    while(i < numOfnums)
    {
        // When we do modulus %, the remainder can't be greater than the divisor
        randVal = min + std::rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}

void BubbleSort(std::vector<int>& theVec)
{
    // Have the largest number at the end of the list.
    int i = theVec.size()-1;
    // Continue cycling while i >= 1.
    while(i >= 1)
    {
        int j = 0;
        // Start comparing indices. The largest number is bubbled up to the end.
        while(j < i)
        {
            printf("\nIs %d > %d\n", theVec[j], theVec[j+1]);
            if(theVec[j] >= theVec[j+1])
            {
                std::cout << "Switch\n";
                int temp = theVec[j];
                theVec[j] = theVec[j+1];
                theVec[j+1] = temp;
            }
            else
            {
                std::cout << "Don't switch\n";
            }
            j+=1;
            for(auto k: theVec)
            {
                std::cout << k << ", ";
            }
        }
        std::cout << "\nEnd of round\n";
        i-=1;
    } 
}

int Factorial(int number)
{
    if(number == 1)
    {
        return 1;
    }
    else
    {
        int result = number*Factorial(number-1);
        return result;
    }
}


