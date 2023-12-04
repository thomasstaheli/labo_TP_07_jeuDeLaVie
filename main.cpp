#include <iostream>
#include <iomanip>
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



void displayTitleWithSeparation(const string& text, int numberLineSeparator, const string& symbolSeparator){
  static int numberIterartion;

  const int spaceToMiddle= numberLineSeparator/2 + (int(text.size())/2) - 1;

  cout << symbolSeparator   << endl;
  cout << setw(spaceToMiddle) << text << numberIterartion << endl;
  cout << symbolSeparator   << endl;

  numberIterartion++;
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
    updateBoard(actualBoard,ALIVECELL,DEADCELL);

    // Changement afin d'éviter un fichier
    this_thread::sleep_for(chrono::milliseconds(SLEEPTIMEMS));
    // Ajout de la condition après le 'and ...'
    if (i < MAXGAMEGENERATION - 1 and actualBoard != oldBoard)
      CLEARTERMINAL

  }
  // Ajout de l'attente que l'utilisateur appuisse sur enter pour terminer le programme
  cout << endl << "Press any key to finish ...";
  cin.get();
  return EXIT_SUCCESS;
}
