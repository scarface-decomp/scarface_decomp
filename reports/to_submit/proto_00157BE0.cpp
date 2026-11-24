// bin: proto
// va: 0x00157BE0
// what: 
// tool: the portal's starter code (no AI)

// sub_00157BE0 (Proto 0x00157BE0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00143100();
};

int __cdecl sub_00157BE0(int a1)
{
    return (unsigned char)((Object*)a1)->sub_00143100();
}
