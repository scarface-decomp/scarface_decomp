// bin: pc
// va: 0x007002F0
// tool: the portal's starter code (no AI)
// sub_007002F0 (0x007002F0, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006F16C0(int);

class Class_007002F0
{
public:
    int sub_007002F0(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x1C];
    int m_Field2C; // +0x2C
    unsigned char m_Field30; // +0x30
};

int Class_007002F0::sub_007002F0(int a1)
{
    int r_eax;

    if (a1) {
        r_eax = m_Field0C;
        if (r_eax) {
            r_eax = sub_006F16C0(r_eax);
            if (r_eax != 2) goto L_3B;
            if (m_Field30) goto L_3B;
            r_eax = m_Field0C;
            *(int*)a1 = r_eax;
            m_Field0C = 0;
            goto L_3B;
        }
        *(int*)a1 = 0;
    }
L_3B:
    r_eax = 5;
    if (m_Field2C != 5) {
        m_Field2C = 5;
    }
    return r_eax;
}
