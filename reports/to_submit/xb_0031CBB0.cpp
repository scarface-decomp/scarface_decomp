// bin: xb
// va: 0x0031CBB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CBB0 (0x0031CBB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E800[];
extern "C" char DAT_0043E808[];
extern "C" Object DAT_0048FB88;
extern "C" char sub_001EE880[];

void __cdecl sub_0031CBB0(void)
{
    DAT_0048FB88.sub_0006F830((int)DAT_0043E808, (int)DAT_0043E800, (int)sub_001EE880, 0, 3, 3);
}
