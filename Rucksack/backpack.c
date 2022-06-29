#include "backpack.h"

int* backPacker(int amount, int* selected, int* weights, int* values, int remainingCapacity, int objIndex, int* beststate, int bestvalue) {

    // validate state
    if (objIndex == amount) {
        // all objects checked
        return selected;
    } else if (remainingCapacity == 0) {
        // no capacity left
        return selected;
    } else if (weights[objIndex] > remainingCapacity) {
        // check if new object is not to big
        selected[objIndex] = 0; // We don't want this anymore
        return selected;
    }


    // subsequent states

    // STATE A: add package
    int* withPkg = arraycopy(selected, amount);
    withPkg[objIndex] = 1;
    withPkg = backPacker(amount, withPkg, weights, values, remainingCapacity - weights[objIndex], objIndex + 1, beststate, bestvalue);

    int valueWith = getValue(withPkg, values, amount);
    if (valueWith > bestvalue) {
        bestvalue = valueWith;
        beststate = withPkg;
    }

    // STATE B: leave package
    int* withoutPkg = arraycopy(selected, amount);
    withoutPkg[objIndex] = 0;
    withoutPkg = backPacker(amount, withoutPkg, weights, values, remainingCapacity, objIndex + 1, beststate, bestvalue);

    int valueWithout = getValue(withoutPkg, values, amount);
    if (valueWithout > bestvalue) {
        beststate = withoutPkg;
    }

 
    // return best/current state
    return beststate;
}

int* greedyPacker(int amount, int* packed, int* weights, int* values, int capacity) {
    int weight = -1;

    // go through objects
    for (int i = 0; i < amount; ++i) {
        
        // check if object has value and isn't already packed
        if (values[i] && !packed[i]) {

            // now check if capacity is enough
            if (weights[i] <= capacity) {
                weight = weights[i];
                packed[i] = 1;

                // we found an object, no need to continue
                break;
            }
        }
    }

    // if no object matches the requirements, we return the solution, else we continue packing
    if (weight == -1) {
        return packed;
    } else {

        // recursive call to greedyPacker
        return greedyPacker(amount, packed, weights, values, capacity - weight);
    }
}

int* arraycopy(int* array, int length) {
    int* copy = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        copy[i] = array[i];
    }
    return copy;
}

int getWeight(int* selected, int* weights, int length) {
    int weight = 0;
    for (int i = 0; i < length; ++i) {
        weight += weights[i] * selected[i]; // no need for if statement because 0*x = 0
    }
    return weight;
}

int getValue(int* selected, int* values, int length) {
    int value = 0;
    for (int i = 0; i < length; ++i) {
        value += values[i] * selected[i];
    }
    return value;
}