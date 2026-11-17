// bin: proto
// va: 0x0003ACD0
// tool: the portal's starter code (no AI)
// sub_0003ACD0 (0x0003ACD0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FEEF0(int);
};

extern "C" char sub_0003AB40[];

class Class_0003ACD0
{
public:
    void sub_0003ACD0();
    char m_pad00[0x30];
    int m_Field30; // +0x30
    char m_pad34[0x16];
    bool m_Field4A; // +0x4A
    char m_pad4B[0x3];
    bool m_Field4E; // +0x4E
    char m_pad4F[0x2];
    bool m_Field51; // +0x51
};

void Class_0003ACD0::sub_0003ACD0()
{
    if (m_Field4A) {
        ((Object*)m_Field30 + 168)->sub_001FEEF0((int)sub_0003AB40);
        m_Field4A = false;
    }
    if (m_Field4E) {
        ((Object*)m_Field30 + 216)->sub_001FEEF0((int)sub_0003AB40);
        m_Field4E = false;
    }
    if (m_Field51) {
        ((Object*)m_Field30 + 252)->sub_001FEEF0((int)sub_0003AB40);
        m_Field51 = false;
    }
}
