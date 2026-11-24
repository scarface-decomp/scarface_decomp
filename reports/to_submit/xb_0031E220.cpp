// bin: xb
// va: 0x0031E220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E220 (0x0031E220, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C57C[];
extern "C" char DAT_0044C58C[];
extern "C" Object DAT_00490840;
extern "C" char sub_00216450[];

void __cdecl sub_0031E220(void)
{
    DAT_00490840.sub_0006F830((int)DAT_0044C58C, (int)DAT_0044C57C, (int)sub_00216450, 0, 4, 4);
}
