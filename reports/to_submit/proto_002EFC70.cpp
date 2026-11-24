// bin: proto
// va: 0x002EFC70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EFC70 (Proto 0x002EFC70, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00491038;
extern "C" int DAT_00491044;
extern "C" int DAT_00491048;
extern "C" char sub_002F7CC0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EFC70(void)
{
    DAT_00491038.sub_00290E20(0, 0);
    DAT_00491044 = 16;
    DAT_00491048 = 4;
    sub_002C8EB3((int)sub_002F7CC0);
}
