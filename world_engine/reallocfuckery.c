#include <stdio.h>
#include <stdlib.h>

int main (void) {
    char **array = NULL;
    char a = 0;
    
    while(1) {
        a++;
        array = (char **) realloc(array, a * sizeof(char*));
        if (array == NULL) {
            printf("you fucked up\n"); /* returns this for me */
            return 1;
        }
        if (a > 5) {
            printf("you didn't fuck up\n");
            break; /* cuz we know it worked */
        }
    }
    free(array);
    return 0;
}