// bin: xb
// va: 0x003128B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003128B0 (0x003128B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041B680[];
extern "C" char DAT_0041B68C[];
extern "C" Object DAT_0047411C;
extern "C" char sub_0002D330[];

void __cdecl sub_003128B0(void)
{
    DAT_0047411C.sub_0006F830((int)DAT_0041B68C, (int)DAT_0041B680, (int)sub_0002D330, 0, 3, 3);
}
