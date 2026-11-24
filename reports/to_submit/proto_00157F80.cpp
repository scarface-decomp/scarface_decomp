// bin: proto
// va: 0x00157F80
// what: 
// tool: the portal's starter code (no AI)

// sub_00157F80 (Proto 0x00157F80, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00153840();
};

bool __cdecl sub_00157F80(int a1)
{
    ((Object*)a1 + 704)->sub_00153840();
    return true;
}
