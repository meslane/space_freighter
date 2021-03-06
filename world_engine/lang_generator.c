#include "defs.h"
#include "rng.h"

int generatelang(const char *filename) {
    FILE *f = fopen(filename, "wb"); /* binary write to file */
    
    char *vowels[] = {
        "i", "e", "a", "u", "o", 
    };
    char vowelprobs[] = { /* probabilities of a given vowel or diphthong being attested */
        93, 68, 99, 87, 68, 
    };
    
    char *consonants[] = {
        "m", "n", "ny", "ng",                           /* nasals */
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
    
    unsigned char i; 
    
    const int consize = sizeof(consonants) / sizeof(consonants[0]); 
    const int vsize = sizeof(vowels) / sizeof(vowels[0]);
    
    char onset; 
    char coda; 
    
    if (f == NULL) {
        return 1;
    }
    
    /* make consonant inventory */
    for (i = 0; i < consize; i++) { /* go through each array element */
        if (rng(1, 100) <= consprobs[i]) { /* include phoneme if weighted rng result <= its probability value */
            fputs(consonants[i], f);
            fputc('\0', f); /* null-terminate each string */
        }
    }
    
    fputc('\n', f);

    /* make vowel inventory */
    for (i = 0; i < vsize; i++) {
        if (rng(1, 100) <= vowelprobs[i]) {
            fputs(vowels[i], f);
            fputc('\0', f); 
        }  
    }
    
    fputc('\n', f); 
    
    /* get syllable structure */
    onset = rng(1, 2);
    
    if (onset == 2) {
        coda = 1; /* if two are in onset, one must be in coda */
    }
    else {
        coda = rng(0, 1); 
    }
    
    fputc(onset, f);
    fputc(coda, f);
    
    fclose(f);
    
    return 0;
}

char *generateword(const char *filename, char sylnum) {
    FILE *f = fopen(filename, "rb"); 
    
    char c; 
    
    int cl = 0; /* number of consonants/vowels */
    int vl = 0;
    
    unsigned char s = 0; /* string length */
    char stemp[3]; /* temporary array for fetching strings, no sequence of graphemes is longer than 2 + \0 */
    
    char **cons = NULL; /* arrays for storing vowels and consonants */
    char **vowels = NULL;
    
    char onset; 
    char coda;
    
    int i; 
    
    static char word[256]; 
    
    if (f == NULL) {
        return NULL;
    }
    
    while((c = fgetc(f)) != EOF) { /* put consonants into array */
        if (c == '\n') {
            break;
        }
        
        stemp[s] = c; /* put char into string array */
        s++;
        
        if (c == '\0') { 
            s = 0;
            cl++;
            
            cons = (char **) realloc(cons, cl * sizeof(char*)); /* resize array as phonemes are added */
            cons[cl - 1] = (char *) malloc(3 * sizeof(char)); 
            strcpy(cons[cl - 1], stemp); 
        }
    }

    while((c = fgetc(f)) != EOF) {
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
            strcpy(vowels[vl - 1], stemp);            
        }
    }
    
    onset = fgetc(f);
    coda = fgetc(f);
    
    word[0] = '\0';
    
    while(sylnum > 0) { /* make word */
        for (i = 1; i <= rng(0, onset); i++) { 
            strcat(word, cons[rng(0, cl - 1)]); 
        }
        
        strcat(word, vowels[rng(0, vl - 1)]);
        
        for (i = 1; i <= rng(0, coda); i++) { 
            strcat(word, cons[rng(0, cl - 1)]); 
        }
        sylnum--;
    } 
    
    /* free allocated memory and close file */ 
    for (i = 0; i < cl; i++) { 
        free(cons[i]);
    }
    for (i = 0; i < vl; i++) {
        free(vowels[i]);
    }
    
    free(cons);
    free(vowels);
    
    fclose(f);
    
    return word;
}

/*
int main(int argc, char *argv[]) {
    long a = atoi(argv[1]);
    char i;
    
    if (a == 0) {
        srand(time(0));
    }
    else {
        srand(a); 
    }
    
    generatelang("b.lang");
    
    for (i = 0; i < 10; i++) {
        printf("%s ", generateword("b.lang", rng(1,4)));
    }
    
    return 0;
}
*/