#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "backpack.h"

// time stopping function
long long timeInMilliseconds(void);


// test worst case backtarcking
void testbacktracking();

// test worst case greedy
void testgreedy();

#endif//TEST_H
