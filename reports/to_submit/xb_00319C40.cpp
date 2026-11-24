// bin: xb
// va: 0x00319C40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319C40 (0x00319C40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00436630[];
extern "C" char DAT_0043663C[];
extern "C" Object DAT_0048D4AC;
extern "C" char sub_001BD100[];

void __cdecl sub_00319C40(void)
{
    DAT_0048D4AC.sub_0006F880((int)DAT_0043663C, (int)DAT_00436630, (int)sub_001BD100, 0, 2, 2);
}
