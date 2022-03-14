//
// Created by rivka on 06/03/2022.
#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <vector>

using namespace std;


namespace ariel {


   string mat(int column, int row, char symbol1, char symbol2) {
        if ((column*row)%2==0){
            throw std::out_of_range{"Mat size is always odd"};
        }

        if (column < 0 || row < 0) {
            throw std::out_of_range{"Negative values"};
        }
        if (symbol1 == '\r' || symbol2 == '\r'){
            throw std::out_of_range{"Invalid character"};
        }
        if (symbol1 == ' ' || symbol2 == ' '){
            throw std::out_of_range{"Invalid character"};
        }
        if (symbol1 == '\t' || symbol2 == '\t'){
            throw std::out_of_range{"Invalid character"};
        }
        if (symbol1 == '\n' || symbol2 == '\n'){
            throw std::out_of_range{"Invalid character"};
        }
        if (symbol1 < ' '){
            throw std::out_of_range{"Invalid character"};
        }
        if (symbol1 > '~'){
            throw std::out_of_range{"Invalid character"};
        }
        if (symbol2 < ' '){
            throw std::out_of_range{"Invalid character"};
        }
        if (symbol2 > '~'){
            throw std::out_of_range{"Invalid character"};
        }


        vector<vector<char>> matrix(row, vector<char>(column));
        int start_column = 0;
        int end_column = column-1;
        int start_row = 0;
        int end_row = row-1;
        int change = 1;
        char fill=' ';
        while ((start_row <= end_row)&&(start_column <= end_column)){
            if (change == 1) {
                fill = symbol1;
            } else {
                fill = symbol2;
            }

            for (int i = start_column; i <= end_column; i++) {
                matrix[start_row][i] = fill;
            }
            for (int i = start_column; i <= end_column; i++) {
                matrix[end_row][i] = fill;
            }
            for (int i = start_row; i <= end_row; i++) {
                matrix[i][start_column] = fill;
            }
            for (int i = start_row; i <= end_row; i++) {
                matrix[i][end_column] = fill;
            }
            start_row++;
            end_row--;
            start_column++;
            end_column--;
            change = change *(-1);
        }
        string s;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                s +=matrix[i][j];
            }
            s += "\n";
        }
        return s;
    }



}

