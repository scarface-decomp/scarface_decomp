// bin: proto
// va: 0x002E4940
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4940 (Proto 0x002E4940, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045BA8C;
extern "C" int __cdecl sub_000D74C0(void);

int __cdecl sub_002E4940(void)
{
    int t1, t2;

    t1 = sub_000D74C0();
    t2 = *(int*)t1;
    DAT_0045BA8C = *(int*)t1;
    return t2;
}
