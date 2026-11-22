// bin: pc
// va: 0x006FE7D0
// what: 
// tool: the portal's starter code (no AI)

// sub_006FE7D0 (PC 0x006FE7D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006FE7D0(int a1, int a2)
{
    *(int*)a2 = *(int*)(a1 + 4);
    *(int*)(a1 + 12) += -1;
    *(int*)(a1 + 4) = a2;
    return a1;
}
