// bin: proto
// va: 0x001418B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001418B0 (Proto 0x001418B0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001340E0(int);
};

extern "C" int __cdecl sub_0008E600(int);

void __cdecl sub_001418B0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001340E0(sub_0008E600(*(int*)(a3 + 8)));
}
