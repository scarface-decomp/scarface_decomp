// bin: proto
// va: 0x0018B690
// what: 
// tool: the portal's starter code (no AI)

// sub_0018B690 (Proto 0x0018B690, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0017A8E0(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0018B690(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_0017A8E0(sub_002C96FE(*(int*)(a3 + 8)));
}
