// bin: pc
// va: 0x006EFD30
// tool: the portal's starter code (no AI)
// sub_006EFD30 (0x006EFD30, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

bool __cdecl sub_006EFD30(int a1, bool a2)
{
    *(bool*)(a1 + 12) = a2;
    return a2;
}
