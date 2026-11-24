// bin: xb
// va: 0x001C8720
// what: 
// tool: the portal's starter code (no AI)

// sub_001C8720 (0x001C8720, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C7260(int, int);
};

extern "C" int DAT_0048E654;
extern "C" int __cdecl sub_0002B770(int, int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001C8720(int a1, int a2, int a3)
{
    int t2, t3;

    t2 = sub_0002B770(*(int*)(a3 + 4), 0);
    if (t2) {
        t3 = DAT_0048E654;
        ((Object*)t3)->sub_001C7260(t2, sub_002FC43E(*(int*)(a3 + 8)));
    }
}
