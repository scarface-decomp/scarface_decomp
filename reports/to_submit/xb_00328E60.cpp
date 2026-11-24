// bin: xb
// va: 0x00328E60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328E60 (0x00328E60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044C288;
extern "C" int DAT_0044C28C;
extern "C" unsigned short DAT_0044C294;
extern "C" unsigned short DAT_0044C296;
extern "C" unsigned short DAT_0044C29A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328E60(void)
{
    DAT_0044C288 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044C28C);
    DAT_0044C28C = 0;
    DAT_0044C294 = 0;
    DAT_0044C296 = 0;
    DAT_0044C29A = 0;
    return 0;
}
