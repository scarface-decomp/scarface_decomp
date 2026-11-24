// bin: xb
// va: 0x0031A180
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A180 (0x0031A180, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436E68[];
extern "C" char DAT_00436E70[];
extern "C" Object DAT_0048D97C;
extern "C" char sub_001BE270[];

void __cdecl sub_0031A180(void)
{
    DAT_0048D97C.sub_0006F830((int)DAT_00436E70, (int)DAT_00436E68, (int)sub_001BE270, 0, 2, 2);
}
