#include "defs.h"
#include "rng.h"

typedef struct {
    unsigned char r, g, b; 
} pixel;

int randomheightval(void){
    return rand() % 8;
}

float interpolate(float h, float l, float d){ /* find average added value needed for each successive gradient */
    return (h - l) / d; 
}

void generateterrain(int x_size, int y_size, int sep, int sea_level) { 
	char map[x_size][y_size]; /* map array */
	int x, y; /* for navigating FOR loops */
	char a, b; /* interpolation variables */
	float c; /* interpolation constant */
	float d; /* gradient value to successively add for interpolation */
	int i; /* loop value */
	
	memset(map, 0, sizeof(map)); /* set array to all 0s to prevent buggyness */
	
	/* generate lattice points */
	for (y = 0; y < y_size; y++) { /* traverse each y plane */
        for (x = 0; x < x_size; x++) { /* traverse each x plane */
            if (x % sep == 0 && y % sep == 0) { /* make lattice points with separation of 4 */
                map[x][y] = randomheightval();
            }
        }
    }
	
	/* draw in terminal */
	for (y = 0; y < y_size; y++) { 
        for (x = 0; x < x_size; x++) { 
            printf("%i", map[x][y]);
        }
        printf("\n");
    }
	
	/* complete verticals */
	for (y = 0; y < y_size - sep; y++) { /* we don't need the bottom rows of points for this */
        for (x = 0; x < x_size; x++) {
            if (x % sep == 0 && y % sep == 0) { 
                a = map[x][y]; /* get current point */
                b = map[x][y + sep]; /* get point to interpolate to */
                if (a > b) { /* top value is greater so we must subtract */
                    c = interpolate(a, b, sep); 
                    d = c;
                    for (i = y + 1; i < y + sep; i++) { /* gradient filling FOR loop */
                        map[x][i] = a - ceil(d); /* round up */
                        d = d + c;
                    }
                }
                else if (a < b) { /* top value is lesser so we must add */
                    c = interpolate(b, a, sep);
                    d = c;
                    for (i = y + 1; i < y + sep; i++) { 
                        map[x][i] = a + ceil(d);
                        d = d + c;
                    }                 
                }
                else { /* if values are equal, bridge */
                    for (i = y + 1; i < y + sep; i++) {
                        map[x][i] = a;
                    }
                }
            }
        }
    }
	
	/* draw in terminal */
	for (y = 0; y < y_size; y++) { 
        for (x = 0; x < x_size; x++) { 
            printf("%i", map[x][y]);
        }
        printf("\n");
    }
	
	/* complete horizontals */
	for(x = 0; x < x_size - sep; x = x + sep) { /* start at lattices */
        for(y = 0; y < y_size; y++) { /* go down each row */
            char a = map[x][y]; /* get current point */
            char b = map[x + sep][y]; /* get point to interpolate to */
            if (a < b) { /* first value is lesser so we must add */
               c = interpolate(b, a, sep);
               d = c;
               for (i = x + 1; i < x + sep; i++) {
                    map[i][y] = a + ceil(d);   
                    d = d + c;
                }
            }
            else if (a > b) { /* first value is greater so we must subtract */
                c = interpolate(a, b, sep);
                d = c;
                for (i = x + 1; i < x + sep; i++) {
                    map[i][y] = a - ceil(d);
                    d = d + c;
                }
            }
            else {
                for (i= x + 1; i < x + sep; i++) {
                    map[i][y] = a;
                }
            }
        }
    }
	
	/* draw in terminal */
	for (y = 0; y < y_size; y++) { 
        for (x = 0; x < x_size; x++) { 
            printf("%i", map[x][y]);
        }
        printf("\n");
    }
	
	/* write to .ppm */
	FILE *f = fopen("map.ppm", "wb");
	fprintf(f, "P3\n%i %i\n3\n", x_size, y_size); /* file header: 16*16 ppm file with a color depth of 64 total colors */
	for (y = 0; y < y_size; y++) {
		for (x = 0; x < x_size; x++) {
			pixel p;
			switch(map[x][y]) {
				case 0: /* deep water */
					p.r = 0;
					p.g = 1;
					p.b = 3;
					break;
				case 1: /* shallow water */
					p.r = 0;
					p.g = 1;
					p.b = 2;
					break;
				case 2: /* lowlands */
					p.r = 0;
					p.g = 2;
					p.b = 1;
					break;
				case 3: /* foothills */
					p.r = 0;
					p.g = 1;
					p.b = 0;
					break;
				case 4: /* highlands */
					p.r = 1;
					p.g = 1;
					p.b = 0;
					break;
				case 5: /* low mountains */
					p.r = 2;
					p.g = 2;
					p.b = 1;
					break;
				case 6: /* high mountains */
					p.r = 2;
					p.g = 2;
					p.b = 2;
					break;
				case 7: /* mountain peaks */
					p.r = 3;
					p.g = 3;
					p.b = 3;	
					break;					
			}
			fprintf(f, "%i %i %i  ", p.r, p.g, p.b);
		}
		fprintf(f, "\n");
	}	
}

/*
int main(int argc, char *argv[]){
    srand(atoi(argv[4]));
	generateterrain(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), 1);
    return 0;
}
*/