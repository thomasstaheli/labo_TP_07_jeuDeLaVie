#include <iostream>
#include <iomanip>
#include <array>
#include <thread>
#include "boardGame.h"

#ifdef _WIN32
#define CLEARTERMINAL system("CLS");
#else
#define CLEARTERMINAL system("clear");
#endif

using namespace std;

const int TABLEROW = 9;
const int TABLECOL = 9;
const int  MAXGAMEGENERATION = 5;

const int  SLEEPTIMEMS = 500;

const int  SPACINGFORCASE    = 3;
const char ALIVECELL         = 'X';
const char DEADCELL          = '.';

using Board = array<array<char, TABLECOL>, TABLEROW>;




const int    NUMMBERLINESEPARATOR        = 30;
const string TABLEGENERATIONBORDEUR(size_t(NUMMBERLINESEPARATOR), '-');
const string TITLEGENERARTION       = "GENRATION NO ";



void displayTitleWithSeparation(const string& text, int numberLineSeparator, const string& symbolSeparator){
  static int numberIterartion;

  const int spaceToMiddle= numberLineSeparator/2 + (int(text.size())/2) - 1;

  cout << symbolSeparator   << endl;
  cout << setw(spaceToMiddle) << text << numberIterartion << endl;
  cout << symbolSeparator   << endl;

  numberIterartion++;
}


int countLiveNeighbors(const Board &board, size_t row, size_t col) {
  int aliveNeighbors = 0;
  for (int rowNextToCell = -1; rowNextToCell <= 1; ++rowNextToCell) {
    for (int colNextToCell = -1; colNextToCell <= 1; ++colNextToCell) {
      if (rowNextToCell == 0 && colNextToCell == 0) {
        continue;
      }
      if ( row + size_t(rowNextToCell) < board.size()  && col + size_t(colNextToCell) < board[row].size()) {
        aliveNeighbors += (board[row + size_t(rowNextToCell)][col + size_t(colNextToCell)] == ALIVECELL) ? 1 : 0;
      }
    }
  }

  return aliveNeighbors;
}

void updateBoard(Board &actualBoard) {
  Board newBoard = actualBoard;
  // Faire une fonction pour lire un tableau ? Generique ?
  for (size_t row = 0; row < TABLEROW; ++row) {
    for (size_t col = 0; col < TABLECOL; ++col) {
      const int liveNeighbors = countLiveNeighbors(actualBoard, row, col);

      if (actualBoard[row][col] == ALIVECELL) {
        newBoard[row][col] = (liveNeighbors < 2 || liveNeighbors > 3) ? DEADCELL : ALIVECELL;
      } else {
        newBoard[row][col] = (liveNeighbors == 3) ? ALIVECELL : DEADCELL;
      }
    }
  }

  actualBoard = newBoard;
}


int main() {
  // J'a enlevé la fonction pour affecter le tableau
  Board actualBoard = {{
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //0
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //1
      {DEADCELL ,DEADCELL ,DEADCELL ,ALIVECELL,ALIVECELL,ALIVECELL,DEADCELL, DEADCELL, DEADCELL}, //2
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,ALIVECELL,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //3
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,ALIVECELL,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //4
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,ALIVECELL,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //5
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //6
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //7
      {DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL ,DEADCELL, DEADCELL, DEADCELL}, //8
  }};
  // J'ai enlevé la condition avec le break pour éviter le break
  Board oldBoard = {{{}}};
  // Ajout de la condition dans la for
  for (int i = 0; i < MAXGAMEGENERATION and actualBoard != oldBoard; ++i) {
    // Est-ce possible d'avoir plus de clareté dans les noms de fonctions ?
    displayTitleWithSeparation(TITLEGENERARTION,NUMMBERLINESEPARATOR,TABLEGENERATIONBORDEUR);
    display2DTable(actualBoard, SPACINGFORCASE);
    oldBoard = actualBoard;
    updateBoard(actualBoard);

    // Changement afin d'éviter un fichier
    this_thread::sleep_for(chrono::milliseconds(SLEEPTIMEMS));
    // Ajout de la condition après le 'and ...'
    if (i < MAXGAMEGENERATION - 1 and actualBoard != oldBoard)
      CLEARTERMINAL

  }
  // Ajout de l'attente que l'utilisateur appuisse sur enter pour terminer le programme
  cout << endl << "Presse [enter] to finish ...";
  cin.get();
  return EXIT_SUCCESS;
}
