// bin: proto
// va: 0x002EF8F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF8F0 (Proto 0x002EF8F0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" char DAT_003B9B4C[];
extern "C" Object DAT_00490ED8;
extern "C" int DAT_00490EE4;
extern "C" int DAT_00490EE8;
extern "C" char sub_002F7BC0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF8F0(void)
{
    DAT_00490ED8.sub_00290E20((int)DAT_003B9B4C, 0);
    DAT_00490EE4 = 4096;
    DAT_00490EE8 = 32;
    sub_002C8EB3((int)sub_002F7BC0);
}
