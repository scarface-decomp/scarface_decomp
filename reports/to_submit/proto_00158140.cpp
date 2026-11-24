// bin: proto
// va: 0x00158140
// what: 
// tool: the portal's starter code (no AI)

// sub_00158140 (Proto 0x00158140, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00153270();
};

bool __cdecl sub_00158140(int a1)
{
    ((Object*)a1 + 704)->sub_00153270();
    return true;
}
