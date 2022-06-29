#include <stdlib.h>
#include <stdio.h>

#include "backpack.h"

/*
 *
 * Die Kapazitätsrechnung im greedy-Algorithmus wird fehlerhaft berechnet (50 Gewicht bei 30 Plätzen)
 * 
 */

int main() {
    const int NOBJS = 16;
    int gewichte[] = {10, 5, 7, 11, 13, 1, 7, 11, 13, 19, 19, 9, 8, 2, 7, 31};
    int werte[] = {7, 6, 1, 1, 1, 4, 11, 20, 3, 7, 8, 9, 16, 19, 100, 3};
    int capacity = 30;

    // arrays needed
    int* gewaehlt = calloc(NOBJS, sizeof(int)); // set the array to zero
    int* solutionbacktrack = calloc(NOBJS, sizeof(int)); // slow but perfect solution
    int* solutiongreedy = calloc(NOBJS, sizeof(int)); // fast but stupid solution
    
    // running the algorithm(s)
    solutionbacktrack = backPacker(NOBJS, gewaehlt, gewichte, werte, capacity, 0, solutionbacktrack, 0);
    solutiongreedy = greedyPacker(NOBJS, solutiongreedy, gewichte, werte, capacity);

    // Output
    printf("BACKTRACKING\n");
    printf("Der maximale Wert beträgt >%d< Einheiten\n", getValue(solutionbacktrack, werte, NOBJS));
    for (int i = 0; i < NOBJS; ++i) {
        printf("%d:\tselected[%d]\t=\t%d,\tweights[%d]\t=\t%d,\tvalues[%d]\t=\t%d\n", i, i, solutionbacktrack[i], i, gewichte[i], i, werte[i]);
    }
    printf("Die benutzte Kapazität beträgt >%d< Einheiten\n", getWeight(solutionbacktrack, gewichte, NOBJS));


    printf("GREEDY\n");
    printf("Der maximale Wert beträgt >%d< Einheiten\n", getValue(solutiongreedy, werte, NOBJS));
    for (int i = 0; i < NOBJS; ++i) {
        printf("%d:\tselected[%d]\t=\t%d,\tweights[%d]\t=\t%d,\tvalues[%d]\t=\t%d\n", i, i, solutiongreedy[i], i, gewichte[i], i, werte[i]);
    }
    printf("Die benutzte Kapazität beträgt >%d< Einheiten\n", getWeight(solutiongreedy, gewichte, NOBJS));



    return EXIT_SUCCESS;
}