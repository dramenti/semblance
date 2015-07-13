#include "semcall.h"
#include "globals.h"
#include <stdio.h>

void semcall(int call_id) {
    if (call_id == 1) {
        printf("%d\n", reg[90]); 
    }
    else if (call_id == 10) {
        printf("Enter an integer: ");
        scanf("%d", reg+91);
    }
}
