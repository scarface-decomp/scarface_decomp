// bin: proto
// va: 0x002E80B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E80B0 (Proto 0x002E80B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004115F8[];
extern "C" char DAT_0041160C[];
extern "C" Object DAT_0045FBB4;
extern "C" char sub_0018B9F0[];

void __cdecl sub_002E80B0(void)
{
    DAT_0045FBB4.sub_000655A0((int)DAT_0041160C, (int)DAT_004115F8, (int)sub_0018B9F0, 0, 2, 2);
}
