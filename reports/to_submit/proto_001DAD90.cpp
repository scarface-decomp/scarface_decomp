// bin: proto
// va: 0x001DAD90
// what: 
// tool: the portal's starter code (no AI)

// sub_001DAD90 (Proto 0x001DAD90, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001DB8F0();
};

extern "C" bool __cdecl sub_0008E600(int);

void __cdecl sub_001DAD90(int a1, int a2, int a3)
{
    bool t1;
    int t2;

    t1 = sub_0008E600(*(int*)(a3 + 8));
    t2 = ((Object*)a1)->sub_001DB8F0();
    if (t2) {
        *(unsigned char*)(t2 + 1556) = t1;
    }
}
