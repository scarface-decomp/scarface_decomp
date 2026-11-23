// bin: proto
// va: 0x001419F0
// what: 
// tool: the portal's starter code (no AI)

// sub_001419F0 (Proto 0x001419F0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00134130(int);
};

extern "C" int __cdecl sub_0008E600(int);

void __cdecl sub_001419F0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_00134130(sub_0008E600(*(int*)(a3 + 8)));
}
