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
    } else if (weights[objIndex] == 0) {
        // always good
        selected[objIndex] = 1;
        return backPacker(amount, selected, weights, values, remainingCapacity, objIndex + 1, beststate, bestvalue);
    } else if (values[objIndex] == 0) {
        // always bad
        selected[objIndex] = 0;
        return backPacker(amount, selected, weights, values, remainingCapacity, objIndex + 1, beststate, bestvalue);
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
    int* withoutPkg = selected;
    withoutPkg[objIndex] = 0;
    withoutPkg = backPacker(amount, withoutPkg, weights, values, remainingCapacity, objIndex + 1, beststate, bestvalue);

    int valueWithout = getValue(withoutPkg, values, amount);
    if (valueWithout > bestvalue) {
        bestvalue = valueWithout;
        beststate = withoutPkg;
    }

    return beststate;
}

int* greedyPacker(int amount, int* weights, int capacity) {
    
    int* packed = calloc(amount, sizeof(int));

    for (int i = 0; i < amount; ++i) {
        if (weights[i] > capacity) {
            packed[i] = 0;
        } else {
            packed[i] = 1;
            capacity -= weights[i];
        }
        if (capacity <= 0) {
            // no capacity left
            break;
        }
    }
    return packed;
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
