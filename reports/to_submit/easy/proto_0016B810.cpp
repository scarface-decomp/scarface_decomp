// bin: proto
// va: 0x0016B810
// tool: the portal's starter code (no AI)
// GenericP3DMeter::vfunc_01 (0x0016B810, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0040F2BC;

class GenericP3DMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(float a1);
    float m_Field04; // +0x04
    char m_pad08[0x10];
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    bool m_Field20; // +0x20
};

void GenericP3DMeter::vfunc_01(float a1)
{
    if (m_Field20) {
        m_Field04 = ((m_Field1C / DAT_0040F2BC) * m_Field18) + m_Field04;
        m_Field1C = 0.0f;
    }
    m_Field18 = a1 - m_Field04;
    m_Field20 = true;
}
