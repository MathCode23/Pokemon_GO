#include "utils.h"
#include <random>
using namespace std;

#include <stdlib.h> // For random(), RAND_MAX

// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long random_at_most(long max) {
    unsigned long
        // max <= RAND_MAX < ULONG_MAX, so this is okay.
        num_bins = (unsigned long)max + 1,
        num_rand = (unsigned long)RAND_MAX + 1,
        bin_size = num_rand / num_bins,
        defect = num_rand % num_bins;

    long x;
    do {
        x = rand(); //ON TRANSFORME RANDOM EN RAND POUR QUE CELA FONCTIONNE CORRECTEMENT !!!
    }
    // This is carefully written not to overflow
    while (num_rand - defect <= (unsigned long)x);

    // Truncated division is intentional
    return x / bin_size;
}
//Le nombre généré dépend de la sid, qui est ici généré par srand(time(NULL)). Autrement dit, la sid dépend de l'heure actuelle.