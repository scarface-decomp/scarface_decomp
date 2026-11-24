// bin: xb
// va: 0x00216370
// what: 
// tool: the portal's starter code (no AI)

// sub_00216370 (0x00216370, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002172D0(int);
    int sub_00217380();
};

extern "C" int __cdecl sub_00243FA0(int, int);

int __cdecl sub_00216370(int a1, int a2, int a3)
{
    int t2;

    if (((Object*)a1)->sub_00217380()) {
        t2 = ((Object*)a1)->sub_00217380();
        return ((Object*)t2)->sub_002172D0(sub_00243FA0(*(int*)(a3 + 8), 0));
    }
    return 0;
}
