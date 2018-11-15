// Chapter 1. Variable types and input by user.
// Pre-processing directives. 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

// When we create a variable, we are telling the computer how much memory to set aside.
// Global variables, that can be accessed from anywhere, vs constant values.
int g_iRandNum = 0;
const double PI = 3.14159;

int main()
{
    std::cout << "Chapter 1\n";
    std::cout << "\n";

    std::cout << "1. Variable types in cpp.\n";
    // 1. Variable types in cpp.
    bool bMarried = true;
    char chMyGrade = 'A';
    unsigned short int u16age = 43;
    short int siWeight = 180;
    int nDays = 7;
    long lbigNum = 1100000;
    float fPi = 3.15159;
    double dbBigFloat = 1.11111111111;
    long double ldPi = 3.14159;
    auto whatWillBe = true;

    // Check the limits of my variables.
    std::cout << "Min bool " << std::numeric_limits<bool>::min() << "\n";
    std::cout << "Max bool " << std::numeric_limits<bool>::max() << "\n";
    
    // Check the number of bytes.
    std::cout << "int size: " << sizeof(int) << " bytes\n";
    std::cout << "double size: " << sizeof(double) << " bytes\n";
    std::cout << "float size: " << sizeof(float) << " bytes\n";

    // Precision.
    double fBigFloat1 = 1.11111111111111111;     
    double fBigFloat2 = 1.11111111111111111;
    float fFloatSum = fBigFloat1 + fBigFloat2;
    printf("FloatSum precision: %.5f\n", fFloatSum);
    printf("FloatSum precision: %.10f\n", fFloatSum);

    // Using printf.
    printf("%c, %d, %5d, %.3f, %s\n", 'A', 10, 5, 3.1234, "Hi\n");

    // 2. Receiving input from the user.
    std::cout << "2. Receiving input from the user.\n";
    std::string sQuestion1 ("Enter number 1: ");
    std::string sQuestion2 ("Enter number 2: ");
    std::string sNum1, sNum2;
    std::cout << sQuestion1;
    getline(std::cin, sNum1);
    std::cout << sQuestion2;
    getline(std::cin, sNum2);

    int nNum1 = std::stoi(sNum1);
    int nNum2 = std::stoi(sNum2);

    printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
    printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
    printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
    printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
    std::cout << "\n";

    // 3. Test. Convert miles to kilometers.
    std::string sQuestion3 ("Enter a distance in miles: ");
    std::string sNum3;
    std::cout << sQuestion3;
    getline(std::cin, sNum3);

    double nNum3 = std::stod(sNum3);

    printf("%.2f miles = %.2f km", nNum3, (nNum3 * 1.60934));
    std::cout << "\n";

    return 0;
};