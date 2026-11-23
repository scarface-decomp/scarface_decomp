// bin: proto
// va: 0x00158E60
// what: 
// tool: the portal's starter code (no AI)

// sub_00158E60 (Proto 0x00158E60, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00149910(int);
};

extern "C" int __cdecl sub_00028CF0(int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00158E60(int a1, int a2, int a3)
{
    int t2, t4;

    t2 = sub_002C96FE(*(int*)(a3 + 8));
    if (t2 > 0) {
        ((Object*)a1)->sub_00149910(t2);
        return;
    }
    t4 = sub_00028CF0(*(int*)(a3 + 8), 0);
    if (t4) {
        ((Object*)a1)->sub_00149910(*(int*)(t4 + 16));
    }
}
