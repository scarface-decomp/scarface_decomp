// bin: proto
// va: 0x002E3010
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3010 (Proto 0x002E3010, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00383ADC[];
extern "C" Object DAT_00454184;
extern "C" char sub_0008AC10[];

void __cdecl sub_002E3010(void)
{
    DAT_00454184.sub_000D8CC0(55, 41, 49, 87, 50, (int)DAT_00383ADC, (int)sub_0008AC10, 72, 0, 0);
}
