// bin: xb
// va: 0x002EEBF0
// tool: the portal's starter code (no AI)
// sub_002EEBF0 (0x002EEBF0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_002EEBF0(int a1, int a2)
{
    int r_eax, r_ecx, r_edi, r_edx;
    unsigned short t1;

    r_edi = 0;
    r_edx = a1;
    r_eax = a2;
    if (a1 == a2) goto L_48;
    r_ecx = r_edx + 2;
    if (r_ecx == a2) goto L_48;
L_14:
    if (*(unsigned short*)r_edx != *(unsigned short*)r_ecx) {
        r_edx = r_ecx;
        r_ecx += 2;
        if (r_ecx != r_eax) goto L_14;
        return r_eax;
    }
    r_ecx += 2;
    if (r_ecx != r_eax) {
        do {
            t1 = *(unsigned short*)r_ecx;
            if (*(unsigned short*)r_edx != *(unsigned short*)r_ecx) {
                r_edx += 2;
                *(unsigned short*)r_edx = t1;
            }
            r_ecx += 2;
        } while (r_ecx != r_eax);
    }
    r_eax = r_edx + 2;
L_48:
    return r_eax;
}
