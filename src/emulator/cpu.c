//
// Created by olle on 2020-08-16.
//

#include "cpu.h"
#include "../instructionParser.h"

#include "emulator.h"

#include <stdio.h>

byte load_keyboard_state();

void cpu_step() {
    for(unsigned i = 0; i < CPU_CYCLES_COUNT; ++i)
        if (cpu.is_running && !cpu.interrupt) cpu_cycle();

    cpu.interrupt = false;
    if (cpu.dt > 0) cpu.dt--;
}



void cpu_cycle() {
    word opcode;

    opcode.BYTE.high = memory[cpu.pc.WORD];
    opcode.BYTE.low = memory[cpu.pc.WORD + 1];

    //char *parsed_opcode = opcode_to_string(opcode);
    //printf("v: 0x%02X 0x%02X 0x%02X, ", cpu.v[0], cpu.v[1], cpu.v[2]);
    //printf("i: 0x%03X       ", cpu.i.WORD);
    //qprintf("$%03X: 0x%04X   %s\n", cpu.pc.WORD, opcode.WORD, parsed_opcode);

    execute_opcode(opcode);
    cpu.pc.WORD += 2;
}

void execute_opcode(word code) {
    byte V = code.WORD >> 12;
    word nnn = {code.WORD & 0x0FFF};
    byte kk = code.BYTE.low;

    byte x = (code.WORD & 0x0F00) >> 8;
    byte y = (code.WORD & 0x00F0) >> 4;
    byte n = (code.WORD & 0x000F);

    enum OPCODE op = get_opcode(code);
    switch (op) {
        case UNKNOWN: break;
        case NOP: return;
        case CLEAR: return op_clear_display();
        case DISPLAY: return op_update_display();
        case RETURN: return op_return_from_subroutine();
        case AWAIT_KEY: return op_await_key();
        case QUIT: return op_quit();

        case JUMP: return op_jump(nnn);
        case CALL: return op_call_subroutine(nnn);

        case LOAD: return op_load(x, kk);
        case ADD: return op_add(x, kk);
        case SKIP_EQUAL: return op_skip_if_equal(x, kk);
        case SKIP_NOT_EQUAL: return op_skip_if_not_equal(x, kk);
        case RANDOM: return op_rnd_reg(x, kk);

        case LOAD_REG: return op_load_reg(x, y);
        case SKIP_EQUAL_REG: return op_skip_if_equal_reg(x, y);
        case SKIP_NOT_EQUAL_REG: return op_skip_if_not_equal_reg(x, y);
        case OR: return op_or_reg(x, y);
        case AND: return op_and_reg(x, y);
        case XOR: return op_xor_reg(x, y);
        case ADD_REG: return op_add_reg(x, y);
        case SUB_REG: return op_sub_reg(x, y);
        case SUBN: return op_subn_reg(x, y);
        case SHR: return op_shr_reg(x, y);
        case SHL: return op_shl_reg(x, y);

        case LOAD_I: return op_load_i(nnn);
        case JUMP_OFFSET: return op_jump_offset(nnn);

        case DRAW: return op_draw(x, y, n);

        case SKIP_KEY: return op_skip_if_key(x);
        case SKIP_NOT_KEY: return op_skip_if_not_key(x);
        case LOAD_DELAY: return op_load_delay(x);
        case READ_DELAY: return op_read_delay(x);
        case ADD_I: return op_add_i(x);
        case LOAD_GLYPH: return op_load_font(x);
        case LOAD_BCD: return op_load_bcd(x);
        case MEMLOAD_REG: return op_memload_reg(x);
        case MEMSAVE_REG: return op_memsave_reg(x);
    };

    printf("Error: encountered unrecognized opcode: $%04x\n", code.WORD);
    cpu.is_running = false;
}