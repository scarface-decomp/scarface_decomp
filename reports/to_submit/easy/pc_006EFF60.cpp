// bin: pc
// va: 0x006EFF60
// tool: the portal's starter code (no AI)
// sub_006EFF60 (0x006EFF60, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EBBD0();
    void sub_006F2C40(int);
};

extern "C" int DAT_0072F058;
extern "C" char DAT_007F69E0[];
extern "C" int DAT_0085D134;
extern "C" void __cdecl sub_006EE890(int, int);
extern "C" void __cdecl sub_006F3C50(int, int);

int __cdecl sub_006EFF60(int a1)
{
    int t6;

    ((Object*)DAT_0085D134 + 8)->sub_006F2C40(a1);
    ((void (__stdcall*)(int, int, int))DAT_0072F058)(*(int*)(a1 + 20), 0, 32768);
    sub_006F3C50(DAT_0085D134, a1);
    ((Object*)a1 + 104)->sub_006EBBD0();
    sub_006EE890((int)DAT_007F69E0, a1);
    t6 = DAT_0085D134;
    *(int*)(DAT_0085D134 + 20) += -1;
    return t6;
}
