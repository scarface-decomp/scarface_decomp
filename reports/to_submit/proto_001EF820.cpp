// bin: proto
// va: 0x001EF820
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF820 (Proto 0x001EF820, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00462F6C;

int __cdecl sub_001EF820(void)
{
    return *(int*)(*(int*)(DAT_00462F6C + 4) + 16);
}
