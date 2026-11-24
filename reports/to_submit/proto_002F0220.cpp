// bin: proto
// va: 0x002F0220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0220 (Proto 0x002F0220, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004912EC;
extern "C" int DAT_004912F8;
extern "C" int DAT_004912FC;
extern "C" char sub_002F7E90[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0220(void)
{
    DAT_004912EC.sub_00290E20(0, 0);
    DAT_004912F8 = 28;
    DAT_004912FC = 4;
    sub_002C8EB3((int)sub_002F7E90);
}
