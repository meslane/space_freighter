#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

void generatelang(char *filename) {
    FILE *f = fopen(filename, "wb"); /* binary write to file */
    
    char *vowels[] = {
        "i", "e", "a", "u", "o"
    };
    char vowelprobs[] = { /* probabilities of a given vowel being attested */
        93, 68, 99, 87, 68
    };
    
    char *consonants[] = {
        "m", "n", "nn", "ng",                           /* nasals */
        "p", "b", "t", "d", "k", "g", "'",              /* plosives */
        "r",                                            /* taps */
        "bb", "rr",                                     /* trills */
        "ts", "dz", "ch", "j",                          /* affricates */
        "f", "v", "th", "s", "z", "sh", "zh", "x", "h", /* fricatives */
        "w", "l", "y"							        /* approximants */
    };
    char consprobs[] = { /* probabilities of a given consonant being attested */
        95, 81, 49, 56,
        87, 71, 74, 54, 94, 64, 44,
        31,
        1, 38,
        24, 10, 47, 30,
        49, 29, 5, 77, 31, 40, 14, 18, 65,
        84, 66, 88
    };
    
    char i; /* loop variable */
	
    /* make consonant inventory */
    int consize = sizeof(consonants) / sizeof(consonants[0]);
    char *cons_inv[consize]; 
    for (i = 0; i < consize; i++) { /* go through each array element */
        if ((rand() % 100) <= consprobs[i]) {
            fputs(consonants[i], f);
            fputc('\0', f); /* null-terminate each string */
            printf("%s ", consonants[i]);
        }
    }
    
    fputc('\n', f);
    printf("\n");

    /* make vowel inventory */
    char *vowel_inv[5];
    for (i = 0; i < 5; i++) {
        if ((rand() % 100) <= vowelprobs[i]) {
            fputs(vowels[i], f);
            fputc('\0', f); 
            printf("%s ", vowels[i]);
        }  
    }
    
    fputc('\n', f);
    printf("\n"); 
    
    /* get syllable structure */
    char onset = (rand() % 2) + 1; /* number of consonants in onset */
    char coda; /* number of consonants in coda */
    if (onset == 2) {
        coda = 1; /* if two are in onset, one must be in coda */
    }
    else {
        coda = rand() % 2; 
    }
    fputc(onset, f);
    fputc(coda, f);
    
    /* print syllable structure */
    for (i = onset; i != 0; i--) {
        printf("C");
    }
    printf("V");
    for (i = coda; i != 0; i--) {
        printf("C");
    }
}

int generateword(char *filename) { /* BROKEN */
    FILE *f = fopen(filename, "r"); 
    if (f == NULL) {
        printf("File not found");
        return 1;
    }
    
    char c;
    
    int cl = 0;
    int vl = 0;
    
    for(;;) {
        c = fgetc(f);
        printf("%i\n", c);
        if (c == EOF || c == '\n') {
            break;
        }
        cl++;
    }
    
    for(;;) {
        c = fgetc(f);
        if (c == EOF || c == '\n') {
            break;
        }
        vl++;
    }
    
    printf("\n%i %i", cl, vl);
    return 0;
}

int main(int argc, char *argv[]) {
    long a = atoi(argv[1]);
    if (a == 0) {
        srand(time(0));
    }
    else {
        srand(a); 
    }
    generatelang("penis.lang");
    generateword("penis.lang");
    return 0;
}