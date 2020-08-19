//
// Created by olle on 2020-08-16.
//

#ifndef SIMPL8_INSTRUCTIONPARSER_H
#define SIMPL8_INSTRUCTIONPARSER_H

#include "types.h"

// Converts a word instruction into asm (1510 -> JMP 0x510)
char *opcode_to_string(const word code);
enum OPCODE get_opcode(const word code);

#endif //SIMPL8_INSTRUCTIONPARSER_H
