// bin: proto
// va: 0x001E5A10
// what: 
// tool: the portal's starter code (no AI)

// sub_001E5A10 (Proto 0x001E5A10, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E43C0(int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_001E5A10(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = 0;
    if (a2 > 1) {
        r_eax = a3;
        r_eax = sub_002C96FE(*(int*)(r_eax + 4));
    }
    sub_001E43C0(r_eax, 1);
}
