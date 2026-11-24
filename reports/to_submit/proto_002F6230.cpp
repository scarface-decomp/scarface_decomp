// bin: proto
// va: 0x002F6230
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6230 (Proto 0x002F6230, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041D5A0;
extern "C" int DAT_0041D5A4;
extern "C" unsigned short DAT_0041D5AC;
extern "C" unsigned short DAT_0041D5AE;
extern "C" unsigned short DAT_0041D5B2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6230(void)
{
    DAT_0041D5A0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041D5A4);
    DAT_0041D5A4 = 0;
    DAT_0041D5AC = 0;
    DAT_0041D5AE = 0;
    DAT_0041D5B2 = 0;
    return 0;
}
