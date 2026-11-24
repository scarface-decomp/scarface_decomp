// bin: xb
// va: 0x003118A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003118A0 (0x003118A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_004190C0[];
extern "C" Object DAT_00467FA8;
extern "C" char sub_00011340[];

void __cdecl sub_003118A0(void)
{
    DAT_00467FA8.sub_0006F740(0, (int)DAT_004190C0, (int)sub_00011340, 0, 3, 3);
}
