// bin: proto
// va: 0x002EB250
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB250 (Proto 0x002EB250, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00425E8C[];
extern "C" char DAT_00425E9C[];
extern "C" Object DAT_004619F0;
extern "C" char sub_001DAA00[];

void __cdecl sub_002EB250(void)
{
    DAT_004619F0.sub_000655A0((int)DAT_00425E9C, (int)DAT_00425E8C, (int)sub_001DAA00, 0, 2, 2);
}
