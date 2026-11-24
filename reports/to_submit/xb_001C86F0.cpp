// bin: xb
// va: 0x001C86F0
// what: 
// tool: the portal's starter code (no AI)

// sub_001C86F0 (0x001C86F0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001C7240(int);
};

extern "C" int DAT_0048E654;
extern "C" int __cdecl sub_0002B770(int, int);

int __cdecl sub_001C86F0(int a1, int a2, int a3)
{
    int t1;

    t1 = sub_0002B770(*(int*)(a3 + 4), 0);
    if (t1) {
        return ((Object*)DAT_0048E654)->sub_001C7240(t1);
    }
    return 0;
}
