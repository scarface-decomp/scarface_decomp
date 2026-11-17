// bin: xb
// va: 0x000C6B40
// tool: the portal's starter code (no AI)
// sub_000C6B40 (0x000C6B40, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    void sub_000C5F30(int);
    void sub_000C5FD0(int, int, int, int);
};

class Class_000C6B40
{
public:
    void sub_000C6B40(bool a1, bool a2);
    int sub_000C67E0();
    char m_pad00[0x5C];
    Field5C* m_Field5C; // +0x5C
    int m_Field60; // +0x60
    int m_Field64; // +0x64
    char m_pad68[0x8];
    char m_Field70; // +0x70
    char m_Field71; // +0x71
};

void Class_000C6B40::sub_000C6B40(bool a1, bool a2)
{
    m_Field70 = a1;
    if (!a2) {
        m_Field5C->sub_000C5F30(0);
        m_Field60 = 2;
        m_Field71 = 0;
        m_Field5C->sub_000C5FD0(m_Field70, m_Field71, m_Field64, sub_000C67E0());
    }
}
