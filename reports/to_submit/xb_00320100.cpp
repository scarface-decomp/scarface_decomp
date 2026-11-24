// bin: xb
// va: 0x00320100
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320100 (0x00320100, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044E5E0[];
extern "C" Object DAT_00492654;
extern "C" char sub_002308C0[];

void __cdecl sub_00320100(void)
{
    DAT_00492654.sub_0006F880(0, (int)DAT_0044E5E0, (int)sub_002308C0, 0, 1, 1);
}
