// bin: proto
// va: 0x002F0550
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0550 (Proto 0x002F0550, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_0049146C;
extern "C" int DAT_00491478;
extern "C" int DAT_0049147C;
extern "C" char sub_002F7FC0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002F0550(void)
{
    DAT_0049146C.sub_00290E20(0, 0);
    DAT_00491478 = 420;
    DAT_0049147C = 4;
    sub_002C8EB3((int)sub_002F7FC0);
}
