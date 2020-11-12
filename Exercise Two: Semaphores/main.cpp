/*! \mainpage Lab 2 Semaphores
     \author Zhe Cui
     \date 12/11/2020
     \copyright This code is covered by the GNU general public license v3.0
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*! \class Signal
    \brief An Implementation of Threads Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 

*/
/*! \fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)
    \brief This function will print "I must print first to the screen" with a delay
    \param delay the delay in seconds enforced on the function
    \param theSemaphore the semaphore used for flow control
    This function will sleep for the delay in seconds before printing out "I must print first" to the screen
    We will use the semaphore to control the flow of control between the function 
    and taskTwo to get the correct order of print outs
*/

void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
/*! \fn void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
    \brief "This function will print "This will appear second"
    \param theSemaphore the semaphore used for flow control
    
    This function will printing out "This will appear second" after the theSemaphore is signaled
*/ 
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}


int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
