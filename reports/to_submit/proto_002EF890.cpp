// bin: proto
// va: 0x002EF890
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF890 (Proto 0x002EF890, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00490E98;
extern "C" int DAT_00490EA4;
extern "C" int DAT_00490EA8;
extern "C" char sub_002F7BA0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF890(void)
{
    DAT_00490E98.sub_00290E20(0, 0);
    DAT_00490EA4 = 128;
    DAT_00490EA8 = 8;
    sub_002C8EB3((int)sub_002F7BA0);
}
