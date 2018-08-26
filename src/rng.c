#include "defs.h"

double rng(double min, double max) {
    return rand() % (max + 1 - min) + min;
}