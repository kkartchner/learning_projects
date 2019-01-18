#include <iostream>

int main (int argc, char** argv)
{ 
    unsigned int longestSequence = 0, longestStartNum = 0;

    for (unsigned int startNum = 1e6-1; startNum > 0; --startNum){
        unsigned int sequenceLength = 0;
        // While n is not 1, n = 3n + 1 (if n is odd) or n = n/2 (if n is even):
        for (unsigned int n = startNum; n != 1 ; n = (n % 2) ? 3*n + 1 : n/2){
            ++sequenceLength;
        }
        // Update longest sequence length and startNum if if needed:needed
        if (sequenceLength > longestSequence){
            longestSequence = sequenceLength;
            longestStartNum = startNum;

            std::cout << "new longest found: " << longestStartNum << ", len: " << longestSequence
                << std::endl;

        }
    }
    std::cout << "Done.\nThe number under 1 million  with the longest Collatz sequence is " << longestStartNum << std::endl;

    return 0;
}
