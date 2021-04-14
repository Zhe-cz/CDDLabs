/*! \mainpage Lab 6 Producer Consumer
     \author Zhe Cui
     \date 28/11/2020
     \copyright This code is covered by the GNU general public license v3.0
*/

#include "SafeBuffer.h"
#include "Event.h"
#include <iostream>
#include <thread>
#include <vector>
static const int num_threads = 100;
const int size=20;


/*! \fn producer
    \brief Creates events and adds them to buffer
    \param theBuffer
    \param numLoops
*/

void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
{
  for(int i=0;i<numLoops;++i)
  {
    //Produce event and add to buffer
    Event event ;
    theBuffer->push(event);
  } 
}


/*! \fn consumer
    \brief Takes events from buffer and consumes them
    \param theBuffer
    \param numLoops
*/

void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
{

  for(int i=0;i<numLoops;++i)
  {
    //Produce event and add to buffer
    Event event ;
    event = theBuffer->pop();
    event.consume();
  }
}

int main(void)
{

  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer( new SafeBuffer());
  /**< Launch the threads  */
  for(std::thread& prod: producers)
  {
    prod=std::thread(producer,aBuffer,10);
  }

  for(std::thread& cons: consumers)
  {
    cons=std::thread(consumer,aBuffer,10);
  }

  /**< Join the threads with the main thread */
  for (auto& p :producers)
  {
      p.join();
  }
  for (auto& c :consumers)
  {
      c.join();
  }

  std::cout  << std::endl;
  return 0;
}
