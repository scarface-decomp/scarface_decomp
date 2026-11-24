// bin: xb
// va: 0x002306E0
// what: 
// tool: the portal's starter code (no AI)

// sub_002306E0 (0x002306E0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00225810(int, int);
};

extern "C" int DAT_00491EF8;
extern "C" int __cdecl sub_0002B770(int, int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_002306E0(int a1, int a2, int a3)
{
    int t2;

    t2 = sub_0002B770(*(int*)(a3 + 4), 0);
    ((Object*)DAT_00491EF8)->sub_00225810(t2, sub_002FC43E(*(int*)(a3 + 8)));
}
