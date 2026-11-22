// bin: pc
// va: 0x006E94F0
// what: 
// tool: the portal's starter code (no AI)

// sub_006E94F0 (PC 0x006E94F0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E94F0
{
public:
    int sub_006E94F0();
};

int Class_006E94F0::sub_006E94F0()
{
    int r_eax, r_ecx, r_edx, t1;

    r_ecx = (int)this;
    r_edx = *(int*)r_ecx;
L_04:
    *(int*)(r_ecx + 4) += 1;
    r_eax = *(int*)(r_ecx + 4);
    if ((unsigned int)r_eax < (unsigned int)*(unsigned short*)(r_edx + 12)) {
        t1 = *(int*)(*(int*)r_edx + (r_eax * 4));
        if (!*(int*)(*(int*)r_edx + (r_eax * 4))) goto L_04;
        if (t1 == (r_edx + 8)) goto L_04;
    }
    r_ecx = *(unsigned short*)(r_edx + 12);
    if ((unsigned int)r_eax >= (unsigned int)r_ecx) {
        r_eax = 0;
        return r_eax;
    }
    r_edx = *(int*)r_edx;
    r_eax = *(int*)(r_edx + (r_eax * 4));
    return r_eax;
}
