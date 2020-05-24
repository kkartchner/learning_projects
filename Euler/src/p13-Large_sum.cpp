#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>

/**
 * Large Sum:
 *
 * "Work out the first ten digits of the sum of the following one-hundred 50-digit numbers."
 */
int main (int argc, char** argv)
{ 
    using namespace boost::multiprecision;
    std::ifstream inFile("res/p13-number.txt");
    if (!inFile.is_open()){
        std::cout << "\"res/p13-number.txt\" failed to open. Does it exist?"
            << std::endl;

        return -1;
    }

    cpp_int sum = 0;
    std::string curNum = "";

    while (inFile >> curNum){
        std::cout << curNum << std::endl;
        cpp_int temp(curNum);
        sum += temp;
    }

    std::cout << "\nThe sum of the above 100 numbers is:\n" << sum << std::endl;

    // Divide by 10 until it has only 10 digits (less than first eleven digit number, 1e10):
    while (sum > (unsigned long) 1e10){  
        sum /= 10;
    } 

    std::cout << "The first ten digits are: " << sum << std::endl;

    return 0;
}
