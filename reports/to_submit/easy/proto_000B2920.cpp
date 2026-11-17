// bin: proto
// va: 0x000B2920
// tool: the portal's starter code (no AI)
// sub_000B2920 (0x000B2920, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);

class Class_000B2920
{
public:
    void sub_000B2920();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x1C];
    int m_Field28; // +0x28
};

void Class_000B2920::sub_000B2920()
{
    int t1, t3, t5;

    if (m_Field00 > 0) {
        t1 = m_Field28;
        if (m_Field28) {
            sub_00025160(t1);
            m_Field28 = 0;
        }
        t3 = m_Field04;
        if (m_Field04) {
            sub_00025160(t3);
            m_Field04 = 0;
        }
        t5 = m_Field08;
        if (m_Field08) {
            sub_00025160(t5);
            m_Field08 = 0;
        }
        m_Field00 = 0;
    }
}
