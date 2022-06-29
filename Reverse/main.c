#include <stdlib.h>
#include <stdio.h>


// reverse: reverses a c-string
// char* string: pointer to c-string to reverse
// int length: Länge des strings in Zeichen (Das Nullbyte darf NICHT mitgezählt werden)
// int i: als Startwert Null übergeben
void reverse(char* string, int length, int i) {
    
    if (i < length - i) {
        string[i] += string[length - i];
        string[length - i] = string[i] - string[length - i];
        string[i] -= string[length - i];

        reverse(string, length,  i + 1);        
    }
}

int main() {

    char test[] = "leohortetrohoel";
    int length = sizeof(test) / sizeof(char);

    reverse(test, length - 1, 0);
    for (int i = 0; i < 16; ++i)
        printf("%c", test[i]);
    printf("\n");
    return 0;
}