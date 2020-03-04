// Chapter 4. Exception handling and looping.
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>

// Function declarations.
// Range function.
std::vector<int> Range(int start, int max, int step);

int main()
{
    std::cout << "Chapter 4\n";
    std::cout << "\n";

    // 1. Check if a number is even and skip it.
    std::cout << "1. Check if a number is even and skip it.\n";
    int i = 1;
    while(i <= 20)
    {
        if((i % 2) == 0)
        {
            i += 1;
            continue;
        }
        if(i == 15) break;
        std::cout << i << "\n"; 
        i += 1;
    }
    std::cout << "\n";

    // 2. Pine trees, how many rows.
    // How tall is a tree : 5
    /*
    #
   ###
  #####
 #######
    #
    */
    // 1. Decrement spaces by 1 each time through the loop
    // 2. Increment the hashes by 2 each time 
    // 3. Save spaces to the stump by tree height -1
    // 4. Decrement from tree height until equals 0
    // 5. Print spaces and then hashes for each row.
    // 6. Print stamp spaces and then 1 hash.
    std::cout << "Problem 1\n";
    std::cout << "How tall is the tree: ";
    int treeHeight = 0; 
    int spaces = 0; 
    int hashes = 1; 
    int stumpSpaces = 0;
    // Store the value given by the user.
    std::cin >> treeHeight;
    spaces = treeHeight-1;
    stumpSpaces = treeHeight - 1;
    while(treeHeight != 0)
    {
        for(auto x: Range(1, spaces, 1))
            std::cout << " ";
        for(auto x: Range(1, hashes, 1))
            std::cout << "#";

        std::cout << "\n";
        spaces -= 1;
        hashes += 2;
        treeHeight -= 1;
    }

    for(auto x: Range(1, stumpSpaces, 1))
        std::cout << " ";
    
    std::cout << "#\n";

    // Problem 2. Exceptions.
    std::cout << "Problem 2\n";

    double num1 = 0;
    double num2 = 0;

    std::cout << "Enter number 1: ";
    std:: cin >> num1;
    std::cout << "Enter number 2: ";
    std:: cin >> num2;

    try
    {
        if(num2 == 0)
        {
            throw "Division by 0 not possible.\n";
        }
        else
        {
            printf("%.1f / %.1f = %.1f\n", num1, num2, (num1/num2));
        }
    }
    // Catch/solve/handle the error
    catch(const char *exp)
    {
        std::cout << "Error: " << exp << "\n";
    }
    std::cout << "\n";

    // Problem 3. Do while loops. At least 1.
    std::cout << "Problem 3\n";
    srand(time(NULL));
    // create our secret number (from 0 to 10)
    int secretNum = std::rand() % 11; // impossible to get a remainder greater than 11
    int guess = 0;

    do
    {
        std::cout << "Guess the number : ";
        std::cin >> guess;
        if(guess > secretNum) std::cout << "Too big\n";
        if(guess < secretNum) std::cout << "Too small\n";
    } while(secretNum != guess);

    std::cout << "You guessed it!\n";

    /*// Problem 5. While & do while loops.
    std::cout << "Problem 2\n";
    //Infinite loop
    while(true)
    {
        (...)
        if(secretNum == guess) break;
    }
    */
    return 0;

}

// Function definitions.
std::vector<int> Range(int start, int max, int step)
{
    int i = start;
    std::vector<int> range;
    while(i <= max)
    {
        range.push_back(i);
        i += step;
    }
    return range;
}