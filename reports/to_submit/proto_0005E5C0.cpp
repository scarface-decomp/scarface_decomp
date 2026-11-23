// bin: proto
// va: 0x0005E5C0
// what: 
// tool: the portal's starter code (no AI)

// sub_0005E5C0 (Proto 0x0005E5C0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0005D430(int, int, int, int);

void __cdecl sub_0005E5C0(int a1, int a2, int a3)
{
    int r_ecx, r_edx, r_esi;

    r_edx = *(int*)(a3 + 4);
    r_esi = *(int*)(a3 + 8);
    r_ecx = 0;
    if (a2 > 3) {
        r_ecx = *(int*)(a3 + 12);
    }
    sub_0005D430(r_edx, r_esi, r_ecx, 0);
}
