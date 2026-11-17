// bin: xb
// va: 0x00033AC0
// tool: the portal's starter code (no AI)
// sub_00033AC0 (0x00033AC0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000275B0(int, int);

class Class_00033AC0
{
public:
    int sub_00033AC0(int a1, int a2);
    char m_pad00[0xC];
    short m_Field0C; // +0x0C
    char m_pad0E[0x32];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

int Class_00033AC0::sub_00033AC0(int a1, int a2)
{
    int r_eax, t2, t3;

    r_eax = m_Field44;
    if (!r_eax) {
        r_eax = m_Field0C;
        m_Field40 = r_eax;
        r_eax <<= 2;
        r_eax = sub_000275B0(r_eax, 11);
        t2 = m_Field40;
        m_Field44 = r_eax;
        r_eax = 0;
        if (t2 <= 0) goto L_40;
        do {
            *(float*)(m_Field44 + (r_eax * 4)) = 0.0f;
            t3 = m_Field40;
            r_eax += 1;
        } while (r_eax < t3);
    }
L_40:
    r_eax = *(int*)a1;
    *(int*)(m_Field44 + (r_eax * 4)) = *(int*)a2;
    return r_eax;
}
