// bin: xb
// va: 0x003185C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003185C0 (0x003185C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FD60[];
extern "C" char DAT_0042FD6C[];
extern "C" Object DAT_0048B2B8;
extern "C" char sub_00178210[];

void __cdecl sub_003185C0(void)
{
    DAT_0048B2B8.sub_0006F830((int)DAT_0042FD6C, (int)DAT_0042FD60, (int)sub_00178210, 0, 2, 2);
}
