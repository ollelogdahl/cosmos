//
// Created by olle on 2020-08-16.
//

#include "emulator.h"
#include "cpu.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

byte memory[0x1000];            // 4096 bytes of general rom and ram memory
bool screen_buffer[0x3000];     // 128x96 bits.
register_set cpu;
byte keyboard_state;

SDL_Renderer *renderer;

static const unsigned PIXEL_SIZE = 5;

bool running;


byte load_keyboard_state();

const char* basename(const char* path) {
    for(size_t i = strlen(path) - 1; i; i--) {
        if (path[i] == '/') {
            return &path[i+1];
        }
    }
    return path;
}

void print_memory() {
    printf("0x000: ");
    for (unsigned i = 0; i < 0x1000; ++i) {
        if(i % 16 == 0 && i) printf("\n0x%03x: ", i);
        printf("%02x ", memory[i]);
    }
    printf("\n");
}

int emulator_load_program(const char *file) {
    printf("Loading rom %s\n", basename(file));

    // initialize cpu, loading fontset
    memcpy(memory, fontset, sizeof(fontset));
    // set program counter to start of program
    cpu.pc.WORD = CPU_PROGRAM_START_OFFSET;
    cpu.is_running = true;


    FILE *f = fopen(file, "rb");
    if (f == NULL) {
        printf("Couldn't open file (%s)\n", strerror(errno));
        return 1;
    }

    unsigned max_size = 0x1000 - CPU_PROGRAM_START_OFFSET;
    fseek(f, 0, SEEK_END);
    unsigned size = ftell(f);
    rewind(f);
    printf("[%u bytes]\n", size);

    if (size > max_size) {
        printf("Rom size exceeds %u bytes. Can't load into memory.\n", max_size);
        return 1;
    }

    fread(memory+CPU_PROGRAM_START_OFFSET, 1, max_size, f);
    fclose(f);

    // Add an emergency quit after program
    memory[CPU_PROGRAM_START_OFFSET + size] = 0x0F;
    memory[CPU_PROGRAM_START_OFFSET + size + 1] = 0xEF;
    return 0;
}

void emulator_start() {
    SDL_Event event;
    running = true;
    while (running) {
        emulator_handle_events();
        if(cpu.is_running) cpu_step();
        if (cpu.need_repaint) emulator_render_buffer();
    }
}

int emulator_initialize_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init error: %s", SDL_GetError());
        return 1;
    }

    // Open window
    SDL_Window *win = SDL_CreateWindow("cosmos Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       128 * PIXEL_SIZE, 96 * PIXEL_SIZE, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        printf("SDL_CreateWindow error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, 255);
    SDL_RenderClear(renderer);

    printf("SDL Initialized.\n");
    return 0;
}

void emulator_render_buffer() {
    cpu.need_repaint = false;

    SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, fg.r, fg.g, fg.b, 255);

    for(unsigned i = 0; i < 96*128; ++i) {
        if(!screen_buffer[i]) continue;

        int x = i % 128;
        int y = (i / 128);

        SDL_Rect rect = {
                PIXEL_SIZE * x,
                PIXEL_SIZE * y,
                PIXEL_SIZE,
                PIXEL_SIZE
        };
        SDL_RenderFillRect(renderer, &rect);
    }
    SDL_RenderPresent(renderer);
}

void emulator_handle_events() {
    SDL_Event event;
    byte s = 0x00;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_p) cpu.is_running = !cpu.is_running;

                if(event.key.keysym.sym == SDLK_w) s |= 0x01;
                if(event.key.keysym.sym == SDLK_a) s |= 0x02;
                if(event.key.keysym.sym == SDLK_s) s |= 0x04;
                if(event.key.keysym.sym == SDLK_d) s |= 0x08;
                if(event.key.keysym.sym == SDLK_x) s |= 0x10;
                if(event.key.keysym.sym == SDLK_1) s |= 0x20;
                if(event.key.keysym.sym == SDLK_2) s |= 0x40;
                if(event.key.keysym.sym == SDLK_3) s |= 0x80;
                break;
            case SDL_QUIT: running = false;
        }
    }
    keyboard_state = s;
}
