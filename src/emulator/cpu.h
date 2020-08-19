//
// Created by olle on 2020-08-16.
//

#ifndef SIMPL8_CPU_H
#define SIMPL8_CPU_H

#include "../types.h"

// The amount of cpu cycles performed before decrementing timer and reading input.
static const unsigned CPU_CYCLES_COUNT = 42;

// Offset for pc when a program is read.
static const unsigned CPU_PROGRAM_START_OFFSET = 0x60; // (128bytes)

static const byte fontset[80] = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

typedef struct {
    word stack[0x20];   // 32 layers of stack
    byte sp;            // stack pointer
    word pc;            // program counter

    word i;             // index register, mostly used for sprite drawing
    byte v[16];         // general registers, v[0xF] used for carry flag
    byte dt;            // delay timer

    bool is_running;
    bool need_repaint;
    bool interrupt;     // if processor should be interrupted, skipping to next i/o.
} register_set;

extern byte memory[0x1000];             // 4096 bytes of general rom and ram memory
extern bool screen_buffer[0x3000];      // 128x96 bits.
extern byte keyboard_state;             // 8 buttons available
extern register_set cpu;

// Perform one step of the cpu.
void cpu_step();
// Performs the instruction at pc and increments pc.
void cpu_cycle();

// executes an opcode
void execute_opcode(word);

// Instruction set
                                                    // 0000 NOP
void op_clear_display();                            // 0001 CLS
void op_update_display();                           // 0002 DISP
void op_return_from_subroutine();                   // 00FF RET
void op_await_key();                                // 0EAA AWT
void op_quit();                                     // 0FEF QUIT

void op_jump(word addr);                            // 1nnn JMP
void op_call_subroutine(word addr);                 // 2nnn CALL
void op_skip_if_equal(byte x, byte val);            // 3xkk SE
void op_skip_if_not_equal(byte x, byte val);    // 4xkk SNE
void op_skip_if_equal_reg(byte x, byte y);      // 5xy0 SE
void op_load(byte x, byte val);                 // 6xkk LD
void op_add(byte x, byte val);                  // 7xkk ADD

void op_load_reg(byte x, byte y);               // 8xy0 LD
void op_or_reg(byte x, byte y);                 // 8xy1 OR
void op_and_reg(byte x, byte y);                    // 8xy2 AND
void op_xor_reg(byte x, byte y);                    // 8xy3 XOR
void op_add_reg(byte x, byte y);                    // 8xy4 ADD
void op_sub_reg(byte x, byte y);                    // 8xy5 SUB
void op_shr_reg(byte x, byte y);                    // 8xy6 SHR
void op_shl_reg(byte x, byte y);                    // 8xy7 SHL
void op_subn_reg(byte x, byte y);                   // 8xyE SUBN

void op_skip_if_not_equal_reg(byte x, byte y);  // 9xy0 SNE
void op_load_i(word addr);                          // Annn LD
void op_jump_offset(word addr);                     // Bnnn JP
void op_rnd_reg(byte x, byte val);                  // Cxkk RND
void op_draw(byte x, byte y, byte nib);             // Dxyn DRW
void op_skip_if_key(byte x);                        // Ex9E SKP
void op_skip_if_not_key(byte x);                    // ExA1 SKNP
void op_read_delay(byte x);                     // Fx07 LD
void op_load_delay(byte x);                     // Fx15 LD
void op_add_i(byte x);                              // Fx1E ADD I, Vx
void op_load_font(byte x);                          // Fx29 FNT Vx
void op_load_bcd(byte x);                           // Fx33 BCD Vx
void op_memsave_reg(byte x);                           // Fx55 LD [I], Vx
void op_memload_reg(byte x);                           // Fx65 LD Vx, [I]

#endif //SIMPL8_CPU_H
