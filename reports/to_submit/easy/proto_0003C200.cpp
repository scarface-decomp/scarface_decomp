// bin: proto
// va: 0x0003C200
// tool: the portal's starter code (no AI)
// sub_0003C200 (0x0003C200, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FEEF0(int);
};

extern "C" char sub_0003AB40[];
extern "C" char sub_0003C170[];

class Class_0003C200
{
public:
    void sub_0003C200();
    char m_pad00[0x30];
    int m_Field30; // +0x30
    char m_pad34[0x38];
    bool m_Field6C; // +0x6C
    bool m_Field6D; // +0x6D
    bool m_Field6E; // +0x6E
};

void Class_0003C200::sub_0003C200()
{
    if (m_Field6C) {
        ((Object*)m_Field30 + 576)->sub_001FEEF0((int)sub_0003C170);
        m_Field6C = false;
    }
    if (m_Field6D) {
        ((Object*)m_Field30 + 588)->sub_001FEEF0((int)sub_0003C170);
        m_Field6D = false;
    }
    if (m_Field6E) {
        ((Object*)m_Field30 + 600)->sub_001FEEF0((int)sub_0003AB40);
        m_Field6E = false;
    }
}
