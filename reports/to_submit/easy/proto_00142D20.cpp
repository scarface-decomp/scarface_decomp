// bin: proto
// va: 0x00142D20
// tool: the portal's starter code (no AI)
// sub_00142D20 (0x00142D20, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000C6C10(int);
};

class Class_00142D20
{
public:
    void sub_00142D20();
    char m_pad00[0xB8];
    int m_FieldB8; // +0xB8
    char m_padBC[0xE];
    bool m_FieldCA; // +0xCA
};

void Class_00142D20::sub_00142D20()
{
    int t1;

    if (!m_FieldCA) {
        t1 = m_FieldB8;
        m_FieldCA = true;
        ((Object*)*(int*)(*(int*)(t1 + 392) + 384))->sub_000C6C10(1);
    }
}
