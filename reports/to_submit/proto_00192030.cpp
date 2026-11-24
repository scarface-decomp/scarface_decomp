// bin: proto
// va: 0x00192030
// what: 
// tool: the portal's starter code (no AI)

// sub_00192030 (Proto 0x00192030, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00191EA0(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00192030(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_00191EA0(sub_002C96FE(*(int*)(a3 + 8)));
}
