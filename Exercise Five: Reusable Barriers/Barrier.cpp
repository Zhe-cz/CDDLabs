/*! \mainpage Lab 5 Barriers
    \author Zhe Cui
    \date 20.11.2020
    \version GNU AFFERO GENERAL PUBLIC LICENSE Version 3, 19 November 2007
*/

// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Joseph
// Maintainer: 
// Created: Tue Jan  8 12:14:02 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Tue Jan  8 12:15:21 2019 (+0000)
//           By: Joseph
//     Update #: 2
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

/*!
    \fn Barrier::~Barrier()
    \brief The destructor invoked when the objects are destroyed
*/
Barrier::~Barrier()
{}
/*!
    \fn void Barrier::phaseOne()
     \brief First phase of the rendezvous between threads. 
     Using semaphores and mutex to control the flow 
*/
void Barrier::phaseOne()
{
    /* Counting how many threads have arrived.//
    Mutex provides access to count */
    mutex.Wait();
    ++count;
    if (count == numThreads)
    {
        std::cout<<std::endl;
        secondTurnStile.Wait();
        firstTurnStile.Signal();
    }
    mutex.Signal();

    firstTurnStile.Wait();
    firstTurnStile.Signal();
}
/*!
    \fn void Barrier::phaseTwo()
     \brief Second phase of the rendezvous between n number of threads.
     Using semaphores and mutex to control the flow
*/
void Barrier::phaseTwo()
{
    mutex.Wait();
    --count;
    if (count == 0)
    {
        firstTurnStile.Wait();
        secondTurnStile.Signal();
    }
     if (count == 0)
    {
        std::cout<<std::endl;
    }
    mutex.Signal();

    secondTurnStile.Wait();
    secondTurnStile.Signal();
}
/*!
    \fn Barrier::wait()
    \brief Wait function that calls phaseOne() and phaseTwo() functions in sequence
*/
void Barrier::wait()
{
    phaseOne();
    phaseTwo();
}

//
// Barrier.cpp ends here



