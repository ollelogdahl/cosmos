//
// Created by olle on 2020-08-16.
//

#include "cpu.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void op_return_from_subroutine() {
    // jump back in stack, then proceed to next instr
    cpu.pc.WORD = cpu.stack[cpu.sp].WORD;
    cpu.stack[cpu.sp].WORD = 0;
    cpu.sp--;
}

void op_jump(word addr) {
    cpu.pc.WORD = CPU_PROGRAM_START_OFFSET + addr.WORD - 2;
}

void op_call_subroutine(word addr) {
    cpu.sp++;
    cpu.stack[cpu.sp] = cpu.pc;
    cpu.pc.WORD = CPU_PROGRAM_START_OFFSET + addr.WORD - 2;
}

void op_skip_if_equal(byte reg, byte val) {
    if(cpu.v[reg] == val) cpu.pc.WORD += 2;
}

void op_skip_if_not_equal(byte reg, byte val) {
    if(cpu.v[reg] != val) cpu.pc.WORD += 2;
}

void op_skip_if_equal_reg(byte reg1, byte reg2) {
    if(cpu.v[reg1] == cpu.v[reg2]) cpu.pc.WORD += 2;
}

void op_load(byte reg, byte val) {
    cpu.v[reg] = val;
}

void op_add(byte reg, byte val) {
    cpu.v[reg] += val;
}

void op_load_reg(byte reg1, byte reg2) {
    cpu.v[reg1] = cpu.v[reg2];
}

void op_or_reg(byte reg1, byte reg2) {
    cpu.v[reg1] = cpu.v[reg1] | cpu.v[reg2];
}

void op_and_reg(byte reg1, byte reg2) {
    cpu.v[reg1] = cpu.v[reg1] & cpu.v[reg2];
}

void op_xor_reg(byte reg1, byte reg2) {
    cpu.v[reg1] = cpu.v[reg1] ^ cpu.v[reg2];
}

void op_add_reg(byte reg1, byte reg2) {
    int sum = cpu.v[reg1] + cpu.v[reg2];
    if (sum > 255) cpu.v[0xF] = 1;
    else cpu.v[0xF] = 0;
    cpu.v[reg1] = sum & 0xFFFF;
}

void op_sub_reg(byte reg1, byte reg2) {
    if (cpu.v[reg1] > cpu.v[reg2]) cpu.v[0xF] = 1;
    else cpu.v[0xF] = 0;
    cpu.v[reg1] -= cpu.v[reg2];
}

void op_shr_reg(byte reg1, byte reg2) {
    cpu.v[0xF] = cpu.v[reg2] & 0x01;
    cpu.v[reg1] = cpu.v[reg2] >> 1;
}

void op_subn_reg(byte reg1, byte reg2) {
    cpu.v[0xF] = (cpu.v[reg2] > cpu.v[reg1]) ? 1 : 0;
    cpu.v[reg1] = cpu.v[reg2] - cpu.v[reg1];
}

void op_shl_reg(byte reg1, byte reg2) {
    cpu.v[0xF] = cpu.v[reg2] & 0x01;
    cpu.v[reg1] = cpu.v[reg2] << 1;
}

void op_skip_if_not_equal_reg(byte reg1, byte reg2) {
    if(cpu.v[reg1] != cpu.v[reg2]) cpu.pc.WORD += 2;
}

void op_load_i(word addr) {
    cpu.i.WORD = CPU_PROGRAM_START_OFFSET + addr.WORD;
}

void op_jump_offset(word addr) {
    cpu.pc.WORD = CPU_PROGRAM_START_OFFSET + cpu.v[0x0] + addr.WORD - 2;
}

void op_rnd_reg(byte reg, byte val) {
    int r = rand() % 256;
    cpu.v[reg] = r & val;
}

void op_read_delay(byte x) {
    cpu.v[x] = cpu.dt;
}

void op_load_delay(byte x) {
    cpu.dt = cpu.v[x];
}

void op_add_i(byte reg) {
    cpu.i.WORD = cpu.i.WORD + cpu.v[reg];
}

void op_load_font(byte x) {
    cpu.i.WORD = cpu.v[x] * 5;
}

void op_load_bcd(byte x) {
    memory[cpu.i.WORD] = cpu.v[x] / 100;
    memory[cpu.i.WORD+1] = (cpu.v[x] / 10) % 10;
    memory[cpu.i.WORD+2] = cpu.v[x] % 10;
}

void op_memsave_reg(byte x) {
    for(unsigned i = 0; i < x; ++i)
        memory[cpu.i.WORD + x] = cpu.v[i];
}

void op_memload_reg(byte x) {
    for(unsigned i = 0; i < x; ++i)
        cpu.v[i] = memory[cpu.i.WORD+i];
}

void op_draw(byte x, byte y, byte nib) {
    // set collision flag
    cpu.v[0xF] = 0;

    // blit sprite at I reg to Vx, Vy
    for(unsigned h = 0; h < nib; ++h) {
        // calculate offset to start of row
        unsigned row_start = (cpu.v[y] + h) * 128 + cpu.v[x];

        // read a row of the sprite (always 1 byte)
        byte sprite = memory[cpu.i.WORD + h];
        for(unsigned v = 0; v < 8; ++v) {
            // reads the v bit from sprite byte (left to right)
            byte offsetMask = 0x80 >> v;
            bool spritePixel = (sprite & offsetMask);

            if(spritePixel && screen_buffer[row_start + v])
                cpu.v[0xF] = 1;

            // XOR the new pixel value with the old
            screen_buffer[row_start + v] ^= spritePixel;
        }
    }
    cpu.need_repaint = true;
}

void op_skip_if_key(byte k) {
    cpu.is_running = false;

    auto c = ( keyboard_state >> k ) & 0x01;
}

void op_skip_if_not_key(byte k) {
    cpu.is_running = false;
}

void op_clear_display() {
    memset(screen_buffer, 0, sizeof(screen_buffer));
    cpu.need_repaint = true;
}

void op_update_display() {
    cpu.is_running = false;
}

void op_quit() {
    cpu.is_running = false;
}

void op_await_key() {
    if(keyboard_state == 0) {
        cpu.pc.WORD -= 2;
        cpu.interrupt = true;
    }
}
