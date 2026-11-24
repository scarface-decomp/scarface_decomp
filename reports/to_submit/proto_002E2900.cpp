// bin: proto
// va: 0x002E2900
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2900 (Proto 0x002E2900, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004537DC;
extern "C" int DAT_004537E8;
extern "C" int DAT_004537EC;
extern "C" char sub_002F12A0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E2900(void)
{
    DAT_004537DC.sub_00290E20(0, 0);
    DAT_004537E8 = 308;
    DAT_004537EC = 4;
    sub_002C8EB3((int)sub_002F12A0);
}
