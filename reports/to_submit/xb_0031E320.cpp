// bin: xb
// va: 0x0031E320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E320 (0x0031E320, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C694[];
extern "C" char DAT_0044C6A0[];
extern "C" Object DAT_004909A0;
extern "C" char sub_002166A0[];

void __cdecl sub_0031E320(void)
{
    DAT_004909A0.sub_0006F830((int)DAT_0044C6A0, (int)DAT_0044C694, (int)sub_002166A0, 0, 2, 2);
}
