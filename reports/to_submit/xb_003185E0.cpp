// bin: xb
// va: 0x003185E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003185E0 (0x003185E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FD7C[];
extern "C" char DAT_0042FD88[];
extern "C" Object DAT_0048B2E4;
extern "C" char sub_00178220[];

void __cdecl sub_003185E0(void)
{
    DAT_0048B2E4.sub_0006F830((int)DAT_0042FD88, (int)DAT_0042FD7C, (int)sub_00178220, 0, 2, 2);
}
