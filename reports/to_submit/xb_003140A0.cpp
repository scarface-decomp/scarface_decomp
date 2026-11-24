// bin: xb
// va: 0x003140A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003140A0 (0x003140A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041F074[];
extern "C" Object DAT_0047B188;
extern "C" char sub_00070D40[];

void __cdecl sub_003140A0(void)
{
    DAT_0047B188.sub_0006F740(0, (int)DAT_0041F074, (int)sub_00070D40, 0, 2, 0);
}
