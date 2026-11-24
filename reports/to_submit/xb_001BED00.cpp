// bin: xb
// va: 0x001BED00
// what: 
// tool: the portal's starter code (no AI)

// sub_001BED00 (0x001BED00, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A5200(int);
};

extern "C" int __cdecl sub_00099BC0(int);

void __cdecl sub_001BED00(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001A5200(sub_00099BC0(*(int*)(a3 + 8)));
}
