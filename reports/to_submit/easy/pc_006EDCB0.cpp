// bin: pc
// va: 0x006EDCB0
// tool: the portal's starter code (no AI)
// sub_006EDCB0 (0x006EDCB0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EDCB0
{
public:
    Class_006EDCB0* sub_006EDCB0(int a1, bool a2);
    int m_Field00; // +0x00
    bool m_Field04; // +0x04
};

Class_006EDCB0* Class_006EDCB0::sub_006EDCB0(int a1, bool a2)
{
    m_Field00 = a1;
    m_Field04 = a2;
    return this;
}
