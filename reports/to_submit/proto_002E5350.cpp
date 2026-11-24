// bin: proto
// va: 0x002E5350
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5350 (Proto 0x002E5350, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00405D28[];
extern "C" Object DAT_0045BF0C;
extern "C" char sub_00101FF0[];

void __cdecl sub_002E5350(void)
{
    DAT_0045BF0C.sub_00065550(0, (int)DAT_00405D28, (int)sub_00101FF0, 0, 5, 9);
}
