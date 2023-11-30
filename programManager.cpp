#include "programManager.h"
#include <iostream>
#include <thread>



void eraseOutput (){
#ifdef _WIN32
  system("CLS");
#else
  system("clear");
#endif
}

void slowProgramMilliseconds(int time)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}