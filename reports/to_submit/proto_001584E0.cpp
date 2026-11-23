// bin: proto
// va: 0x001584E0
// what: 
// tool: the portal's starter code (no AI)

// sub_001584E0 (Proto 0x001584E0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00147ED0(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_001584E0(int a1, int a2, int a3)
{
    int t1;

    t1 = sub_002C96FE(*(int*)(a3 + 8));
    if (t1 > 0) {
        ((Object*)a1)->sub_00147ED0(t1);
    }
}
