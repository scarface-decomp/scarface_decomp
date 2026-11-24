// bin: xb
// va: 0x0031E3C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E3C0 (0x0031E3C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C730[];
extern "C" char DAT_0044C740[];
extern "C" Object DAT_00490A7C;
extern "C" char sub_00216070[];

void __cdecl sub_0031E3C0(void)
{
    DAT_00490A7C.sub_0006F830((int)DAT_0044C740, (int)DAT_0044C730, (int)sub_00216070, 0, 3, 3);
}
