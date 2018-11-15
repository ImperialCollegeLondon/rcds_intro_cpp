// Chapter 2. C++ tutorial.

// Pre-processes directives. 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main()
{
    // 1. Conditionals. Receive string, convere to int, use if, else, etc.
    std::cout << "1. Conditionals.\n";
    std::string sAge;
    std::cout << "Enter your age: ";
    getline(std::cin, sAge);
    int nAge = std::stoi(sAge);

    // Combine conditional and logical operators.
    if((nAge >= 1) && (nAge <= 18))
    {
        std::cout << "Important Birthday\n";
    }
    else if ((nAge == 21) || (nAge == 50))
    {
        std::cout << "Special Birthday\n";
    }
    else if (nAge >= 65)
    {
        "Not an important Birthday\n";
    }

    // Test. age 5 -> go to kindergarden. 6 through 17 -> 1 through 12. greater to 17, go to college
    std::string sAge2;
    std::cout << "Enter your age: ";
    getline(std::cin, sAge2);
    int nAge2 = std::stoi(sAge2);
    
    if (nAge < 5)
    {
        "To young for school\n";
    }
    else if (nAge == 5)
    {
        "Go to kindergarden\n";
    }
    else if ((nAge > 5) && (nAge <= 17))
    {
        std::cout << "Go to grade " << nAge-5 << "\n";
    }
    else
    {
        std::cout << "Go to college\n";
    }

    // 2. Arrays.
    std::cout << "\n1. Arrays.\n";
    int arrNums[10] = {1};
    int arrNums2[] = {1,2,3};
    int arrNums3[5] = {8,9};
    std::cout << "1st value: " << arrNums3[0] << "\n";
    arrNums3[0] = 7;
    std::cout << "1st value: " << arrNums3[0] << "\n";
    // How many bytes are we working with. Data at this memory adree (*)
    std::cout << "Array size: " << sizeof(arrNums3) / sizeof(*arrNums3) << "\n";
    // Multidim arrays. pages set aside, colums, rows.
    int arrNums4[2][2][2] = {{{1,2}, {3,4}},
                            {{5,6}, {7,8}}};
    std::cout << arrNums4[1][1][1] << "\n";
    
    // 2. Vectors. Re-sizeable.
    std::cout << "\n1. Vectors.\n";    
    std::vector<int> vecRandNums(2);
    vecRandNums[0] = 10;
    vecRandNums[1] = 20;
    vecRandNums.push_back(30);
    std::cout << "Last index: " << vecRandNums[vecRandNums.size()-1] << "\n";
    // convert string to vectr
    std::string sSentence = "This is a random string";
    std::vector<std::string> vecWords;
    // stringstream. object who receives strings and allows to manipulate.
    std::stringstream ss(sSentence);
    std::string sIndivStr;
    char cSpace = ' ';

    // While ss has words to spit out, and throw in sIndivStr, while cspace spare.
    while(getline(ss, sIndivStr, cSpace))
    {
        vecWords.push_back(sIndivStr);
    }
    for(int i=0; i<vecWords.size(); i++)
    {
        std::cout << vecWords[i] << "\n";
    }

    // 3. Test. Calculator.
    std::cout << "\n1. Calculator.\n";
    double Num1, Num2;
    std::string sOperation;
    std::vector<std::string> vecOp;

    std::cout << "Enter operation (e.g. 2+3):";
    getline(std::cin, sOperation);
    std::stringstream ss2(sOperation);
    std::string sIndivStr2;
    char cSpace2 = ' ';
    
    while(getline(ss2, sIndivStr2, cSpace2))
    {
        vecOp.push_back(sIndivStr2);
    }

    Num1 = std::stoi(vecOp[0]);
    Num2 = std::stoi(vecOp[2]);
    std::string operation = vecOp[1];

    if (operation == "+")
    {
        printf("%.1f + %.1f = %.1f\n", Num1, Num2, (Num1 + Num2));
    }
    else if (operation == "-")
    {
        printf("%.1f - %.1f = %.1f\n", Num1, Num2, (Num1 - Num2));
    }
    else
    {
        std::cout << "Please insert only operations +, -, *, /\n";
    }

    return 0;
}