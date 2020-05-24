#include "Grid.hpp"

#include <string>
#include <fstream>
#include <algorithm>

#define DEBUG 1
/**
 * What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
 */
int main (int argc, char** argv)
{
    int width = (argc>2) ? std::stoi(argv[1]) : 20;
    int height = (argc>2) ? std::stoi(argv[2]) : 20;
    std::string filename = (argc>3) ? argv[3] : "res/p11-grid";

    Grid<unsigned int> numberGrid(width, height);    

    std::ifstream gridFile(filename);
    if (gridFile.is_open()){
        unsigned int curNum;
        while (gridFile >> curNum && numberGrid.hasRoom()){
            numberGrid.add(curNum);
        }     
    }

    unsigned long highestProduct = 1;
    auto maxProdOf = [&](int x, int y){
        int startX = x, startY = y, lx = x;
        unsigned long rightProd = 1, downProd = 1, rdiagProd = 1, ldiagProd = 1;
#if DEBUG
        std::cout << "maxProdOf called on (" << x << "," << y << ") (value: " << numberGrid.get(x, y) << "): "
            << std::endl << "right\tdown\trdiag\tldiag" << std::endl;
#endif

        for (int i = 0; i < 4; ++i, ++x, ++y, --lx){
            if (numberGrid.pointInBounds(x, startY)){                // Find right product:
#if DEBUG
                std::cout << numberGrid.get(x, startY) << "\t";
#endif
                rightProd *= numberGrid.get(x, startY);
            } else {
#if DEBUG
                std::cout << "\t";
#endif
                rightProd = 1;
            }

            if (numberGrid.pointInBounds(startX, y)){                // Find down product:
#if DEBUG
                std::cout << numberGrid.get(startX, y) << "\t";
#endif
                downProd *= numberGrid.get(startX, y);
            } else {
#if DEBUG
                std::cout << "\t";
#endif
                downProd  = 1;
            }

            if (numberGrid.pointInBounds(x, y)){                     // Find right diagonal product:
#if DEBUG
                std::cout << numberGrid.get(x, y) << "\t";
#endif
                rdiagProd *= numberGrid.get(x, y);
            } else {
#if DEBUG
                std::cout << "\t";
#endif
                rdiagProd = 1;
            }
            
            if (numberGrid.pointInBounds(lx, y)){                    // Find left diagonal product:
#if DEBUG
                 std::cout << numberGrid.get(lx, y) << std::endl;
#endif
                ldiagProd *= numberGrid.get(lx, y);
            } else {
#if DEBUG
                std::cout << std::endl;
#endif
                ldiagProd = 1;
            }
        }
#if DEBUG
        std::cout << std::endl;
#endif
        unsigned long maxProd = std::max(rightProd, std::max(downProd, std::max(rdiagProd, ldiagProd)));
        highestProduct = std::max(maxProd, highestProduct);
#if DEBUG
        std::cout << "rightProd: " << rightProd << " | downProd: " << downProd 
            << " | rdiagProd: " << rdiagProd << " | ldiagProd: " << ldiagProd << std::endl << std::endl;
#endif
            // Return greatest of the product:
        return;
    };

    numberGrid.print();
    numberGrid.forEach(maxProdOf);

    std::cout << "\nHighest product of 4 adjacent numbers is: "  << highestProduct << std::endl;
#if DEBUG
    numberGrid.print();
#endif
    return 0;
}
