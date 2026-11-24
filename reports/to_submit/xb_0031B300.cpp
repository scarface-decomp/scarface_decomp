// bin: xb
// va: 0x0031B300
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B300 (0x0031B300, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00438AB4[];
extern "C" char DAT_00438ACC[];
extern "C" Object DAT_0048EA80;
extern "C" char sub_001C8860[];

void __cdecl sub_0031B300(void)
{
    DAT_0048EA80.sub_0006F830((int)DAT_00438ACC, (int)DAT_00438AB4, (int)sub_001C8860, 0, 3, 3);
}
