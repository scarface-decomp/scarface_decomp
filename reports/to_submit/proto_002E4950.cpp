// bin: proto
// va: 0x002E4950
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4950 (Proto 0x002E4950, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FF300();
};

extern "C" Object DAT_0045BB10;
extern "C" int DAT_0045BB2C;
extern "C" char sub_002F17D0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4950(void)
{
    DAT_0045BB10.sub_001FF300();
    DAT_0045BB2C = 32;
    sub_002C8EB3((int)sub_002F17D0);
}
