#ifndef BOARDGAME
#define BOARDGAME


#include <iostream>
#include <string>

const unsigned short ROW = 0;


template <typename T ,typename AliveCellType>
int countLiveNeighbors(T& actualBoard, std::size_t row, std::size_t col,AliveCellType aliveCell){
  int aliveNeighbors = 0;
  for (int rowNextToCell = -1; rowNextToCell <= 1; ++rowNextToCell) {
    for (int colNextToCell = -1; colNextToCell <= 1; ++colNextToCell) {
      if ( row + size_t(rowNextToCell) < actualBoard.size()  && col + size_t(colNextToCell) < actualBoard[row].size()) {
        aliveNeighbors += (actualBoard[row + size_t(rowNextToCell)][col + size_t(colNextToCell)] == aliveCell) ? 1 : 0;
      }
    }
  }

  return aliveNeighbors;
}


template <typename T ,typename AliveCellType,typename DeadCellType>
void updateBoard(T& actualBoard, AliveCellType aliveCell, DeadCellType deadCell) {
  T newBoard = actualBoard;
  for (size_t row = 0; row < actualBoard[ROW].size(); ++row) {
    for (size_t col = 0; col < actualBoard.size(); ++col) {
      int liveNeighbors = countLiveNeighbors(actualBoard, row, col,aliveCell) - ((actualBoard[row][col] == aliveCell) ? 1:0);

      if (actualBoard[row][col] == aliveCell) {
        newBoard[row][col] = (liveNeighbors < 2 || liveNeighbors > 3) ? deadCell : aliveCell;
      } else {
        newBoard[row][col] = (liveNeighbors == 3) ? aliveCell : deadCell;
      }
    }
  }

  actualBoard = newBoard;
}






#endif
