// bin: xb
// va: 0x00313B80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313B80 (0x00313B80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041EA1C[];
extern "C" Object DAT_00476DFC;
extern "C" char sub_00068D90[];

void __cdecl sub_00313B80(void)
{
    DAT_00476DFC.sub_0006F830(0, (int)DAT_0041EA1C, (int)sub_00068D90, 0, 1, 1);
}
