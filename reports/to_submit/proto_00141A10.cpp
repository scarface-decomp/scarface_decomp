// bin: proto
// va: 0x00141A10
// what: 
// tool: the portal's starter code (no AI)

// sub_00141A10 (Proto 0x00141A10, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00134190(int);
};

extern "C" int __cdecl sub_0008E600(int);

void __cdecl sub_00141A10(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_00134190(sub_0008E600(*(int*)(a3 + 8)));
}
