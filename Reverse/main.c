#include <stdlib.h>
#include <stdio.h>

void reverse(char* string, int length, int i) {
    
    if (i < length - i) {
        string[i] += string[length - i];
        string[length - i] = string[i] - string[length - i];
        string[i] -= string[length - i];

        reverse(string, length,  i + 1);        
    }
    /*for (int i = 0; i < (int)(length / 2); ++i) {

    }*/
}

int main() {

    char test[] = "Laufzeittest";

    reverse(test, 12, 0);
    for (int i = 0; i < 13; ++i)
        printf("%c", test[i]);
    printf("\n");
    return 0;
}