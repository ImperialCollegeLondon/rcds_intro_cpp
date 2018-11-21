// Chapter 8. Solving problems.
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>
#include <cmath>

// Function declarations:
// Generate a vector of random numbers.
std::vector<int> GenerateRandVec(int numOfnums, int min, int max);
// Bubble sort. Receive the reference to a vector, to change it directly.
void BubbleSort(std::vector<int>& theVec);
// Get factorials.
int Factorial(int numumber);
// Generate Fibonacci.
int Fibonacci(int index);
// Compute area of circles.
double Area(double radius);
// Compute area of rectangles.
double Area(double heigh, double width);

int main()
{
    std::cout << "Chapter 8\n";
    std::cout << "\n";
    
    // Problem 1. Bubble sort.
    std::cout << "Problem 1. Bubble Sort\n";
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    for(auto x: vecVals) std::cout << x << "\n";
    BubbleSort(vecVals);
    for(auto x: vecVals) std::cout << x << "\n";

    // Problem 2. Recursion and calculating factorials.
    std::cout << "\nProblem 2. Recursion & Factorials\n";
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;    
    std::cout << "Factorial " << num << " = " << Factorial(num) << "\n";

    // Problem 3. Fibonacci numbers.
    std::cout << "\nProblem 3. Recursion & Fibonacci numbers\n";
    int index;
    std::cout << "Enter a Fibonacci index: ";
    std::cin >> index; 
    printf("Fib(%d) = %d\n", index, Fibonacci(index));

    // Problem 4. Overloaded functions.
    // Functions with same function name and same return type, but different parameters.
    std::cout << "\nProblem 4. Overloaded functions\n";
    // Switch statement
    char areaType;
    std::cout << "Type c for circle, and r for rectanclge: ";
    std::cin >> areaType;
    switch(areaType)
    {
        case 'c': 
            std::cout << "Enter radius: ";
            double radius;
            std::cin >> radius;
            std::cout << "Area = " << Area(radius) << "\n";
            break;
        case 'r': 
            std::cout << "Enter height: ";
            double height;
            std::cin >> height;
            std::cout << "Enter width: ";
            double width;
            std::cin >> width;
            std::cout << "Area = " << Area(height, width) << "\n";
            break;
        default : std::cout << "Please enter c or r";
    }

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
    if(number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        int result = number*Factorial(number-1);
        return result;
    }
}

int Fibonacci(int index)
{
    int num1 = 1;
    int num2 = 1;
    int next;
    if(index < 2) return index;
    else return Fibonacci(index-1) + Fibonacci(index-1);
}

double Area(double radius)  
{
    std::cout << "ok";
    return 3.141592*pow(radius, 2);
}

double Area(double heigh, double width)
{
    return heigh*width;
}

