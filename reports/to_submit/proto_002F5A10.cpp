// bin: proto
// va: 0x002F5A10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5A10 (Proto 0x002F5A10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419508;
extern "C" int DAT_0041950C;
extern "C" unsigned short DAT_00419514;
extern "C" unsigned short DAT_00419516;
extern "C" unsigned short DAT_0041951A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5A10(void)
{
    DAT_00419508 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041950C);
    DAT_0041950C = 0;
    DAT_00419514 = 0;
    DAT_00419516 = 0;
    DAT_0041951A = 0;
    return 0;
}
