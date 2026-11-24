// bin: proto
// va: 0x001E5890
// what: 
// tool: the portal's starter code (no AI)

// sub_001E5890 (Proto 0x001E5890, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001E2F00(int);

int __cdecl sub_001E5890(int a1, int a2, int a3)
{
    return sub_001E2F00(*(int*)(a3 + 4));
}
