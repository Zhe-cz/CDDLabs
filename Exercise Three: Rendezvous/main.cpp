/*! \mainpage Lab 3 Rendezvous
     \author Zhe Cui
     \date 13/11/2020
     \copyright This code is covered by the GNU general public license v3.0
*/
/*! \file main.cpp
    \brief An Implementation of a Rendezvous using Semaphores
*/


#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! \fn taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay)
    \brief "This function will print "Task One has arrived!" "Task One has left!"
    \param firstSem the firstSem used for flow control
    \param secondSem the secondSem used for flow control

    This function will displays a message that is split in to 2 sections to show how a rendezvous works
*/ 
void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  
  std::cout <<"Task One has arrived! "<< std::endl;
  firstSem->Wait();
  secondSem->Signal();
  //THIS IS THE RENDEZVOUS POINT!
  std::cout << "Task One has left!"<<std::endl;
  
}

/*! \fn taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay)
    \brief "This function will print "Task Two has arrived!" "Task Two has left!"
    \param firstSem the firstSem used for flow control
    \param secondSem the secondSem used for flow control
    
    This function will displays a message that is split in to 2 sections to show how a rendezvous works
*/ 
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  
  std::cout <<"Task Two has arrived "<<std::endl;
  firstSem->Signal();
  secondSem->Wait();
  //THIS IS THE RENDEZVOUS POINT!
  std::cout << "Task Two has left "<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2,taskTwoDelay);
  threadTwo=std::thread(taskOne,sem1,sem2,taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
