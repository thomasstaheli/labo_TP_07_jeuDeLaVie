#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include "boardGame.h"
#include "programManager.h"

using namespace std;


const int timeSecond=500;

constexpr int MAXGAMEGENERATION=30;
constexpr char ALIVECELL='X';
constexpr char DEADCELL='.';
constexpr int DISPLAYSPACE=3;
extern const int TABLEROW=9;
extern const int TABLECOL=9;
using Board = array<array<char,TABLECOL>,TABLEROW>;

void displayNumberIteration(){
  static int numberIterartion;
  cout<<"------------------------------"<<endl;
  cout<<setw(20) << "GENRATION NO " << numberIterartion << endl;
  cout<<"------------------------------"<<endl;
  numberIterartion++;
}




void initializeBoard(Board &board) {

  board ={{
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //0
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //1
      {DEADCELL,DEADCELL,DEADCELL,ALIVECELL,ALIVECELL,ALIVECELL,DEADCELL,DEADCELL,DEADCELL}, //2
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,ALIVECELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //3
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,ALIVECELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //4
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,ALIVECELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //5
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //6
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //7
      {DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL,DEADCELL}, //8
  }};



//  random_device rd;
//  mt19937 gen(rd());
//  uniform_int_distribution<> dis(0, 1);
//
//  for (size_t i = 0; i < TABLEROW; ++i) {
//    for (size_t j = 0; j < TABLECOL; ++j) {
//      board[i][j] = dis(gen) == 0 ? DEADCELL : ALIVECELL;
//
//    }
//  }

}

void displayBoard(Board &board) {
  cout<<setw(DISPLAYSPACE)<<"";
  for (int col = 0; col < TABLECOL; ++col) {
    cout << setw(DISPLAYSPACE) << col;
  }
  cout<<endl;
  for (size_t row = 0; row < TABLEROW; ++row) {
    cout << setw(DISPLAYSPACE) << row;
    for (size_t col = 0; col < TABLECOL; ++col) {
      cout << setw(DISPLAYSPACE) << board[row][col] ;
    }
    cout << endl;
  }
}



int countLiveNeighbors(const Board &board, size_t row, size_t col) {
  int aliveNeighbors = 0;

  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (row + size_t(i) >= 0 && row + size_t(i) < board.size() && col + size_t(j) >= 0 && col + size_t(j) < board[row].size()) {
        aliveNeighbors += (board[row + size_t(i)][col + size_t(j)] == ALIVECELL) ? 1 : 0;
      }
    }
  }

  return aliveNeighbors;
}

void updateBoard(Board &board) {
  Board newBoard = board;

  for (size_t row = 0; row < TABLEROW; ++row) {
    for (size_t col = 0; col < TABLECOL; ++col) {
      int liveNeighbors = countLiveNeighbors(board, row, col);

      if (board[row][col] == ALIVECELL) {
        newBoard[row][col] = (liveNeighbors < 2 || liveNeighbors > 3) ? DEADCELL : ALIVECELL;
      } else {
        newBoard[row][col] = (liveNeighbors == 3) ? ALIVECELL : DEADCELL;
      }
    }
  }

  board = newBoard;
}


int main() {
  Board board;
  initializeBoard(board);


  for (int i = 0; i < MAXGAMEGENERATION; ++i) {


    displayNumberIteration();
    displayBoard(board);
    Board oldBoard = board;
    updateBoard(board);
    if (board == oldBoard) {
      break;
    }

    slowProgramMilliseconds(timeSecond);
    if (i < MAXGAMEGENERATION - 1)
      eraseOutput();

  }
  string s;
  cin >> s;
  return EXIT_SUCCESS;
}
