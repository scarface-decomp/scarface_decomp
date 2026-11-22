// bin: proto
// va: 0x0011E030
// what: 
// tool: the portal's starter code (no AI)

// sub_0011E030 (Proto 0x0011E030, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

float __cdecl sub_0011E030(float a1, float a2, float a3, float a4, float a5)
{
    if (a1 >= a4) {
        return (a2 * a4) + a5;
    }
    if (a3 >= a1) {
        return (a2 * a3) + a5;
    }
    return (a1 * a2) + a5;
}
