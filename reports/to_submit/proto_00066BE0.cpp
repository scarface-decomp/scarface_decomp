// bin: proto
// va: 0x00066BE0
// what: 
// tool: the portal's starter code (no AI)

// sub_00066BE0 (Proto 0x00066BE0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_00066BE0(int a1, int a2, int a3)
{
    int r_eax, r_edx;
    bool t1;

    r_eax = a3;
    r_eax = *(int*)(r_eax + 4);
    r_edx = r_eax + 1;
    do {
        t1 = *(bool*)r_eax;
        r_eax += 1;
    } while (t1);
    r_eax -= r_edx;
    return r_eax;
}
