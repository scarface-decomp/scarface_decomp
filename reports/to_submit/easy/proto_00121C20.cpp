// bin: proto
// va: 0x00121C20
// tool: the portal's starter code (no AI)
// sub_00121C20 (0x00121C20, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB4
{
    void sub_000B5200();
};

extern "C" float DAT_0037CE50;

class Class_00121C20
{
public:
    int sub_00121C20();
    char m_pad00[0xB4];
    FieldB4* m_FieldB4; // +0xB4
};

int Class_00121C20::sub_00121C20()
{
    FieldB4* t2;

    m_FieldB4->sub_000B5200();
    t2 = m_FieldB4;
    *(float*)((int)m_FieldB4 + 4) = 0.0f;
    *(float*)((int)m_FieldB4 + 8) = DAT_0037CE50;
    *(bool*)((int)m_FieldB4 + 12) = true;
    return (int)t2;
}
