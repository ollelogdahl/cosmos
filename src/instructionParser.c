//
// Created by olle on 2020-08-16.
//

#include "asprintf.h"

#include "instructionParser.h"
#include <stdio.h>

#include <stdarg.h>
#include <string.h>

char *opcode_to_string(const word code) {
    word nnn = {code.WORD & 0x0FFF};
    byte kk = code.BYTE.low;

    byte x = (code.WORD & 0x0F00) >> 8;
    byte y = (code.WORD & 0x00F0) >> 4;
    byte n = (code.WORD & 0x000F);

    char *str;
    enum OPCODE op = get_opcode(code);
    switch (op) {
        case UNKNOWN: return "???";
        case NOP: return "NOP";
        case CLEAR: return "CLS";
        case DISPLAY: return "DISP";
        case RETURN: return "RET";
        case AWAIT_KEY: return "AWT";
        case QUIT: return "QUIT";

        case JUMP: asprintf(&str, "JMP $%03X", nnn); break;
        case CALL: asprintf(&str, "CALL $%03X", nnn); break;

        case LOAD: asprintf(&str, "MOV V%x, 0x%02X", x, kk); break;

        case ADD: asprintf(&str, "ADD V%x, 0x%02X", x, kk); break;
        case SKIP_EQUAL: asprintf(&str, "SE V%x, 0x%02X", x, kk); break;
        case SKIP_NOT_EQUAL: asprintf(&str, "SNE V%x, 0x%02X", x, kk); break;
        case RANDOM: asprintf(&str, "RNG V%x, 0x%02X", x, kk); break;

        case LOAD_REG: asprintf(&str, "MOV V%x, V%x", x, y); break;
        case SKIP_EQUAL_REG: asprintf(&str, "SE V%x, V%x", x, y); break;
        case SKIP_NOT_EQUAL_REG: asprintf(&str, "SNE V%x, V%x", x, y); break;
        case OR: asprintf(&str, "OR V%x, V%x", x, y); break;
        case AND: asprintf(&str, "AND V%x, V%x", x, y); break;
        case XOR: asprintf(&str, "XOR V%x, V%x", x, y); break;
        case ADD_REG: asprintf(&str, "ADD V%x, V%x", x, y); break;
        case SUB_REG: asprintf(&str, "SUB V%x, V%x", x, y); break;
        case SUBN: asprintf(&str, "SUBN V%x, V%x", x, y); break;
        case SHR: asprintf(&str, "SHR V%x, V%x", x, y); break;
        case SHL: asprintf(&str, "SHL V%x, V%x", x, y); break;

        case LOAD_I: asprintf(&str, "MOV I, 0x%03X", nnn); break;
        case JUMP_OFFSET: asprintf(&str, "JP $%03X", nnn); break;

        case DRAW: asprintf(&str, "DRW V%x, V%x, 0x%X", x, y, n); break;

        case SKIP_KEY: asprintf(&str, "SE K%X", x); break;
        case SKIP_NOT_KEY: asprintf(&str, "SNE K%X", x); break;
        case LOAD_DELAY: asprintf(&str, "MOV D, V%x", x); break;
        case READ_DELAY: asprintf(&str, "MOV V%x, D", x); break;
        case ADD_I: asprintf(&str, "ADD I, V%x", x); break;
        case LOAD_GLYPH: asprintf(&str, "FNT V%x", x); break;
        case LOAD_BCD: asprintf(&str, "BCD V%x", x); break;
        case MEMLOAD_REG: asprintf(&str, "MOV I, V%x", x); break;
        case MEMSAVE_REG: asprintf(&str, "MOV V%x, I", x); break;
    };

    if (str == "") return "PARSER NOT IMPL";
}

enum OPCODE get_opcode(const word code) {
    byte V = code.WORD >> 12;
    byte kk = code.BYTE.low;
    byte n = (code.WORD & 0x000F);

    if(code.WORD == 0x0000) return NOP;
    if(code.WORD == 0x00A1) return CLEAR;
    if(code.WORD == 0x00A2) return DISPLAY;
    if(code.WORD == 0x00FF) return RETURN;
    if(code.WORD == 0x0EAA) return AWAIT_KEY;
    if(code.WORD == 0x0FEF) return QUIT;

    switch (V) {
        case 0x1: return JUMP;
        case 0x2: return CALL;
        case 0x3: return LOAD;
        case 0x4: return ADD;
        case 0x5: return SKIP_EQUAL;
        case 0x6: return SKIP_NOT_EQUAL;
        case 0x7: switch (n) {
            case 0x0: return LOAD_REG;
            case 0x1: return SKIP_EQUAL_REG;
            case 0x2: return SKIP_NOT_EQUAL_REG;
            case 0x3: return OR;
            case 0x4: return AND;
            case 0x5: return XOR;
            case 0x6: return ADD_REG;
            case 0x7: return SUB_REG;
            case 0x8: return SUBN;

            case 0xA: return SHR;
            case 0xB: return SHL;
        }; break;
        case 0x8: return LOAD_I;
        case 0x9: return JUMP_OFFSET;
        case 0xA: return DRAW;
        case 0xB: switch (kk) {
            case 0x01: return SKIP_KEY;
            case 0x02: return SKIP_NOT_KEY;
            case 0x03: return LOAD_DELAY;
            case 0x04: return READ_DELAY;
            case 0x05: return ADD_I;

            case 0x0F: return LOAD_GLYPH;
            case 0x10: return LOAD_BCD;
            case 0x11: return MEMSAVE_REG;
            case 0x12: return MEMLOAD_REG;
        }; break;
        case 0xC: return RANDOM;
    };
    return UNKNOWN;
}
