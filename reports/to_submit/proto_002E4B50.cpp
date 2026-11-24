// bin: proto
// va: 0x002E4B50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4B50 (Proto 0x002E4B50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00403318[];
extern "C" char DAT_00403324[];
extern "C" Object DAT_0045BDEC;
extern "C" char sub_000FE680[];

void __cdecl sub_002E4B50(void)
{
    DAT_0045BDEC.sub_00065550((int)DAT_00403324, (int)DAT_00403318, (int)sub_000FE680, 0, 8, 10);
}
