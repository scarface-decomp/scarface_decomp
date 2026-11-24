// bin: xb
// va: 0x001EE200
// what: 
// tool: the portal's starter code (no AI)

// sub_001EE200 (0x001EE200, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001EEF70(int);
};

void __cdecl sub_001EE200(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001EEF70(*(int*)(a3 + 8));
}
