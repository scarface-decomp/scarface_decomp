// bin: proto
// va: 0x002EBFB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EBFB0 (Proto 0x002EBFB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_004270E8[];
extern "C" char DAT_004270F4[];
extern "C" Object DAT_00462828;
extern "C" char sub_001E5370[];

void __cdecl sub_002EBFB0(void)
{
    DAT_00462828.sub_00065460((int)DAT_004270F4, (int)DAT_004270E8, (int)sub_001E5370, 0, 5, 8);
}
