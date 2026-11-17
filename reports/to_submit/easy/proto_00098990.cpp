// bin: proto
// va: 0x00098990
// tool: the portal's starter code (no AI)
// sub_00098990 (0x00098990, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037F534;

class Class_00098990
{
public:
    void sub_00098990();
    char m_pad00[0xC];
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

void Class_00098990::sub_00098990()
{
    m_Field10 = m_Field0C * DAT_0037F534;
}
