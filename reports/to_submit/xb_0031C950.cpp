// bin: xb
// va: 0x0031C950
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C950 (0x0031C950, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043E28C[];
extern "C" char DAT_0043E298[];
extern "C" Object DAT_0048F920;
extern "C" char sub_001EE220[];

void __cdecl sub_0031C950(void)
{
    DAT_0048F920.sub_0006F880((int)DAT_0043E298, (int)DAT_0043E28C, (int)sub_001EE220, 0, 2, 2);
}
