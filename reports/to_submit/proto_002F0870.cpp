// bin: proto
// va: 0x002F0870
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0870 (Proto 0x002F0870, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004915B0;
extern "C" int DAT_004915BC;
extern "C" int DAT_004915C0;
extern "C" char sub_002F80F0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0870(void)
{
    DAT_004915B0.sub_00290E20(0, 0);
    DAT_004915BC = 88;
    DAT_004915C0 = 8;
    sub_002C8EB3((int)sub_002F80F0);
}
