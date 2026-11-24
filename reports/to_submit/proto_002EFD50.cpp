// bin: proto
// va: 0x002EFD50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EFD50 (Proto 0x002EFD50, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004910A4;
extern "C" int DAT_004910B0;
extern "C" int DAT_004910B4;
extern "C" char sub_002F7D20[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EFD50(void)
{
    DAT_004910A4.sub_00290E20(0, 0);
    DAT_004910B0 = 64;
    DAT_004910B4 = 8;
    sub_002C8EB3((int)sub_002F7D20);
}
