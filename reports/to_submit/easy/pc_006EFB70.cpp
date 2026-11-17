// bin: pc
// va: 0x006EFB70
// tool: the portal's starter code (no AI)
// sub_006EFB70 (0x006EFB70, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFB70(int a1, float a2)
{
    *(float*)(a1 + 16) = a2;
    return a1;
}
