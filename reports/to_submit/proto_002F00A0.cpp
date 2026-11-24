// bin: proto
// va: 0x002F00A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F00A0 (Proto 0x002F00A0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_0049122C;
extern "C" int DAT_00491238;
extern "C" int DAT_0049123C;
extern "C" char sub_002F7E10[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F00A0(void)
{
    DAT_0049122C.sub_00290E20(0, 0);
    DAT_00491238 = 16;
    DAT_0049123C = 4;
    sub_002C8EB3((int)sub_002F7E10);
}
