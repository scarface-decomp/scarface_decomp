// bin: xb
// va: 0x0031A260
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A260 (0x0031A260, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437014[];
extern "C" char DAT_0043701C[];
extern "C" Object DAT_0048DA2C;
extern "C" char sub_001BE470[];

void __cdecl sub_0031A260(void)
{
    DAT_0048DA2C.sub_0006F830((int)DAT_0043701C, (int)DAT_00437014, (int)sub_001BE470, 0, 3, 3);
}
