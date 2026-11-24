// bin: xb
// va: 0x0031B280
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B280 (0x0031B280, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00438A68[];
extern "C" Object DAT_0048EA1C;
extern "C" char sub_001C8580[];

void __cdecl sub_0031B280(void)
{
    DAT_0048EA1C.sub_0006F740(0, (int)DAT_00438A68, (int)sub_001C8580, 0, 2, 2);
}
