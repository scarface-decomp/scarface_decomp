// bin: proto
// va: 0x00148890
// tool: the portal's starter code (no AI)
// CharacterObject::vfunc_11 (0x00148890, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CharacterObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    char m_pad04[0x71];
    bool m_Field75; // +0x75
};

void CharacterObject::vfunc_11()
{
    if (!m_Field75) {
        m_Field75 = true;
        vfunc_05(1);
    }
}
