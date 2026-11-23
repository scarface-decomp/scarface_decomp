// bin: xb
// va: 0x00216340
// what: 
// tool: the portal's starter code (no AI)

// sub_00216340 (0x00216340, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002172C0(int);
    int sub_00217380();
};

extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00216340(int a1, int a2, int a3)
{
    int t1;

    t1 = ((Object*)a1)->sub_00217380();
    if (t1) {
        ((Object*)t1)->sub_002172C0(sub_00243FA0(*(int*)(a3 + 8), 0));
    }
}
