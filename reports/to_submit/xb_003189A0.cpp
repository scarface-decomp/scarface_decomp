// bin: xb
// va: 0x003189A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003189A0 (0x003189A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043019C[];
extern "C" char DAT_004301B0[];
extern "C" Object DAT_0048B80C;
extern "C" char sub_001785E0[];

void __cdecl sub_003189A0(void)
{
    DAT_0048B80C.sub_0006F880((int)DAT_004301B0, (int)DAT_0043019C, (int)sub_001785E0, 0, 2, 2);
}
