// bin: xb
// va: 0x0011CF70
// tool: the portal's starter code (no AI)
// sub_0011CF70 (0x0011CF70, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00113C70(int);

int __cdecl sub_0011CF70(int a1, int a2, int a3)
{
    return sub_00113C70(*(int*)(a3 + 4));
}
