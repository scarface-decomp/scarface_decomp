// bin: proto
// va: 0x002F74B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F74B0 (Proto 0x002F74B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00425D7C;
extern "C" int DAT_00425D80;
extern "C" unsigned short DAT_00425D88;
extern "C" unsigned short DAT_00425D8A;
extern "C" unsigned short DAT_00425D8E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F74B0(void)
{
    DAT_00425D7C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00425D80);
    DAT_00425D80 = 0;
    DAT_00425D88 = 0;
    DAT_00425D8A = 0;
    DAT_00425D8E = 0;
    return 0;
}
