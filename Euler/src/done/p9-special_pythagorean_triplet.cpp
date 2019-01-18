#include <iostream>
#include <map>
/**
 * "A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *
 * a2 + b2 = c2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc."
 */
int main (int argc, char** argv)
{
    std::map<int, int> abCombos; // map<a, b>
    int abcSum = (argc > 1) ? std::stoi(argv[1]) : 1000;

    auto bofa = [](int a){ 
        return ( 1000 * (a-500)) / (a-1000);
    };

    for (int a = 1; a < 333; ++a){
        int b = bofa(a);
        if (a > b)
            break;
        abCombos[a] = b;
   }

    for (auto const &combo : abCombos){
        const int &a = combo.first;
        const int &b = combo.second;
        const int c = 1000 - a - b;

        if ((a*a + b*b) == c*c){
            std::cout << "Pythagorean triplet for which a + b + c = " << abcSum << ":"  << std::endl;           
            std::cout << "a: " << a << " b: " << b
                << " c: " << c << std::endl;
            std::cout << "a*b*c = " << a*b*c << std::endl;
            break;
        }
    }

    return 0;
}
