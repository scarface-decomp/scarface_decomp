// bin: xb
// va: 0x00216780
// what: 
// tool: the portal's starter code (no AI)

// sub_00216780 (0x00216780, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00217380();
};

extern "C" bool __cdecl sub_00099BC0(int);

void __cdecl sub_00216780(int a1, int a2, int a3)
{
    bool t1;
    int t2;

    t1 = sub_00099BC0(*(int*)(a3 + 8));
    t2 = ((Object*)a1)->sub_00217380();
    if (t2) {
        *(unsigned char*)(t2 + 1598) = t1;
    }
}
