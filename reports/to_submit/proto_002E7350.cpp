// bin: proto
// va: 0x002E7350
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7350 (Proto 0x002E7350, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041019C[];
extern "C" char DAT_004101A4[];
extern "C" Object DAT_0045EEA4;
extern "C" char sub_00189F30[];

void __cdecl sub_002E7350(void)
{
    DAT_0045EEA4.sub_00065550((int)DAT_004101A4, (int)DAT_0041019C, (int)sub_00189F30, 0, 3, 3);
}
