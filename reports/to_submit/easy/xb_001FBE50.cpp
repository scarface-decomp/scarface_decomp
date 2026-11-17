// bin: xb
// va: 0x001FBE50
// tool: the portal's starter code (no AI)
// ExplosionTemplate::vfunc_10 (0x001FBE50, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    int sub_00021640();
};

class ExplosionTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    void sub_001FBCA0();
    char m_pad04[0x1C];
    short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    Field28 m_Field28; // +0x28
    char m_pad29[0x33];
    int m_Field5C; // +0x5C
    char m_pad60[0x24];
    int m_Field84; // +0x84
};

void ExplosionTemplate::vfunc_10()
{
    int r_eax;

    r_eax = m_Field22;
    if ((unsigned char)r_eax) goto L_43;
    r_eax = m_Field84;
    if (r_eax) {
        if (*(unsigned char*)r_eax) goto L_1C;
    }
    r_eax = m_Field5C;
L_1C:
    if (r_eax) {
        if (*(unsigned char*)r_eax) goto L_38;
    }
    if (m_Field20 < 0) {
        r_eax = m_Field28.sub_00021640();
        if ((unsigned char)r_eax) goto L_43;
    }
L_38:
    sub_001FBCA0();
    m_Field22 = true;
L_43:
    ;
}
