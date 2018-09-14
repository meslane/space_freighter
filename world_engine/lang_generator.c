#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

int generatelang(char *filename) {
    FILE *f = fopen(filename, "wb"); /* binary write to file */
    
    char *vowels[] = {
        "i", "e", "a", "u", "o", 
    };
    char vowelprobs[] = { /* probabilities of a given vowel or diphthong being attested */
        93, 68, 99, 87, 68, 
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
    
    int consize = sizeof(consonants) / sizeof(consonants[0]); /* sizes of vowel and consonant arrays */
    int vsize = sizeof(vowels) / sizeof(vowels[0]);
    
    char *cons_inv[consize]; /* array for writing consonants to file */
    
    char *vowel_inv[vsize]; /* array for writing vowels to file */
    
    char onset = (rand() % 2) + 1; /* number of consonants in onset */
    char coda; /* number of consonants in coda */
    
    if (f == NULL) {
        printf("File not found");
        return 1;
    }
    
    /* make consonant inventory */
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
    
    for (i = 0; i < vsize; i++) {
        if ((rand() % 100) <= vowelprobs[i]) {
            fputs(vowels[i], f);
            fputc('\0', f); 
            printf("%s ", vowels[i]);
        }  
    }
    
    fputc('\n', f);
    printf("\n"); 
    
    /* get syllable structure */
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
    
    fclose(f);
    
    return 0;
}

int generateword(char *filename) { /*  TODO; malloc into array of strings */
    FILE *f = fopen(filename, "rb"); 
    
    char c; /* char grabbed from file scan */
    
    int cl = 0; /* number of consonants/vowels */
    int vl = 0;
    
    char s = 0; /* string length */
    char stemp[3]; /* temporary array for fetching strings, no sequence of graphemes is longer than 2 + \0 */
    
    char **cons = NULL; /* arrays for storing vowels and consonants */
    char **vowels = NULL;
    
    int i; /* loop variable */
    
    if (f == NULL) {
        printf("File not found");
        return 1;
    }
    
    while((c = fgetc(f)) != EOF) { /* put consonants into array */
        if (c == '\n') {
            break;
        }
        
        stemp[s] = c; /* put char into string array */
        s++;
        
        if (c == '\0') { /* on end of string */
            s = 0;
            cl++;
            
            cons = (char **) realloc(cons, cl * sizeof(char*)); /* reallocate for each array length */
            cons[cl - 1] = (char *) malloc(3 * sizeof(char)); /* allocate for each string */
            strncpy(cons[cl - 1], stemp, 3); /* write to string */
        }
    }

    while((c = fgetc(f)) != EOF) { /* find number of strings in vowel inventory */
        if (c == '\n') {
            break;
        }
        
        stemp[s] = c; 
        s++;
        
        if (c == '\0') {
            s = 0;
            vl++;
            
            vowels = (char **) realloc(vowels, vl * sizeof(char*));
            vowels[vl - 1] = (char *) malloc(3 * sizeof(char));
            strncpy(vowels[vl - 1], stemp, 3);            
        }
    }
    
    printf("\n%i %i\n", cl, vl);
    
    fclose(f);
    
    for (i = 0; i < cl; i++) { /* free each array index first */
        printf("%s ", cons[i]);
        free(cons[i]);
    }
    
    printf("\n");
    
    for (i = 0; i < vl; i++) {
        printf("%s ", vowels[i]);
        free(vowels[i]);
    }
    
    free(vowels);
    free(cons);
    
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
    generatelang("a.lang");
    generateword("a.lang");
    return 0;
}