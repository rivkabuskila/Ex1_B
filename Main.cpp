////
//// Created by rivka on 13/03/2022.
#include "mat.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

int main() {
    bool con = true;
    do {
        try {
            int column;
            int row;
            char symbol1;
            char symbol2;
            cout << "enter a column" << endl;
            cin >> column;
            cout << "enter a row" << endl;
            cin >> row;
            cout << "enter a symbol1" << endl;
            cin >> symbol1;
            cout << "enter a symbol2" << endl;
            cin >> symbol2;
            cout << ariel::mat(column, row, symbol1, symbol2) << endl;
            con = false;
        }

        catch (std::out_of_range ex) {
            cout << ex.what() << endl;
        }
    }while (con);


    return 0;
}

