// bin: xb
// va: 0x001BED70
// what: 
// tool: the portal's starter code (no AI)

// sub_001BED70 (0x001BED70, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A5250(int);
};

void __cdecl sub_001BED70(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001A5250(*(int*)(a3 + 8));
}
