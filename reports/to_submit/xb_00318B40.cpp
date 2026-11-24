// bin: xb
// va: 0x00318B40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318B40 (0x00318B40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430378[];
extern "C" char DAT_0043038C[];
extern "C" Object DAT_0048BA48;
extern "C" char sub_00178770[];

void __cdecl sub_00318B40(void)
{
    DAT_0048BA48.sub_0006F830((int)DAT_0043038C, (int)DAT_00430378, (int)sub_00178770, 0, 3, 3);
}
