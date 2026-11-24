// bin: xb
// va: 0x00315340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315340 (0x00315340, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424724[];
extern "C" char DAT_00424730[];
extern "C" Object DAT_00486E9C;
extern "C" char sub_000C9F70[];

void __cdecl sub_00315340(void)
{
    DAT_00486E9C.sub_0006F830((int)DAT_00424730, (int)DAT_00424724, (int)sub_000C9F70, 0, 3, 6);
}
