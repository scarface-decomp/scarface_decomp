// bin: xb
// va: 0x0031E240
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E240 (0x0031E240, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C59C[];
extern "C" char DAT_0044C5AC[];
extern "C" Object DAT_0049086C;
extern "C" char sub_002164B0[];

void __cdecl sub_0031E240(void)
{
    DAT_0049086C.sub_0006F830((int)DAT_0044C5AC, (int)DAT_0044C59C, (int)sub_002164B0, 0, 4, 4);
}
