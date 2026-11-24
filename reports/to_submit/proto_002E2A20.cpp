// bin: proto
// va: 0x002E2A20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2A20 (Proto 0x002E2A20, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004538D8;
extern "C" int DAT_004538E4;
extern "C" int DAT_004538E8;
extern "C" char sub_002F1300[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E2A20(void)
{
    DAT_004538D8.sub_00290E20(0, 0);
    DAT_004538E4 = 32;
    DAT_004538E8 = 4;
    sub_002C8EB3((int)sub_002F1300);
}
