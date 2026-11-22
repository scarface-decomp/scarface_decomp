// bin: proto
// va: 0x000502C0
// what: 
// tool: the portal's starter code (no AI)

// sub_000502C0 (Proto 0x000502C0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044A59C[];

int __cdecl sub_000502C0(int a1)
{
    int r_eax, r_ecx;

    r_ecx = a1;
    r_eax = 0;
L_06:
    if (DAT_0044A59C[r_eax] != r_ecx) {
        r_eax += 1;
        if ((unsigned int)r_eax < (unsigned int)8) goto L_06;
        return r_eax;
    }
    r_ecx = DAT_0044A59C[r_eax];
    *(bool*)(r_ecx + 1664) = false;
    *(float*)(DAT_0044A59C[r_eax] + 1660) = 0.0f;
    return r_eax;
}
