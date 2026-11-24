// bin: proto
// va: 0x002EFD20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EFD20 (Proto 0x002EFD20, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00491078;
extern "C" int DAT_00491084;
extern "C" int DAT_00491088;
extern "C" char sub_002F7CF0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EFD20(void)
{
    DAT_00491078.sub_00290E20(0, 0);
    DAT_00491084 = 24;
    DAT_00491088 = 4;
    sub_002C8EB3((int)sub_002F7CF0);
}
