// bin: proto
// va: 0x0023DA00
// tool: the portal's starter code (no AI)
// pure3d::CharacterPose::vfunc_06 (0x0023DA00, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class CharacterPose
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    virtual void vfunc_07(int);
    void sub_0023D540(int);
    void sub_0023D5A0(int);
    void sub_0023D680(int);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xD];
    unsigned char m_Field1D; // +0x1D
    char m_pad1E[0xA];
    int m_Field28; // +0x28
    unsigned char m_Field2C; // +0x2C
};

void CharacterPose::vfunc_06(int a1)
{
    if (!(m_Field2C & 5)) {
        if (a1) goto L_1F;
        if (m_Field1D & 1) goto L_1F;
        if (!m_Field28) goto L_22;
    }
L_1F:
    m_Field0C += 1;
L_22:
    if (m_Field1D & 2) {
        sub_0023D5A0(a1);
        sub_0023D540(a1);
        vfunc_07(a1);
        sub_0023D680(a1);
        m_Field1D &= 253;
    }
}

}
