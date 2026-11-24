// bin: proto
// va: 0x002E7E90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7E90 (Proto 0x002E7E90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004113EC[];
extern "C" char DAT_004113FC[];
extern "C" Object DAT_0045F920;
extern "C" char sub_0018B7B0[];

void __cdecl sub_002E7E90(void)
{
    DAT_0045F920.sub_000655A0((int)DAT_004113FC, (int)DAT_004113EC, (int)sub_0018B7B0, 0, 3, 3);
}
