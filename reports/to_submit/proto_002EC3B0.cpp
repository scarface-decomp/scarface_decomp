// bin: proto
// va: 0x002EC3B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC3B0 (Proto 0x002EC3B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004275F0[];
extern "C" Object DAT_00462D7C;
extern "C" char sub_001E5C40[];

void __cdecl sub_002EC3B0(void)
{
    DAT_00462D7C.sub_000655A0(0, (int)DAT_004275F0, (int)sub_001E5C40, 0, 2, 2);
}
