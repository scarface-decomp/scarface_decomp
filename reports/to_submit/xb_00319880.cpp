// bin: xb
// va: 0x00319880
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319880 (0x00319880, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00435F60[];
extern "C" char DAT_00435F68[];
extern "C" Object DAT_0048D1EC;
extern "C" char sub_001BC890[];

void __cdecl sub_00319880(void)
{
    DAT_0048D1EC.sub_0006F830((int)DAT_00435F68, (int)DAT_00435F60, (int)sub_001BC890, 0, 3, 3);
}
