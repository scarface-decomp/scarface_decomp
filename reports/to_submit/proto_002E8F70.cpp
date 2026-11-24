// bin: proto
// va: 0x002E8F70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8F70 (Proto 0x002E8F70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00414270[];
extern "C" char DAT_0041427C[];
extern "C" Object DAT_004604C0;
extern "C" char sub_0019B970[];

void __cdecl sub_002E8F70(void)
{
    DAT_004604C0.sub_000655A0((int)DAT_0041427C, (int)DAT_00414270, (int)sub_0019B970, 0, 2, 2);
}
