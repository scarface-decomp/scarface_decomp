// bin: xb
// va: 0x001E0580
// tool: the portal's starter code (no AI)
// sub_001E0580 (0x001E0580, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002FAD0(int, int);

class Class_001E0580
{
public:
    int sub_001E0580();
    char m_pad00[0x8C];
    int m_Field8C; // +0x8C
    char m_pad90[0x8];
    int m_Field98; // +0x98
};

int Class_001E0580::sub_001E0580()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_eax = m_Field98;
    if (!r_eax) {
        r_eax |= -1;
        return r_eax;
    }
    r_eax -= 1;
    r_eax = sub_0002FAD0(0, r_eax);
    r_edx = r_eax;
    r_eax = 0;
    r_ecx = (int)(&m_Field8C);
L_30:
    if (*(unsigned char*)((int)this + r_eax + 144)) {
        if (*(unsigned char*)(*(int*)r_ecx + 22) & 127) goto L_47;
        if (!r_edx) goto L_53;
        r_edx -= 1;
    }
L_47:
    r_eax += 1;
    r_ecx += 4;
    if (r_eax < 1) goto L_30;
    r_eax |= -1;
L_53:
    return r_eax;
}
