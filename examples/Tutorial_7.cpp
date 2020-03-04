// Chapter 7. Solving problems.
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>

// Function declarations:
// Cipher function.
std::string CaesarCipher(std::string theString, int key, bool encrypt);
// Receive an equation and solve it for x.
void SolveForX(std::string equation);
// String to vector.
std::vector<std::string> StringToVector(std::string MyString, char separator);
// Check if a number is prime.
bool IsPrime(int num);
// Generate a list of primes.
std::vector<int> GeneratePrimes(int maxNum);
// Range function.
std::vector<int> Range(int start, int max, int step);
// Generate a vector of random numbers.
std::vector<int> GenerateRandVec(int numOfnums, int min, int max);

int main()
{
    std::cout << "Chapter 7\n";
    std::cout << "\n";
    
    // Problem 1. Create a string and encrypt it.
    std::cout << "Problem 1. Encrypting & Decrypting strings\n";
    std::string theString = "Make me secret";
    std::string encryptedStr = CaesarCipher(theString, 5, true); // A->F
    std::string decryptedStr = CaesarCipher(encryptedStr, 5, false);
    std::cout << "Encrypted: " << encryptedStr << "\n";
    std::cout << "Decrypted: " << decryptedStr << "\n";
    std::cout << "\n";
    
    /* Incomplete. Segmentation fault (core dumped)
    // Problem 2. Solve a first order equation.
    std::cout << "Problem 2. Solving equations\n";
    std::cout << "Enter an equation to solve: ";
    std::string equation = "";
    std::cin >> equation;
    // geline(std::cin, equation);
    SolveForX(equation);
    std::cout << "\n";*/

    // Problem 3. Provide a list of primes. enter a value ans check
    std::cout << "Problem 3. Play with primes\n";
    int num = 0;
    std::cout << "Enter a number to check: ";
    std::cin >> num;
    // Write the boolean as true/false insted 0/1
    std::cout.setf(std::ios::boolalpha);
    if(IsPrime(num) == true)
        std::cout << num << " is prime\n";
    else
        std::cout << num << " is not prime\n";
    std::cout << "Generate Primes up to ";
    int maxPrime;
    std::cin >> maxPrime;
    std::vector<int> primeList = GeneratePrimes(maxPrime);
    for (auto x: primeList)
        {
            std::cout << x << "\n";
        }
    std::cout << "\n";

    // Problem 4. Generate a random vector.
    std::cout << "Problem 4. Play with randoms\n";
    int numRands;
    int minRand;
    int maxRand;
    std::cout << "Enter the number of randoms to create: ";
    std::cin >> numRands;
    std::cout << "Enter the minimum value: ";
    std::cin >> minRand;
    std::cout << "Enter the maximum value: ";
    std::cin >> maxRand;
    std::vector<int> vecVals = GenerateRandVec(numRands, minRand, maxRand);
    for (auto x: vecVals)
        std::cout << x << "\n";

    return 0;
}

// Function definitions:
std::string CaesarCipher(std::string theString, int key, bool encrypt)
{
    std::string returnString = "";
    int charCode = 0;
    char letter;
    // Change the direction of the key for encrypt/decript.
    if(encrypt) key = key * -1; 
    for(char& c:theString)
    {
        // Check if it is a letter (alphanumeric), and change it only if it is a letter.
        if(isalpha(c))
        {
            // Convert the charactar to integer, and increase it based on the key.
            // Actually, we don't convert. Just say to read the binary code as an int or as a letter.
            charCode = (int) c; 
            charCode += key;
            // It is upper case character. Check if the new charCode is greater than the upper case letter Z.
            // If it is, shift back to the beggining, to avoid ASCII characters that are not letter.
            if(isupper(c))
            {
                if(charCode > (int) 'Z')
                {
                    // Back to the beggining to my upper case letters.
                    charCode -= 26;
                }
                else if(charCode < (int) 'A')
                {
                    charCode += 26;
                }
            } 
            else
            {
                if(charCode > (int)'z')
                {
                    charCode -= 26; // Back to the beggining to my upper case letters.
                }
                else if(charCode < (int)'a')
                {
                    charCode += 26;
                }
            }
            // Now, fom integers to characters.
            letter = charCode;
            // Add it to the end of my returned string.
            returnString += letter;
        }
        // If it is not alphanumeric
        else
        {      
            letter = c;
            returnString += c;
        }
    }
    return returnString;
}

// Format: x + 4 = 9
void SolveForX(std::string equation)
{
    std::vector<std::string> vecEquation = StringToVector(equation, ' ');
    // Convert my strings to integers.
    int num1 = std::stoi(vecEquation[2]);
    int num2 = std::stoi(vecEquation[4]);
    int xVal = num1 + num2;
    std::cout << "x =   " << xVal << "\n";
}

std::vector<std::string> StringToVector(std::string MyString, char separator)
{
    std::vector<std::string> vecWords;
    std::stringstream ss(MyString);
    std::string sIndivStr;
    while(getline(ss, sIndivStr, separator))
    {
        vecWords.push_back(sIndivStr);
    }
    return vecWords;
}

bool IsPrime(int num)
{
    for (auto n: Range(2, num-1, 1))
    {
        if((num % n) == 0)
            return false;
    }
    return true;
}

std::vector<int> GeneratePrimes(int maxNum)
{
    std::vector<int> vecPrimes;
    for (auto x: Range(2, maxNum, 1))
    {
        if(IsPrime(x))
            vecPrimes.push_back(x);
    }
    return vecPrimes;
}

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

