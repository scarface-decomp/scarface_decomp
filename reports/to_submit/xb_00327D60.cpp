// bin: xb
// va: 0x00327D60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327D60 (0x00327D60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004440F0;
extern "C" int DAT_004440F4;
extern "C" unsigned short DAT_004440FC;
extern "C" unsigned short DAT_004440FE;
extern "C" unsigned short DAT_00444102;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327D60(void)
{
    DAT_004440F0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004440F4);
    DAT_004440F4 = 0;
    DAT_004440FC = 0;
    DAT_004440FE = 0;
    DAT_00444102 = 0;
    return 0;
}
