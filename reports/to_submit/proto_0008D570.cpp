// bin: proto
// va: 0x0008D570
// what: 
// tool: the portal's starter code (no AI)

// sub_0008D570 (Proto 0x0008D570, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008CFE0(int);
};

extern "C" Object DAT_004542A4;
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0008D570(int a1, int a2, int a3)
{
    DAT_004542A4.sub_0008CFE0(sub_002C96FE(*(int*)(a3 + 4)));
}
