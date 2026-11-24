// bin: xb
// va: 0x001EE150
// what: 
// tool: the portal's starter code (no AI)

// sub_001EE150 (0x001EE150, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001EFB90(int);
};

extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_001EE150(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001EFB90(sub_00244040(*(int*)(a3 + 8), 0));
}
