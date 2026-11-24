// bin: xb
// va: 0x00316850
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316850 (0x00316850, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004895E4;
extern "C" int __cdecl sub_000E9B40(void);

int __cdecl sub_00316850(void)
{
    int t1, t2;

    t1 = sub_000E9B40();
    t2 = *(int*)t1;
    DAT_004895E4 = *(int*)t1;
    return t2;
}
