// bin: xb
// va: 0x001DB2A0
// tool: the portal's starter code (no AI)
// sub_001DB2A0 (0x001DB2A0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002FAD0(int, int);

class Class_001DB2A0
{
public:
    int sub_001DB2A0();
    char m_pad00[0x7C];
    int m_Field7C; // +0x7C
    char m_pad80[0x4C];
    int m_FieldCC; // +0xCC
};

int Class_001DB2A0::sub_001DB2A0()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_eax = m_FieldCC;
    if (!r_eax) {
        r_eax |= -1;
        return r_eax;
    }
    r_eax -= 1;
    r_eax = sub_0002FAD0(0, r_eax);
    r_edx = r_eax;
    r_eax = 0;
    r_ecx = (int)(&m_Field7C);
L_26:
    if (*(unsigned char*)((int)this + r_eax + 136)) {
        if (*(unsigned char*)(*(int*)r_ecx + 22) & 127) goto L_3D;
        if (!r_edx) goto L_49;
        r_edx -= 1;
    }
L_3D:
    r_eax += 1;
    r_ecx += 4;
    if (r_eax < 3) goto L_26;
    r_eax |= -1;
L_49:
    return r_eax;
}
