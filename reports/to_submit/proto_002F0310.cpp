// bin: proto
// va: 0x002F0310
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0310 (Proto 0x002F0310, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00491368;
extern "C" int DAT_00491374;
extern "C" int DAT_00491378;
extern "C" char sub_002F7F00[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0310(void)
{
    DAT_00491368.sub_00290E20(0, 0);
    DAT_00491374 = 104;
    DAT_00491378 = 8;
    sub_002C8EB3((int)sub_002F7F00);
}
