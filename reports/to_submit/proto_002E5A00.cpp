// bin: proto
// va: 0x002E5A00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5A00 (Proto 0x002E5A00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00409E54[];
extern "C" char DAT_00409E64[];
extern "C" Object DAT_0045C7D8;
extern "C" char sub_00141E30[];

void __cdecl sub_002E5A00(void)
{
    DAT_0045C7D8.sub_000655A0((int)DAT_00409E64, (int)DAT_00409E54, (int)sub_00141E30, 0, 3, 3);
}
