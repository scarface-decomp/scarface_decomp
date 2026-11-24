// bin: proto
// va: 0x002EF2E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF2E0 (Proto 0x002EF2E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" char DAT_003B91B8[];
extern "C" Object DAT_00490B8C;
extern "C" char sub_002F7970[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF2E0(void)
{
    DAT_00490B8C.sub_00290E20((int)DAT_003B91B8, 0);
    sub_002C8EB3((int)sub_002F7970);
}
