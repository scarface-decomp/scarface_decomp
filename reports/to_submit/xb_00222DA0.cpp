// bin: xb
// va: 0x00222DA0
// what: 
// tool: the portal's starter code (no AI)

// sub_00222DA0 (0x00222DA0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0021FC50(int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_00222DA0(int a1, int a2, int a3)
{
    sub_0021FC50(sub_002FC43E(*(int*)(a3 + 4)));
}
