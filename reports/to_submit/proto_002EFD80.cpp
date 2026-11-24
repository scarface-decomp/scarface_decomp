// bin: proto
// va: 0x002EFD80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EFD80 (Proto 0x002EFD80, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004910B8;
extern "C" int DAT_004910C4;
extern "C" int DAT_004910C8;
extern "C" char sub_002F7D10[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EFD80(void)
{
    DAT_004910B8.sub_00290E20(0, 0);
    DAT_004910C4 = 16;
    DAT_004910C8 = 4;
    sub_002C8EB3((int)sub_002F7D10);
}
