#ifndef BACKPACK_H
#define BACKPACK_H

#include <stdlib.h>
#include <stdio.h>

// Algorithms
// backPacker:      selects the best combination of objects
// amount: int      amount of objects in the set
// selected: int*   the current select
// weights: int*    the weights of all objects
// values: int*     the values of all objects
// remainingCapacity: int   the remaining capacity, that can be filles
// objIndex: int    Marks the next Element to check
// beststate: int*  current best option
// bestvalue: int   current best value (reduces calls of getValue)
int* backPacker(int amount, int* selected, int* weights, int* values, int remainingCapacity, int objIndex, int* beststate, int bestvalue);

// greedyPacker:    packs every first element within the capacity
// amount: int      amount of objects in the set
// packed: int      stores the already packed objects
// weights: int*    the weights of all objects
// values: int*     the values of all ojects
// capacity: int    the remaining capacity
int* greedyPacker(int amount, int* weights, int capacity);


// utils
int* arraycopy(int* array, int length);
int getWeight(int* selected, int* weights, int length);
int getValue(int* selected, int* values, int length);


#endif//BACKPACK_H