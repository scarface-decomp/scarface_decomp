// bin: pc
// va: 0x006E78E0
// tool: the portal's starter code (no AI)
// core::Win32Drive::vfunc_09 (0x006E78E0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006E74F0(void);

namespace core {

class Win32Drive
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
    virtual int vfunc_09();
    char m_pad04[0x74];
    int m_Field78; // +0x78
    char m_pad7C[0x50];
    int m_FieldCC; // +0xCC
    char m_padD0[0xC];
    int m_FieldDC; // +0xDC
    char m_padE0[0x14];
    int m_FieldF4; // +0xF4
};

int Win32Drive::vfunc_09()
{
    if (m_FieldDC) {
        if (sub_006E74F0() == m_FieldF4) goto L_43;
        if (m_FieldCC != 4) {
            m_FieldCC = 3;
            m_Field78 = 3;
        }
        return 0;
    }
    sub_006E74F0();
    m_FieldF4 = 0;
L_43:
    return !m_FieldCC;
}

}
