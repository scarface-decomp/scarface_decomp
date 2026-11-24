// bin: proto
// va: 0x002EF660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF660 (Proto 0x002EF660, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00490DA0;
extern "C" int DAT_00490DAC;
extern "C" int DAT_00490DB0;
extern "C" char sub_002F7AE0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF660(void)
{
    DAT_00490DA0.sub_00290E20(0, 0);
    DAT_00490DAC = 40;
    DAT_00490DB0 = 4;
    sub_002C8EB3((int)sub_002F7AE0);
}
