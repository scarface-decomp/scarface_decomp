// bin: proto
// va: 0x000CE650
// what: 
// tool: the portal's starter code (no AI)

// sub_000CE650 (Proto 0x000CE650, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

float __cdecl sub_000CE650(int a1, float a2, int a3)
{
    if (a1 == a3) {
        return a2;
    }
    return (a2 * *(float*)(a3 + 12)) / *(float*)(a1 + 12);
}
