// bin: xb
// va: 0x00320000
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320000 (0x00320000, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044E4EC[];
extern "C" Object DAT_004924F4;
extern "C" char sub_002307C0[];

void __cdecl sub_00320000(void)
{
    DAT_004924F4.sub_0006F880(0, (int)DAT_0044E4EC, (int)sub_002307C0, 0, 1, 1);
}
