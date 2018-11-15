// Chapter 6. Solving problems.
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>

// Function declarations.
// String to vector
std::vector<std::string> StringToVector(std::string MyString, char separator);
// Vector to string
std::string VectorToString(std::vector<std::string>& MyVector, char separator2);
// Handle spaces
std::string TrimWhiteSpace(std::string);
// Store matches in a vector
std::vector<int> FindSubstringMatches(std::string MyString, std::string substring);
// Replace
std::string ReplaceSubstrings(std::string MyString, std::string substring, std::string newString);


int main()
{
    std::vector<std::string> vec1 = StringToVector("This is a random string", ' ');
    for(int i=0; i<vec1.size(); i++)
    {
        std::cout << vec1[i] << "\n";
    }   

    // Problem 2. Customers
    std::vector<std::string> vCusts(3);
    vCusts[0] = "Bob";
    vCusts[1] = "Sue";
    vCusts[2] = "Tom";
    std::string sCusts = VectorToString(vCusts, ' ');
    std::cout << sCusts << "\n";

    // Problem 3. Get rid of space
    std::string aStr = "Just some random words    ";
    aStr = TrimWhiteSpace(aStr);
    std::cout << "*" << aStr << "*\n";

    // Problem 4. Index that match and store in a vector
    std::string phrase = "To be or not to be";
    std::vector<int> matches = FindSubstringMatches(phrase, "be");
    for(int i=0; i< matches.size(); i++)
    {
        std::cout << matches[i] << "\n";
    }

    // Problem 5. replace all substrings.
    std::cout << ReplaceSubstrings("To know or not to know", "know", "be") << "\n";

    return 0;
}

// Function definitions
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

std::string VectorToString(std::vector<std::string>& myVector, char separator2)
{
    std::string myString = "";
    for(int i=0; i<myVector.size(); i++)
    {
        myString += myVector[i] + separator2; 
    }
 
    return myString;
}

std::string TrimWhiteSpace(std::string myString)
{
    //Define the white spaces i want to fet rid of
    std::string whitespaces(" \t\f\n\r");
    myString.erase(myString.find_last_not_of(whitespaces) + 1); // find the last instance that is one of those
    myString.erase(0, myString.find_first_not_of(whitespaces));

    return myString;
}

std::vector<int> FindSubstringMatches(std::string MyString, std::string substring)
{
    std::vector<int> matchingIndexes;
    int index = MyString.find(substring, 0);
    while(index != std::string::npos)
    {
        matchingIndexes.push_back(index);
        index = MyString.find(substring, index+1);
    }
    return matchingIndexes;
}

std::string ReplaceSubstrings(std::string MyString, std::string substring, std::string newString)
{
    std::vector<int> matches = FindSubstringMatches(MyString, substring);
    // If i have a match
    if(matches.size() != 0)
    {
        int lengthDifference = newString.size() - substring.size();
        int timesLooped = 0;
        for(int i=0; i<matches.size(); i++)
        {
            MyString.replace(matches[i] + (timesLooped * lengthDifference), substring.size(), newString);
            timesLooped++;
        }
    }

    return MyString;
}



