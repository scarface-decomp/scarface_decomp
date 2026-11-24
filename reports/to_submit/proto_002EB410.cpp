// bin: proto
// va: 0x002EB410
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB410 (Proto 0x002EB410, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00426050[];
extern "C" char DAT_00426064[];
extern "C" Object DAT_00461C58;
extern "C" char sub_001DAD60[];

void __cdecl sub_002EB410(void)
{
    DAT_00461C58.sub_000655A0((int)DAT_00426064, (int)DAT_00426050, (int)sub_001DAD60, 0, 2, 2);
}
