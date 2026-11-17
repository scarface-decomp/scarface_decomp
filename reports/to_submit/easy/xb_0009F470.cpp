// bin: xb
// va: 0x0009F470
// tool: the portal's starter code (no AI)
// sub_0009F470 (0x0009F470, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A00FC;

class Class_0009F470
{
public:
    void sub_0009F470();
    char m_pad00[0x1C];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
};

void Class_0009F470::sub_0009F470()
{
    float t1;

    t1 = DAT_003A00FC;
    m_Field20 = m_Field1C * t1;
    m_Field28 = m_Field24 * t1;
}
