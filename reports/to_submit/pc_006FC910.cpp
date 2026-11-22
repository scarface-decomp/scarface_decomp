// bin: pc
// va: 0x006FC910
// what: 
// tool: the portal's starter code (no AI)

// sub_006FC910 (PC 0x006FC910, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006FC910(int a1)
{
    return (((((unsigned int)*(int*)(*(int*)(a1 + 8) + 12)) >> 4) & 31) * *(int*)(a1 + 136)) + (((((unsigned int)*(int*)(*(int*)(a1 + 8) + 12)) >> 4) & 31) * *(int*)(a1 + 136));
}
