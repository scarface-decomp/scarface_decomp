// bin: xb
// va: 0x003121C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003121C0 (0x003121C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00419F5C[];
extern "C" char DAT_00419F70[];
extern "C" Object DAT_0047157C;
extern "C" char sub_00020900[];

void __cdecl sub_003121C0(void)
{
    DAT_0047157C.sub_0006F830((int)DAT_00419F70, (int)DAT_00419F5C, (int)sub_00020900, 0, 5, 6);
}
