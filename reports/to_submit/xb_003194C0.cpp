// bin: xb
// va: 0x003194C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003194C0 (0x003194C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043403C[];
extern "C" Object DAT_0048C168;
extern "C" char sub_001896C0[];

void __cdecl sub_003194C0(void)
{
    DAT_0048C168.sub_0006F830(0, (int)DAT_0043403C, (int)sub_001896C0, 0, 1, 2);
}
