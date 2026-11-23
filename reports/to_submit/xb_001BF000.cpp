// bin: xb
// va: 0x001BF000
// what: 
// tool: the portal's starter code (no AI)

// sub_001BF000 (0x001BF000, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A8170(int);
};

extern "C" int __cdecl sub_00099BC0(int);

void __cdecl sub_001BF000(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001A8170(sub_00099BC0(*(int*)(a3 + 8)));
}
