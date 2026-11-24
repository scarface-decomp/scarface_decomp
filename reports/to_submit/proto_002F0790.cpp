// bin: proto
// va: 0x002F0790
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0790 (Proto 0x002F0790, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00491548;
extern "C" int DAT_00491554;
extern "C" int DAT_00491558;
extern "C" char sub_002F80B0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0790(void)
{
    DAT_00491548.sub_00290E20(0, 0);
    DAT_00491554 = 8;
    DAT_00491558 = 4;
    sub_002C8EB3((int)sub_002F80B0);
}
