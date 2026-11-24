// bin: proto
// va: 0x002E9B20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9B20 (Proto 0x002E9B20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00417A50[];
extern "C" char DAT_00417A58[];
extern "C" Object DAT_00460CEC;
extern "C" char sub_001B4290[];

void __cdecl sub_002E9B20(void)
{
    DAT_00460CEC.sub_000655A0((int)DAT_00417A58, (int)DAT_00417A50, (int)sub_001B4290, 0, 3, 3);
}
