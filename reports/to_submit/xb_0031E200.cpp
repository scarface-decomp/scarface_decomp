// bin: xb
// va: 0x0031E200
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E200 (0x0031E200, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0044C560[];
extern "C" char DAT_0044C56C[];
extern "C" Object DAT_00490814;
extern "C" char sub_00216400[];

void __cdecl sub_0031E200(void)
{
    DAT_00490814.sub_0006F740((int)DAT_0044C56C, (int)DAT_0044C560, (int)sub_00216400, 0, 2, 2);
}
