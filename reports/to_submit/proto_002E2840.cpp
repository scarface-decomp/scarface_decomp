// bin: proto
// va: 0x002E2840
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2840 (Proto 0x002E2840, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_0045377C;
extern "C" int DAT_00453788;
extern "C" int DAT_0045378C;
extern "C" char sub_002F1270[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E2840(void)
{
    DAT_0045377C.sub_00290E20(0, 0);
    DAT_00453788 = 8;
    DAT_0045378C = 4;
    sub_002C8EB3((int)sub_002F1270);
}
