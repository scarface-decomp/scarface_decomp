// bin: proto
// va: 0x002F5B10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5B10 (Proto 0x002F5B10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041993C;
extern "C" int DAT_00419940;
extern "C" unsigned short DAT_00419948;
extern "C" unsigned short DAT_0041994A;
extern "C" unsigned short DAT_0041994E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5B10(void)
{
    DAT_0041993C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419940);
    DAT_00419940 = 0;
    DAT_00419948 = 0;
    DAT_0041994A = 0;
    DAT_0041994E = 0;
    return 0;
}
