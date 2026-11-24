// bin: proto
// va: 0x002EF750
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF750 (Proto 0x002EF750, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00490E04;
extern "C" int DAT_00490E10;
extern "C" int DAT_00490E14;
extern "C" char sub_002F7B40[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF750(void)
{
    DAT_00490E04.sub_00290E20(0, 0);
    DAT_00490E10 = 160;
    DAT_00490E14 = 4;
    sub_002C8EB3((int)sub_002F7B40);
}
