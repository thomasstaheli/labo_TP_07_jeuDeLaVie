#ifndef TABLEHANDLING
#define TABLEHANDLING

#include <iomanip>

template <typename T>
void display2DTable(T &table, int spaceBetweenDisplay) {

  const unsigned short NESTED_TABLE_SIZE = 0;
  std::cout << std::setw(spaceBetweenDisplay) << "";
  for (size_t col = 0; col < table.size(); ++col) {
    std::cout << std::setw(spaceBetweenDisplay) << col;
  }

  std::cout << std::endl;
  for (size_t row = 0; row < table[NESTED_TABLE_SIZE].size(); ++row) {
    std::cout << std::setw(spaceBetweenDisplay) << row;
    for (size_t col = 0; col < table.size(); ++col) {
      std::cout << std::setw(spaceBetweenDisplay) << table[row][col] ;
    }
    std::cout << std::endl;
  }
}


#endif
