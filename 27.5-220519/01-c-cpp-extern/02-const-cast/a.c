#include "a.h"
#include <stdio.h>

void print_ints(int *arr, int len) {  // Old-school C: do not care about const
    for (int i = 0; i < len; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");
}
