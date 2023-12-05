#ifndef BOARDGAME
#define BOARDGAME

const unsigned short  ROW = 0;
const size_t STARTING_POS = 0;

void displayTitleWithSeparation(const std::string& text, int numberLineSeparator, const std::string& symbolSeparator);

template <typename T, typename AliveCellType,typename DeadCellType>
void initializeBoard(T& table, AliveCellType aliveCell, DeadCellType deadCell) {
  const int ALIVE_CELL = 1;

  for (size_t row = STARTING_POS; row < table[ROW].size(); ++row) {
    for (size_t col = STARTING_POS; col < table.size(); ++col) {
      table[row][col] = table[row][col]==ALIVE_CELL ? aliveCell:deadCell;
    }
  }
}


template <typename T ,typename AliveCellType>
int countLiveNeighbors(T& actualBoard, std::size_t row, std::size_t col,AliveCellType aliveCell){
  int aliveNeighbors = 0;
  const int STARTING_POS_NEIGHBORS = -1;
  const int ENDING_POS_NEIGHBORS   =  1;

  for (int rowNextToCell = STARTING_POS_NEIGHBORS; rowNextToCell <= ENDING_POS_NEIGHBORS; ++rowNextToCell) {
    for (int colNextToCell = STARTING_POS_NEIGHBORS; colNextToCell <= ENDING_POS_NEIGHBORS; ++colNextToCell) {
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
  const unsigned short MIN_NEIGHBORS_TO_SURVIVE = 2;
  const unsigned short NUMBER_OF_NEIGHBORS_TO_REVIVE = 3;

  for (size_t row = STARTING_POS; row < actualBoard[ROW].size(); ++row) {
    for (size_t col = STARTING_POS; col < actualBoard.size(); ++col) {
      int aliveCellsNeighbors = countLiveNeighbors(actualBoard, row, col, aliveCell) - ((actualBoard[row][col] == aliveCell) ? 1 : 0);

      if (actualBoard[row][col] == aliveCell) {
        newBoard[row][col] = (aliveCellsNeighbors < MIN_NEIGHBORS_TO_SURVIVE || aliveCellsNeighbors > NUMBER_OF_NEIGHBORS_TO_REVIVE) ? deadCell : aliveCell;
      } else {
        newBoard[row][col] = (aliveCellsNeighbors == NUMBER_OF_NEIGHBORS_TO_REVIVE) ? aliveCell : deadCell;
      }
    }
  }

  actualBoard = newBoard;
}


#endif
