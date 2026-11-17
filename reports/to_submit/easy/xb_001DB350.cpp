// bin: xb
// va: 0x001DB350
// tool: the portal's starter code (no AI)
// sub_001DB350 (0x001DB350, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002FAD0(int, int);

class Class_001DB350
{
public:
    int sub_001DB350();
    char m_pad00[0xB0];
    int m_FieldB0; // +0xB0
    char m_padB4[0x28];
    int m_FieldDC; // +0xDC
};

int Class_001DB350::sub_001DB350()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_eax = m_FieldDC;
    if (!r_eax) {
        r_eax |= -1;
        return r_eax;
    }
    r_eax -= 1;
    r_eax = sub_0002FAD0(0, r_eax);
    r_edx = r_eax;
    r_eax = 0;
    r_ecx = (int)(&m_FieldB0);
L_30:
    if (*(unsigned char*)((int)this + r_eax + 184)) {
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
