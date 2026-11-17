// bin: xb
// va: 0x001652C0
// tool: the portal's starter code (no AI)
// CharacterObject::vfunc_10 (0x001652C0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CharacterObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    char m_pad04[0x1A];
    unsigned char m_Field1E; // +0x1E
};

void CharacterObject::vfunc_10()
{
    unsigned char t1;

    t1 = m_Field1E;
    if (!(m_Field1E & 16)) {
        m_Field1E = (unsigned char)(t1 | 16);
        vfunc_04(1);
    }
}
