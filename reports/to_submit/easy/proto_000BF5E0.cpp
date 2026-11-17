// bin: proto
// va: 0x000BF5E0
// tool: the portal's starter code (no AI)
// sub_000BF5E0 (0x000BF5E0, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000BF5E0
{
public:
    void sub_000BF5E0(int a1);
    char m_pad00[0x84];
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
    char m_pad90[0x4];
    int m_Field94; // +0x94
    int m_Field98; // +0x98
    int m_Field9C; // +0x9C
    char m_padA0[0xFC];
    unsigned char m_Field19C; // +0x19C
};

void Class_000BF5E0::sub_000BF5E0(int a1)
{
    unsigned char t1;

    m_Field94 = *(int*)a1;
    m_Field98 = *(int*)(a1 + 4);
    m_Field9C = *(int*)(a1 + 8);
    m_Field84 = *(int*)a1;
    m_Field88 = *(int*)(a1 + 4);
    m_Field8C = *(int*)(a1 + 8);
    t1 = m_Field19C;
    if (!(m_Field19C & 2)) {
        m_Field19C = (unsigned char)(t1 & 254);
    }
}
