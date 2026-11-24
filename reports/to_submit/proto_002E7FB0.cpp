// bin: proto
// va: 0x002E7FB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7FB0 (Proto 0x002E7FB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00411528[];
extern "C" Object DAT_0045FAAC;
extern "C" char sub_0018B8B0[];

void __cdecl sub_002E7FB0(void)
{
    DAT_0045FAAC.sub_000654B0(0, (int)DAT_00411528, (int)sub_0018B8B0, 0, 1, 1);
}
