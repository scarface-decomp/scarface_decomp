// bin: proto
// va: 0x000800F0
// what: 
// tool: the portal's starter code (no AI)

// sub_000800F0 (Proto 0x000800F0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003FDE64;

float __cdecl sub_000800F0(int a1)
{
    a1 = a1 & 63;
    return ((float)a1) * DAT_003FDE64;
}
