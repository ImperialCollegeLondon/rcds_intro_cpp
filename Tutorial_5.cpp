// Chapter 5. Strings & Math (Incomplete).
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>

// Function declarations.

int main()
{
    std::cout << "Chapter 5\n";
    std::cout << "\n";

    // c character String = array of characters with a no caracter \0 at the end
    char cString[] = {'A', ' ', 'S','t','r','i','n','g','\0'};

    std::cout << "Array size = " << sizeof(cString) << "\n";

    // cStrings trouble -> the program can crashh. cpp std strings ara okkkk, they can grow in size
    std::vector<std::string> strVec(10);

    std::string str("I'm a string");
    strVec[0] = str;

    std::cout << strVec[0] << "\n";
    std::cout << str.front() << " " << str.back() << "\n";
    std::cout << "Length = " << str.length() << "\n";

    std::string str2(str);
    strVec[1] = str2;

    std::string str3(str, 4);
    strVec[2] = str3;

    std::string str4(5, 'x');
    strVec[3] = str4;

    strVec[4] = str.append(" and you are not");

    // Problem 1. Find a string and change some characters
    std::cout << "\nFind a string and change some characters\n";
    for(auto x: strVec) 
        std::cout << x << "\n";

    // Find function. npos will be returned if the condition does not match.
    if(str.find("string") != std::string::npos)
        std::cout << "1st not " << str.find("string") << "\n";
    
    // Get the ascii code for each character
    // a-z : 97 - 122
    // A-Z : 65 - 90
    char aChar = 'A';
    int aInt = aChar;
    std::cout << "A code: " << (int)'a' << "\n";

    // Problem.
    // Receive upper case strings. Hyde the meaning by turn them into their ascii code
    // a-z : 97 - 122
    // A-Z : 65 - 90
    std::cout << "Problem 1\n";
    std::string normalStr;
    std::string secretStr = "";
    std::cout << "Enter your string in capital letters: ";
    std::cin >> normalStr;

    for(char c: normalStr)
        secretStr += std::to_string((int)c);
    
    std::cout << "Secret: " << secretStr << "\n";

    // Cononvert it back
    normalStr = "";
    // each caracter represented by 2 digits 
    for(int i = 0; i < secretStr.length(); i += 2)
    {
        std::string sCharCode = "";
        sCharCode += secretStr[i];
        sCharCode += secretStr[i+1];

        // string that I grab to an integer
        int nCharCode = std::stoi(sCharCode);
        char chCharCode = nCharCode;
        normalStr += chCharCode;
    }

    std::cout << "Original: " << normalStr << "\n";

    return 0;
}