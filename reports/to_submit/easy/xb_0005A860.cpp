// bin: xb
// va: 0x0005A860
// tool: the portal's starter code (no AI)
// sub_0005A860 (0x0005A860, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00475990[];

int __cdecl sub_0005A860(int a1)
{
    int r_eax, r_ecx;

    r_ecx = a1;
    r_eax = 0;
L_06:
    if (DAT_00475990[r_eax] != r_ecx) {
        r_eax += 1;
        if ((unsigned int)r_eax < (unsigned int)48) goto L_06;
        return r_eax;
    }
    r_ecx = DAT_00475990[r_eax];
    *(bool*)(r_ecx + 1664) = false;
    *(float*)(DAT_00475990[r_eax] + 1660) = 0.0f;
    return r_eax;
}
