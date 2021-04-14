/*! \mainpage Lab 6 Producer Consumer
     \author Zhe Cui
     \date 28/11/2020
     \copyright This code is covered by the GNU general public license v3.0
*/
#include "SafeBuffer.h"
#include <iostream>
#include <stdlib.h>
#include "Event.h"
   
SafeBuffer::SafeBuffer()
{
    theMutex = std::make_shared<Semaphore>(1);
    theSemaphore = std::make_shared<Semaphore>(0);
}

/*!
    \fn SafeBuffer::push(Event lowerChar)
    \brief add event into the buffer
    \param lowerChar The lower case character event created 
*/

int SafeBuffer::push(Event lowerChar)
{
    theMutex->Wait();
    theData.push_back(lowerChar);
    int size = theData.size();
    theMutex->Signal();
    theSemaphore->Signal();
    return size;
}

/*!
    \fn SafeBuffer::pop()
    \brief consumes an event from the buffer
*/

Event SafeBuffer::pop()
{
    theSemaphore->Wait();
    theMutex->Wait();
    Event e = theData.back();
    theData.pop_back();
    theMutex->Signal();
    return e;
}