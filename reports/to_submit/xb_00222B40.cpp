// bin: xb
// va: 0x00222B40
// what: 
// tool: the portal's starter code (no AI)

// sub_00222B40 (0x00222B40, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00221070(int, int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_00222B40(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = 0;
    if (a2 > 1) {
        r_eax = a3;
        r_eax = sub_002FC43E(*(int*)(r_eax + 4));
    }
    sub_00221070(r_eax, 1);
}
