// bin: xb
// va: 0x000B7FE0
// tool: the portal's starter code (no AI)
// sub_000B7FE0 (0x000B7FE0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B7FE0
{
public:
    virtual int vfunc_00(int);
    bool sub_000B7FE0(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

bool Class_000B7FE0::sub_000B7FE0(int a1)
{
    int r_ecx, r_edi, t3;

    r_ecx = (int)this;
    if (!a1) {
        return false;
    }
    r_edi = 0;
    if (m_Field08 > 0) {
        do {
            r_ecx = (int)this;
            if (a1 == vfunc_00(r_edi)) {
                r_ecx = m_Field04;
                if (!*(unsigned char*)(r_edi + r_ecx)) goto L_44;
            }
            t3 = m_Field08;
            r_edi += 1;
        } while (r_edi < t3);
    }
    return false;
L_44:
    return true;
}
