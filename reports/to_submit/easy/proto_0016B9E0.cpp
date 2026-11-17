// bin: proto
// va: 0x0016B9E0
// tool: the portal's starter code (no AI)
// GenericBarMeter::vfunc_01 (0x0016B9E0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0040F2BC;

class GenericBarMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(float a1);
    float m_Field04; // +0x04
    char m_pad08[0x18];
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    bool m_Field28; // +0x28
};

void GenericBarMeter::vfunc_01(float a1)
{
    if (m_Field28) {
        m_Field04 = ((m_Field24 / DAT_0040F2BC) * m_Field20) + m_Field04;
        m_Field24 = 0.0f;
    }
    m_Field20 = a1 - m_Field04;
    m_Field28 = true;
}
