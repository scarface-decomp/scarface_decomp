// bin: proto
// va: 0x0023D9D0
// tool: the portal's starter code (no AI)
// pure3d::CharacterPose::vfunc_09 (0x0023D9D0, 32 bytes)
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
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(bool a1);
    char m_pad04[0x19];
    unsigned char m_Field1D; // +0x1D
    char m_pad1E[0xE];
    unsigned char m_Field2C; // +0x2C
};

void CharacterPose::vfunc_09(bool a1)
{
    if (a1) {
        m_Field1D |= 1;
        m_Field2C = (unsigned char)(((unsigned char)(m_Field2C & 254)) | 6);
        return;
    }
    m_Field2C &= 254;
}

}
