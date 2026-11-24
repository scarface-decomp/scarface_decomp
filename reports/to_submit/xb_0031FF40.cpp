// bin: xb
// va: 0x0031FF40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FF40 (0x0031FF40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E448[];
extern "C" Object DAT_004923EC;
extern "C" char sub_00230710[];

void __cdecl sub_0031FF40(void)
{
    DAT_004923EC.sub_0006F830(0, (int)DAT_0044E448, (int)sub_00230710, 0, 1, 1);
}
