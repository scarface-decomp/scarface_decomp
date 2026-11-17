// bin: proto
// va: 0x0020DEA0
// tool: the portal's starter code (no AI)
// sub_0020DEA0 (0x0020DEA0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00201440(int, int);

void __cdecl sub_0020DEA0(int a1)
{
    int r_eax;

    r_eax = a1;
    if (*(unsigned char*)r_eax == 92) {
        r_eax += 1;
    }
    sub_00201440(r_eax, 0);
}
