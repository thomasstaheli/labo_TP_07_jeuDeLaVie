#include <iostream>
#include <iomanip>
#include "boardGame.h"

void displayTitleWithSeparation(const std::string& text, int numberLineSeparator, const std::string& symbolSeparator){
  static int numberIteration;
  const int SPACE_TO_MIDDLE = numberLineSeparator/2 + (int(text.size())/2) - 1;

  std::cout << symbolSeparator   << std::endl;
  std::cout << std::setw(SPACE_TO_MIDDLE) << text << numberIteration << std::endl;
  std::cout << symbolSeparator   << std::endl;

  numberIteration++;
}