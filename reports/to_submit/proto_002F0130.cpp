// bin: proto
// va: 0x002F0130
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0130 (Proto 0x002F0130, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_00491278;
extern "C" int DAT_00491284;
extern "C" int DAT_00491288;
extern "C" char sub_002F7E60[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0130(void)
{
    DAT_00491278.sub_00290E20(0, 0);
    DAT_00491284 = 56;
    DAT_00491288 = 8;
    sub_002C8EB3((int)sub_002F7E60);
}
