// bin: proto
// va: 0x0018A5A0
// what: 
// tool: the portal's starter code (no AI)

// sub_0018A5A0 (Proto 0x0018A5A0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0016ECA0(int, int);
    void sub_0016F460(int);
};

extern "C" int DAT_0045E07C;
extern "C" int __cdecl sub_0008E600(int);

void __cdecl sub_0018A5A0(int a1, int a2, int a3)
{
    int t2;

    t2 = DAT_0045E07C;
    ((Object*)t2)->sub_0016F460(((Object*)t2)->sub_0016ECA0(*(int*)(a3 + 4), sub_0008E600(*(int*)(a3 + 8))));
}
