// bin: xb
// va: 0x0031D390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D390 (0x0031D390, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00440CA8[];
extern "C" char DAT_00440CB8[];
extern "C" Object DAT_00490364;
extern "C" char sub_001FEC40[];

void __cdecl sub_0031D390(void)
{
    DAT_00490364.sub_0006F790((int)DAT_00440CB8, (int)DAT_00440CA8, (int)sub_001FEC40, 0, 2, 2);
}
