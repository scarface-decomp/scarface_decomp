// bin: xb
// va: 0x0031C9D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C9D0 (0x0031C9D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E310[];
extern "C" char DAT_0043E320[];
extern "C" Object DAT_0048F9D0;
extern "C" char sub_001EE280[];

void __cdecl sub_0031C9D0(void)
{
    DAT_0048F9D0.sub_0006F830((int)DAT_0043E320, (int)DAT_0043E310, (int)sub_001EE280, 0, 3, 3);
}
