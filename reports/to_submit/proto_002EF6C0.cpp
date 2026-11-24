// bin: proto
// va: 0x002EF6C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF6C0 (Proto 0x002EF6C0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00490DC8;
extern "C" int DAT_00490DD4;
extern "C" int DAT_00490DD8;
extern "C" char sub_002F7AF0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF6C0(void)
{
    DAT_00490DC8.sub_00290E20(0, 0);
    DAT_00490DD4 = 4;
    DAT_00490DD8 = 4;
    sub_002C8EB3((int)sub_002F7AF0);
}
