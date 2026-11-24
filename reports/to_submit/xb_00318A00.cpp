// bin: xb
// va: 0x00318A00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318A00 (0x00318A00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00430210[];
extern "C" char DAT_0043021C[];
extern "C" Object DAT_0048B890;
extern "C" char sub_00178680[];

void __cdecl sub_00318A00(void)
{
    DAT_0048B890.sub_0006F880((int)DAT_0043021C, (int)DAT_00430210, (int)sub_00178680, 0, 2, 2);
}
