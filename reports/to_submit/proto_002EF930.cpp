// bin: proto
// va: 0x002EF930
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF930 (Proto 0x002EF930, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00490EC4;
extern "C" int DAT_00490ED0;
extern "C" int DAT_00490ED4;
extern "C" char sub_00020340[];
extern "C" char sub_002F7BD0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF930(void)
{
    DAT_00490EC4.sub_00290E20(0, 0);
    DAT_00490ED0 = (int)sub_00020340;
    DAT_00490ED4 = 4;
    sub_002C8EB3((int)sub_002F7BD0);
}
