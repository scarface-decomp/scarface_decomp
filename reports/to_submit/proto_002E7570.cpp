// bin: proto
// va: 0x002E7570
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7570 (Proto 0x002E7570, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004104F8[];
extern "C" char DAT_00410504[];
extern "C" Object DAT_0045F088;
extern "C" char sub_0018A320[];

void __cdecl sub_002E7570(void)
{
    DAT_0045F088.sub_000655A0((int)DAT_00410504, (int)DAT_004104F8, (int)sub_0018A320, 0, 2, 2);
}
