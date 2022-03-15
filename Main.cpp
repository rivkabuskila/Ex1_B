////
//// Created by rivka on 13/03/2022.
#include "mat.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    bool con = true;
    do {
        try {
            int column;
            int row;
            char symbol1;
            char symbol2;
            cout << "enter a column" << endl;
            while (!(cin >> column)) {
                cout << "column must be number, Please insert column" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }
            cout << "enter a row" << endl;
            while (!(cin >> row)) {
                cout << "row must be number, Please insert row" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }
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