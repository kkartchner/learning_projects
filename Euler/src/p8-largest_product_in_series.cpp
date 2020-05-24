#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

int main ()
{
    std::vector<int> digits;
    char curDigit = -1;

    std::ifstream numFile("res/p9-number.txt");
    if (numFile.is_open()){
        while (numFile >> curDigit){
            if (isdigit(curDigit)){
                digits.push_back(curDigit - '0');
            }    
        }
    } else {
        std::cout << "\"res/p9-number.txt\" failed to open. Does it exist?" << std::endl;
    }
    numFile.close();

    unsigned long largestProduct = 0;
    int startOfLargest = 0;

    for (int curDigit = 0; curDigit < 1000; ++curDigit){
        unsigned long product = 1;
        for (int i = curDigit; i < curDigit + 13; ++i){
            std::cout << i << " "  << digits[i] << " ";
            product *= digits[i];
            std::cout << product << std::endl;
            if (product == 0){
                curDigit = i;
                break;
            }
        }
        if (product > largestProduct){
            largestProduct = product;
            startOfLargest = curDigit;
        }
        std::cout << std::endl;
    }
    
    std::cout << "Largest product of 13 consecutive digits in the loaded number is: " << std::endl;
    for (int i = startOfLargest; i < startOfLargest + 13; ++i){
        std::cout << digits[i] << " x ";
    }
    std::cout << "\b\b= " << largestProduct << std::endl;
    
    return 0;
}

