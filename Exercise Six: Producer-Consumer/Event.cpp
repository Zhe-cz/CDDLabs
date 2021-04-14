/*! \mainpage Lab 6 Producer Consumer
     \author Zhe Cui
     \date 28/11/2020
     \copyright This code is covered by the GNU general public license v3.0
*/
#include "Event.h"
#include <iostream>
#include <stdlib.h>


/*! \file Event.cpp
    \fn Event::Event()
    \name The implementation of the Event
    \brief creates random characters from a-z lower case
*/

Event::Event()
{ 
  nChar = 'a'+rand()%26;
  std::cout << nChar<< "Produced : "<< std::endl;
}

/*! \file Event.cpp
    \fn void Event::consume()
    \name The implementation of the Event
    \brief Outputs a caharacter from lower case to upper case
*/

void Event::consume()
{
    char upperChar = nChar-32;    
    std::cout << upperChar << "Consumed : "<<std::endl;
}