#ifndef BOARDGAME
#define BOARDGAME

#include <span>
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>


template <typename T>
void display2DTable(T &table, int spaceBetweenDisplay) {
  const unsigned short ROW = 0;
  const unsigned short COL = 1;

  std::cout << std::setw(spaceBetweenDisplay) << "";
  for (size_t col = 0; col < table[COL].size(); ++col) {
    std::cout << std::setw(spaceBetweenDisplay) << col;
  }

  std::cout << std::endl;
  for (size_t row = 0; row < table[ROW].size(); ++row) {
    std::cout << std::setw(spaceBetweenDisplay) << row;
    for (size_t col = 0; col < table[COL].size(); ++col) {
      std::cout << std::setw(spaceBetweenDisplay) << table[row][col] ;
    }
    std::cout << std::endl;
  }
}



#endif
