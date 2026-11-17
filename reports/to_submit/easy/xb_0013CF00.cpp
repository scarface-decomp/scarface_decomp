// bin: xb
// va: 0x0013CF00
// tool: the portal's starter code (no AI)
// sub_0013CF00 (0x0013CF00, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldA0
{
    void sub_000C2AE0();
};

extern "C" float DAT_0039D664;

class Class_0013CF00
{
public:
    int sub_0013CF00();
    char m_pad00[0xA0];
    FieldA0* m_FieldA0; // +0xA0
};

int Class_0013CF00::sub_0013CF00()
{
    FieldA0* t2;

    m_FieldA0->sub_000C2AE0();
    t2 = m_FieldA0;
    *(float*)((int)m_FieldA0 + 4) = 0.0f;
    *(float*)((int)m_FieldA0 + 8) = DAT_0039D664;
    *(bool*)((int)m_FieldA0 + 12) = true;
    return (int)t2;
}
