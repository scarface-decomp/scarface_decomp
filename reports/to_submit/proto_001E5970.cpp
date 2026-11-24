// bin: proto
// va: 0x001E5970
// what: 
// tool: the portal's starter code (no AI)

// sub_001E5970 (Proto 0x001E5970, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001E2F00(int);
extern "C" void __cdecl sub_001E4190(int);

void __cdecl sub_001E5970(int a1, int a2, int a3)
{
    sub_001E4190(sub_001E2F00(*(int*)(a3 + 4)));
}
