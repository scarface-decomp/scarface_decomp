// bin: xb
// va: 0x000C3430
// tool: the portal's starter code (no AI)
// sub_000C3430 (0x000C3430, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000C3430
{
public:
    void sub_000C3430();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

void Class_000C3430::sub_000C3430()
{
    float t1;

    t1 = DAT_0039D65C;
    m_Field0C = 0;
    m_Field10 = t1;
}
