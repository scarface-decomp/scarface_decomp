// bin: proto
// va: 0x0002AB60
// what: 
// tool: the portal's starter code (no AI)

// sub_0002AB60 (Proto 0x0002AB60, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008E380();
};

int __cdecl sub_0002AB60(int a1)
{
    return (short)((unsigned short)((Object*)a1 + 48)->sub_0008E380());
}
