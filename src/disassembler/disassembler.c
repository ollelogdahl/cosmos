//
// Created by olle on 2020-08-17.
//
#include "disassembler.h"
#include "../types.h"
#include "../instructionParser.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void disassemble(char *file, char *output) {
    FILE *src = fopen(file, "rb");
    FILE *res = fopen(output, "w");

    char *buffer;
    long size;

    fseek(src, 0, SEEK_END);        // Jump to the end of the file
    size = ftell(src);              // Get the current byte offset in the file
    rewind(src);                    // Jump back to the beginning of the file

    buffer = (char *)malloc(size * sizeof(char)); // Enough memory for the file
    fread(buffer, size, 1, src); // Read in the entire file
    fclose(src); // Close the file

    for(unsigned long i = 0; i < size; i += 2) {
        word opcode;
        opcode.BYTE.high = buffer[i];
        opcode.BYTE.low = buffer[i + 1];

        char *parsed_opcode = opcode_to_string(opcode);
        fputs(parsed_opcode, res);
        fputs("\n", res);
    }
    fclose(res);
};