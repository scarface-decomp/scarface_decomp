// bin: xb
// va: 0x001BF620
// what: 
// tool: the portal's starter code (no AI)

// sub_001BF620 (0x001BF620, 98 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00195830(int);
    void sub_001AD700(int);
    void sub_001AD7D0(int);
};

extern "C" int DAT_0048C23C;
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BF620(int a1, int a2, int a3)
{
    int t1;

    t1 = ((Object*)DAT_0048C23C)->sub_00195830(70);
    if (t1) {
        *(int*)(t1 + 132) = sub_002FC43E(*(int*)(a3 + 4));
        *(int*)(t1 + 136) = sub_002FC43E(*(int*)(a3 + 8));
        *(int*)(t1 + 140) = sub_002FC43E(*(int*)(a3 + 12));
        ((Object*)t1)->sub_001AD700(*(int*)(a3 + 16));
        ((Object*)t1)->sub_001AD7D0(*(int*)(a3 + 20));
    }
}
