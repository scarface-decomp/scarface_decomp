// bin: proto
// va: 0x0018B890
// what: 
// tool: the portal's starter code (no AI)

// sub_0018B890 (Proto 0x0018B890, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0017BC50(int);
};

void __cdecl sub_0018B890(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_0017BC50(*(int*)(a3 + 8));
}
