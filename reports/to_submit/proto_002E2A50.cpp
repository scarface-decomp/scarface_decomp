// bin: proto
// va: 0x002E2A50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2A50 (Proto 0x002E2A50, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004538EC;
extern "C" int DAT_004538F8;
extern "C" int DAT_004538FC;
extern "C" char sub_002F1310[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E2A50(void)
{
    DAT_004538EC.sub_00290E20(0, 0);
    DAT_004538F8 = 108;
    DAT_004538FC = 4;
    sub_002C8EB3((int)sub_002F1310);
}
