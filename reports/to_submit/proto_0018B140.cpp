// bin: proto
// va: 0x0018B140
// what: 
// tool: the portal's starter code (no AI)

// sub_0018B140 (Proto 0x0018B140, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0016ED30(int);
    void sub_001784C0(int);
    void sub_00178500(int);
};

extern "C" int DAT_0045E07C;
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0018B140(int a1, int a2, int a3)
{
    int t1;

    t1 = ((Object*)DAT_0045E07C)->sub_0016ED30(18);
    ((Object*)t1)->sub_00178500(sub_002C96FE(*(int*)(a3 + 4)));
    if (a2 > 2) {
        ((Object*)t1)->sub_001784C0(*(int*)(a3 + 8));
    }
}
