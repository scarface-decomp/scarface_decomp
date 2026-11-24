// bin: proto
// va: 0x002EFB90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EFB90 (Proto 0x002EFB90, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00490FF4;
extern "C" int DAT_00491000;
extern "C" int DAT_00491004;
extern "C" char sub_002F7C90[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EFB90(void)
{
    DAT_00490FF4.sub_00290E20(0, 0);
    DAT_00491000 = 64;
    DAT_00491004 = 8;
    sub_002C8EB3((int)sub_002F7C90);
}
