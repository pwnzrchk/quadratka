#include <stdio.h>
#include <math.h>
#include "square.h"
#include "testing.h"

int main (void) {

    if (allTests() == 0) {
        printf("All tests end successful\n");
    } else if (allTests() != 0) {
        printf("Error test N%d", allTests());
    }
    return 0;
}
