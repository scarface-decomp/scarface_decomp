// bin: xb
// va: 0x00312180
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312180 (0x00312180, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00419F2C[];
extern "C" char DAT_00419F34[];
extern "C" Object DAT_00471524;
extern "C" char sub_00020860[];

void __cdecl sub_00312180(void)
{
    DAT_00471524.sub_0006F830((int)DAT_00419F34, (int)DAT_00419F2C, (int)sub_00020860, 0, 5, 6);
}
