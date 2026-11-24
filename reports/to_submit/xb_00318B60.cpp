// bin: xb
// va: 0x00318B60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318B60 (0x00318B60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043039C[];
extern "C" char DAT_004303AC[];
extern "C" Object DAT_0048BA74;
extern "C" char sub_001787A0[];

void __cdecl sub_00318B60(void)
{
    DAT_0048BA74.sub_0006F830((int)DAT_004303AC, (int)DAT_0043039C, (int)sub_001787A0, 0, 3, 3);
}
