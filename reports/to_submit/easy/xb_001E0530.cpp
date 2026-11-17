// bin: xb
// va: 0x001E0530
// tool: the portal's starter code (no AI)
// sub_001E0530 (0x001E0530, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002FAD0(int, int);

class Class_001E0530
{
public:
    int sub_001E0530();
    char m_pad00[0x78];
    int m_Field78; // +0x78
    char m_pad7C[0xC];
    int m_Field88; // +0x88
};

int Class_001E0530::sub_001E0530()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_eax = m_Field88;
    if (!r_eax) {
        r_eax |= -1;
        return r_eax;
    }
    r_eax -= 1;
    r_eax = sub_0002FAD0(0, r_eax);
    r_edx = r_eax;
    r_eax = 0;
    r_ecx = (int)(&m_Field78);
L_26:
    if (*(unsigned char*)((int)this + r_eax + 129)) {
        if (*(unsigned char*)(*(int*)r_ecx + 22) & 127) goto L_3D;
        if (!r_edx) goto L_49;
        r_edx -= 1;
    }
L_3D:
    r_eax += 1;
    r_ecx += 4;
    if (r_eax < 2) goto L_26;
    r_eax |= -1;
L_49:
    return r_eax;
}
