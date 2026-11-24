// bin: proto
// va: 0x002F6BF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6BF0 (Proto 0x002F6BF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421428;
extern "C" int DAT_0042142C;
extern "C" unsigned short DAT_00421434;
extern "C" unsigned short DAT_00421436;
extern "C" unsigned short DAT_0042143A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6BF0(void)
{
    DAT_00421428 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0042142C);
    DAT_0042142C = 0;
    DAT_00421434 = 0;
    DAT_00421436 = 0;
    DAT_0042143A = 0;
    return 0;
}
