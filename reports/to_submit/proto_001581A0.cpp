// bin: proto
// va: 0x001581A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001581A0 (Proto 0x001581A0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001494F0(int);
};

void __cdecl sub_001581A0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001494F0(*(int*)(a3 + 8));
}
