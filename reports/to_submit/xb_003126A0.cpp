// bin: xb
// va: 0x003126A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003126A0 (0x003126A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041AAB0[];
extern "C" char DAT_0041AABC[];
extern "C" Object DAT_004719D8;
extern "C" char sub_00024D80[];

void __cdecl sub_003126A0(void)
{
    DAT_004719D8.sub_0006F830((int)DAT_0041AABC, (int)DAT_0041AAB0, (int)sub_00024D80, 0, 4, 4);
}
