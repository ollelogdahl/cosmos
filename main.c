#include "src/emulator/emulator.h"
#include "src/disassembler/disassembler.h"

int main(const int argc, const char *argv[]) {
    emulator_initialize_sdl();

    int status = emulator_load_program(argv[1]);
    if (status > 0) return 1;

    emulator_start();
    return 0;
}
