#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "find_two_chars.c"

int main() {
    printf("Testing assignment examples...\n");
    assert(find_two_chars ("hello", 'h', 'e') == 0); //returns 0
    assert(find_two_chars ("hello", 'l', 'l') == 0); //returns 0
    assert(find_two_chars ("hello", 'o', 'l') == 1); //returns 1
    assert(find_two_chars ("hello", 'h', 'o') == 2); //returns 2
    printf("Passed!\n");
    
    printf("Testing Josh Kunz's corner cases...\n");
    assert(find_two_chars("ab\0x", 'b', 'a') == 1);
    assert(find_two_chars("", '\0', 'a') == 2);
    assert(find_two_chars("", 'a', 'b') == 2);
    assert(find_two_chars("a", 'a', 'b') == 2);
    assert(find_two_chars("a", 'a', '\0') == 2);
    assert(find_two_chars("a\0x", 'a', 'x') == 2);
    assert(find_two_chars("a\0xa", 'a', 'x') == 2);
    printf("Passed!\n");
    
    printf("Testing my corner cases...\n");
    assert(find_two_chars("9999999", '9', '9') == 0);
    assert(find_two_chars("9999999", '9', ':') == 2);
    assert(find_two_chars("aqqaqa", 'a', 'q') == 0);
    assert(find_two_chars("aqa", 'q', 'a') == 0);
    assert(find_two_chars("fa", 'a', 'f') == 1);
    int i;
    char * large_string = (char*) malloc(2048*sizeof(char));
    for (i=0; i<2048; i++)
        large_string[i] = '.';
    assert(find_two_chars(large_string, 'a', 'b') == 2);
    printf("Passed!\n");
}