// Chapter 9. Lambda expressions. Perform list operatons.
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>
#include <cmath>
#include <algorithm>

// Function declarations:
// Generate a vector of random numbers.
std::vector<int> GenerateRandVec(int numOfnums, int min, int max);

int main()
{
    std::cout << "Chapter 9\n";
    std::cout << "\n";

    // Problem 1. Bubble sort a vector.
    std::cout << "Problem 1. Sort function\n";
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    std::cout << "Vector before sorted\n";
    for(auto x: vecVals) std::cout << x << "\n";
    // [] designates the beggining of a lambda expression. Anonymous function, without a name.
    // [] receives parameters inside (), and performs and operation inside {}.
    std::sort(vecVals.begin(), vecVals.end(), [](int x, int y){return x<y;});
    std::cout << "Vector after sorted\n";
    for(auto x: vecVals) std::cout << x << "\n";

    // Problem 2. copy_if function. Equivalent to Filter() of python.
    // Generate a vector and delete some values, to store in another vector.
    std::cout << "\nProblem 2. copy_if function\n";
    std::vector<int> evenVecVals;
    // Return and copy into evenVecVals only if the condition inside {} of the lambda expression is fulfilled.
    std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(evenVecVals),
        [](int x){return(x % 2) == 0;});
    std::cout << "Even numbers only\n";
    for(auto x: evenVecVals) std::cout << x << "\n";

    // Problem 3. for_each function. Sum the elements of a vector.
    std::cout << "\nProblem 3. for_each function\n";
    int sum = 0;
    // Capture all the variables used in the body of our lambda expression by reference.
    std::for_each(vecVals.begin(), vecVals.end(), [&](int x){sum += x;});
    std::cout << "Sum " << sum << "\n";
    
    // Problem 4. Create a dynamic list, divisible by a value.
    std::cout << "\nProblem 4. Create a dynamic list\n";
    int divisor;
    std::vector<int> vecVals2;
    std::cout << "List of values divisible by: ";
    std::cin >> divisor;
    // Same as in the copy_if. Jus type divisor inside the capture list.
    std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(vecVals2),
        [divisor](int x){return(x % divisor) == 0;});
    for(auto x: vecVals2) std::cout << x << "\n";

    // Problem 5. Add and store values of different vector to another vector.
    std::cout << "\nProblem 5. Playing with vectors\n";
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> vec3(5);
    // Take vec1 and vec2. Store everything in vec3.
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), 
        [](int x, int y){return(x+y);});
    for(auto x: vec3) std::cout << x << "\n";

    return 0;
}

// Function definitions:
std::vector<int> GenerateRandVec(int numOfnums, int min, int max)
{
    std::vector<int> vecValues;
    srand(time(NULL));
    int i = 0;
    int randVal = 0;
    while(i < numOfnums)
    {
        // When we do modulus %, the remainder can't be greater than the divisor.
        randVal = min + std::rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}