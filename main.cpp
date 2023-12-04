#include <iostream>
#include <array>
#include <thread>
#include "boardGame.h"
#include "tableHandling.h"

#ifdef _WIN32
#define CLEARTERMINAL system("CLS");
#else
#define CLEARTERMINAL system("clear");
#endif

using namespace std;

const int TABLEROW = 9;
const int TABLECOL = 9;
const int  MAXGAMEGENERATION = 10;

const int  SLEEPTIMEMS = 500;

const int  SPACINGFORCASE    = 3;
const char ALIVECELL         = 'X';
const char DEADCELL          = '.';

using Board = array<array<char, TABLECOL>, TABLEROW>;


const int    NUMMBERLINESEPARATOR        = SPACINGFORCASE * (TABLEROW+1);
const string TABLEGENERATIONBORDEUR(size_t(NUMMBERLINESEPARATOR), '-');
const string TITLEGENERARTION       = "GENRATION NO ";





int main() {
  // problème si on change la taille de TABLEROW / TABLECOL il faut aussi modifier tout ce tableau avec des 0 et 1
  Board actualBoard = {{
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0}
                       }};

  initializeBoard(actualBoard, ALIVECELL, DEADCELL);
  Board oldBoard = {{{}}};

  for (int i = 0; i < MAXGAMEGENERATION and actualBoard != oldBoard; ++i) {
    displayTitleWithSeparation(TITLEGENERARTION, NUMMBERLINESEPARATOR, TABLEGENERATIONBORDEUR);
    display2DTable(actualBoard, SPACINGFORCASE);
    oldBoard = actualBoard;
    updateBoard(actualBoard, ALIVECELL, DEADCELL);

    this_thread::sleep_for(chrono::milliseconds(SLEEPTIMEMS));

    if (i < MAXGAMEGENERATION - 1 and actualBoard != oldBoard)
      CLEARTERMINAL

  }

  //any key au lieu de enter
  cout << endl << "Press any key to finish ...";
  cin.get();
  return EXIT_SUCCESS;
}
