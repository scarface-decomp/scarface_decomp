// bin: proto
// va: 0x002F07C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F07C0 (Proto 0x002F07C0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_0049155C;
extern "C" int DAT_00491568;
extern "C" int DAT_0049156C;
extern "C" char sub_002F80A0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F07C0(void)
{
    DAT_0049155C.sub_00290E20(0, 0);
    DAT_00491568 = 8;
    DAT_0049156C = 4;
    sub_002C8EB3((int)sub_002F80A0);
}
