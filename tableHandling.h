#ifndef TABLEHANDLING
#define TABLEHANDLING

#include <iomanip>
#include <string>

void displayTitleWithSeparation(const std::string& text, int numberLineSeparator, const std::string& symbolSeparator){
  static int numberIterartion;

  const int spaceToMiddle= numberLineSeparator/2 + (int(text.size())/2) - 1;

  std::cout << symbolSeparator   << std::endl;
  std::cout << std::setw(spaceToMiddle) << text << numberIterartion << std::endl;
  std::cout << symbolSeparator   << std::endl;

  numberIterartion++;
}


template <typename T>
void display2DTable(T &table, int spaceBetweenDisplay) {

  const unsigned short IMBRICKEDTABLESIZE = 0;

  std::cout << std::setw(spaceBetweenDisplay) << "";
  for (size_t col = 0; col < table.size(); ++col) {
    std::cout << std::setw(spaceBetweenDisplay) << col;
  }

  std::cout << std::endl;
  for (size_t row = 0; row < table[IMBRICKEDTABLESIZE].size(); ++row) {
    std::cout << std::setw(spaceBetweenDisplay) << row;
    for (size_t col = 0; col < table.size(); ++col) {
      std::cout << std::setw(spaceBetweenDisplay) << table[row][col] ;
    }
    std::cout << std::endl;
  }
}


#endif
