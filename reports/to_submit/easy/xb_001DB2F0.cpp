// bin: xb
// va: 0x001DB2F0
// tool: the portal's starter code (no AI)
// sub_001DB2F0 (0x001DB2F0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002FAD0(int, int);

class Class_001DB2F0
{
public:
    int sub_001DB2F0();
    char m_pad00[0xA4];
    int m_FieldA4; // +0xA4
    char m_padA8[0x2C];
    int m_FieldD4; // +0xD4
};

int Class_001DB2F0::sub_001DB2F0()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_eax = m_FieldD4;
    if (!r_eax) {
        r_eax |= -1;
        return r_eax;
    }
    r_eax -= 1;
    r_eax = sub_0002FAD0(0, r_eax);
    r_edx = r_eax;
    r_eax = 0;
    r_ecx = (int)(&m_FieldA4);
L_30:
    if (*(unsigned char*)((int)this + r_eax + 172)) {
        if (*(unsigned char*)(*(int*)r_ecx + 22) & 127) goto L_47;
        if (!r_edx) goto L_53;
        r_edx -= 1;
    }
L_47:
    r_eax += 1;
    r_ecx += 4;
    if (r_eax < 2) goto L_30;
    r_eax |= -1;
L_53:
    return r_eax;
}
