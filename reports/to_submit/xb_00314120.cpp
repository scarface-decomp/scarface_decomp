// bin: xb
// va: 0x00314120
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314120 (0x00314120, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041F0A0[];
extern "C" Object DAT_0047B238;
extern "C" char sub_00070DA0[];

void __cdecl sub_00314120(void)
{
    DAT_0047B238.sub_0006F740(0, (int)DAT_0041F0A0, (int)sub_00070DA0, 0, 4, 4);
}
