// bin: proto
// va: 0x002F0660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0660 (Proto 0x002F0660, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004914E4;
extern "C" int DAT_004914F0;
extern "C" int DAT_004914F4;
extern "C" char sub_002F8010[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0660(void)
{
    DAT_004914E4.sub_00290E20(0, 0);
    DAT_004914F0 = 136;
    DAT_004914F4 = 8;
    sub_002C8EB3((int)sub_002F8010);
}
