// bin: proto
// va: 0x00158300
// what: 
// tool: the portal's starter code (no AI)

// sub_00158300 (Proto 0x00158300, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00147E70(int);
};

void __cdecl sub_00158300(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_00147E70(*(int*)(a3 + 8));
}
