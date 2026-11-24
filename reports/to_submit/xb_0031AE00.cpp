// bin: xb
// va: 0x0031AE00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AE00 (0x0031AE00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004387E4[];
extern "C" char DAT_004387F4[];
extern "C" Object DAT_0048E5A4;
extern "C" char sub_001C7180[];

void __cdecl sub_0031AE00(void)
{
    DAT_0048E5A4.sub_0006F830((int)DAT_004387F4, (int)DAT_004387E4, (int)sub_001C7180, 0, 2, 2);
}
