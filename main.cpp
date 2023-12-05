#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <thread>
#include "boardGame.h"
#include "tableHandling.h"

#ifdef _WIN32
#define CLEAR_TERMINAL system("CLS");
#else
#define CLEARTERMINAL system("clear");
#endif

using namespace std;

const unsigned int  TABLE_ROW = 9;
const unsigned int  TABLE_COL = 9;
const unsigned int  MAX_GAME_GENERATION = 10;

const unsigned int  SLEEP_TIMES = 500;

const unsigned int  SPACING_FOR_CASE   = 3;
const char          ALIVE_CELL         = 'X';
const char          DEAD_CELL          = '.';

using Board = array<array<char, TABLE_COL>, TABLE_ROW>;


const unsigned int NUMBER_LINE_SEPARATOR   = SPACING_FOR_CASE * (TABLE_ROW+1);
const string       TITLE_GENERATION        = "GENERATION NO ";
const string       TABLE_GENERATION_BORDER(size_t(NUMBER_LINE_SEPARATOR), '-');


int main() {
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

  initializeBoard(actualBoard, ALIVE_CELL, DEAD_CELL);
  Board oldBoard = {{{}}};

  for (unsigned int i = 0; i < MAX_GAME_GENERATION and actualBoard != oldBoard; ++i) {
    displayTitleWithSeparation(TITLE_GENERATION, NUMBER_LINE_SEPARATOR, TABLE_GENERATION_BORDER);
    display2DTable(actualBoard, SPACING_FOR_CASE);
    oldBoard = actualBoard;
    updateBoard(actualBoard, ALIVE_CELL, DEAD_CELL);

    this_thread::sleep_for(chrono::milliseconds(SLEEP_TIMES));

    if (i < MAX_GAME_GENERATION - 1 and actualBoard != oldBoard)
      CLEAR_TERMINAL

  }
  cout << endl;
  system("pause");
  return EXIT_SUCCESS;
}
