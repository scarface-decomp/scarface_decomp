// bin: proto
// va: 0x002EF690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF690 (Proto 0x002EF690, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00490DB4;
extern "C" int DAT_00490DC0;
extern "C" int DAT_00490DC4;
extern "C" char sub_002F7B00[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF690(void)
{
    DAT_00490DB4.sub_00290E20(0, 0);
    DAT_00490DC0 = 28;
    DAT_00490DC4 = 4;
    sub_002C8EB3((int)sub_002F7B00);
}
