//
// Created by olle on 2020-08-17.
//

#include "../types.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void assemble(char *file) {
    FILE *src = fopen(file, "r");

    FILE *res = fopen(strcat(file, ".asm"), "wb");

    fclose(src);
    fclose(res);
};