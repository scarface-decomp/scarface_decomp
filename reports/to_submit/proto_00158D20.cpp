// bin: proto
// va: 0x00158D20
// what: 
// tool: the portal's starter code (no AI)

// sub_00158D20 (Proto 0x00158D20, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00462DD4;

int __cdecl sub_00158D20(int a1)
{
    return *(int*)(a1 + 16) == DAT_00462DD4;
}
