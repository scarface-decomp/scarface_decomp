// bin: proto
// va: 0x001467C0
// tool: the portal's starter code (no AI)
// sub_001467C0 (0x001467C0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_001467C0(int a1, bool a2, float a3)
{
    *(bool*)a1 = a2;
    *(float*)(a1 + 4) = a3;
    return a1;
}
