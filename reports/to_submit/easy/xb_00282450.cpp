// bin: xb
// va: 0x00282450
// tool: the portal's starter code (no AI)
// pure3d::CharacterPose::vfunc_06 (0x00282450, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

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
    void sub_00281F40(int);
    void sub_00281FA0(int);
    void sub_00282090(int);
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
    int r_edi;

    r_edi = a1;
    if (!(m_Field2C & 5)) {
        if (a1) goto L_21;
        if (m_Field1D & 1) goto L_21;
        if (!m_Field28) goto L_24;
    }
L_21:
    m_Field0C += 1;
L_24:
    if (m_Field1D & 2) {
        sub_00281FA0(r_edi);
        sub_00281F40(r_edi);
        vfunc_07(r_edi);
        sub_00282090(r_edi);
        m_Field1D &= 253;
    }
}

}
