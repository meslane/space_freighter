#include "defs.h"

int rng(const int min, const int max) {
    return (rand() % (max + 1 - min)) + min;
}