#include "terrain_generator.h"
#include "lang_generator.h"
#include "defs.h"

int main(int argc, char *argv[]) {
    long a = atoi(argv[1]);
    
    if (a == 0) {
        srand(time(0));
    }
    else {
        srand(a); 
    }
    
    generateterrain(16, 16, 4, 1);
    generatelang("l.lang");
}