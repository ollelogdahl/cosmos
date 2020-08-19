//
// Created by olle on 2020-08-16.
//

#ifndef SIMPL8_TYPES_H
#define SIMPL8_TYPES_H

#include <stdbool.h>

typedef unsigned char byte;
typedef union {
    unsigned short WORD;
    struct {
        byte low, high;
    } BYTE;
} word;

enum OPCODE {
    // Rule VVVV
    UNKNOWN,
    NOP,
    CLEAR,
    DISPLAY,
    RETURN,
    QUIT,

    // Rule Vnnn
    JUMP,
    CALL,

    // Rule Vxkk
    LOAD,
    ADD,
    SKIP_EQUAL,
    SKIP_NOT_EQUAL,

    // Rule VxyV
    LOAD_REG,
    SKIP_EQUAL_REG,
    SKIP_NOT_EQUAL_REG,
    OR,
    AND,
    XOR,
    ADD_REG,
    SUB_REG,
    SUBN,
    SHR,
    SHL,
    RANDOM,

    // Rule Vnnn
    LOAD_I,
    JUMP_OFFSET,

    // Rule Vxyn
    DRAW,

    // Rule VxVV
    SKIP_KEY,
    SKIP_NOT_KEY,
    AWAIT_KEY,
    LOAD_DELAY,
    READ_DELAY,
    ADD_I,
    LOAD_GLYPH,
    LOAD_BCD,
    MEMSAVE_REG,
    MEMLOAD_REG
};

#endif //SIMPL8_TYPES_H
