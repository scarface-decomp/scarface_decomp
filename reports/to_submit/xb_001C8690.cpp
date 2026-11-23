// bin: xb
// va: 0x001C8690
// what: 
// tool: the portal's starter code (no AI)

// sub_001C8690 (0x001C8690, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C79B0(int);
};

extern "C" int DAT_0048E654;
extern "C" int __cdecl sub_0002B770(int, int);

void __cdecl sub_001C8690(int a1, int a2, int a3)
{
    int t1;

    t1 = sub_0002B770(*(int*)(a3 + 4), 0);
    if (t1) {
        ((Object*)DAT_0048E654)->sub_001C79B0(t1);
    }
}
