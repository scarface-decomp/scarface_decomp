// bin: proto
// va: 0x002E2BA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2BA0 (Proto 0x002E2BA0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004539A8;
extern "C" int DAT_004539B4;
extern "C" int DAT_004539B8;
extern "C" char sub_002F1380[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E2BA0(void)
{
    DAT_004539A8.sub_00290E20(0, 0);
    DAT_004539B4 = 32;
    DAT_004539B8 = 8;
    sub_002C8EB3((int)sub_002F1380);
}
