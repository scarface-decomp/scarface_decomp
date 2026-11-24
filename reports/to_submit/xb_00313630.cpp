// bin: xb
// va: 0x00313630
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313630 (0x00313630, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041DD30[];
extern "C" Object DAT_00475BDC;
extern "C" char sub_00060780[];

void __cdecl sub_00313630(void)
{
    DAT_00475BDC.sub_0006F830(0, (int)DAT_0041DD30, (int)sub_00060780, 0, 2, 2);
}
