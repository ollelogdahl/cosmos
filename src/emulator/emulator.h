//
// Created by olle on 2020-08-16.
//

#ifndef SIMPL8_EMULATOR_H
#define SIMPL8_EMULATOR_H

#include "types.h"

#include <SDL2/SDL.h>

static const SDL_Color bg = {0x29, 0x16, 0x1d};
static const SDL_Color fg = {0xfa, 0x94, 0x95};

// loads a program into memory
int emulator_load_program(const char *file);
int emulator_initialize_sdl();

void emulator_start();
void emulator_render_buffer();
void emulator_handle_events();

void print_memory();

#endif //SIMPL8_EMULATOR_H
