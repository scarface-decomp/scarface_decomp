// bin: proto
// va: 0x002EB1F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB1F0 (Proto 0x002EB1F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00425E28[];
extern "C" char DAT_00425E38[];
extern "C" Object DAT_0046196C;
extern "C" char sub_001DA900[];

void __cdecl sub_002EB1F0(void)
{
    DAT_0046196C.sub_000655A0((int)DAT_00425E38, (int)DAT_00425E28, (int)sub_001DA900, 0, 6, 6);
}
