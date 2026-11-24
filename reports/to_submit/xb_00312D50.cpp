// bin: xb
// va: 0x00312D50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312D50 (0x00312D50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041C1FC[];
extern "C" Object DAT_0047476C;
extern "C" char sub_0002EB30[];

void __cdecl sub_00312D50(void)
{
    DAT_0047476C.sub_0006F740(0, (int)DAT_0041C1FC, (int)sub_0002EB30, 0, 1, 1);
}
