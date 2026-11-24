// bin: proto
// va: 0x002F0070
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0070 (Proto 0x002F0070, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00491218;
extern "C" int DAT_00491224;
extern "C" int DAT_00491228;
extern "C" char sub_002F7E20[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0070(void)
{
    DAT_00491218.sub_00290E20(0, 0);
    DAT_00491224 = 56;
    DAT_00491228 = 8;
    sub_002C8EB3((int)sub_002F7E20);
}
