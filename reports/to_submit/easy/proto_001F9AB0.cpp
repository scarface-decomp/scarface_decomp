// bin: proto
// va: 0x001F9AB0
// tool: the portal's starter code (no AI)
// sub_001F9AB0 (0x001F9AB0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FCEA0(int, int, int);

class Class_001F9AB0
{
public:
    void sub_001F9AB0(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
    char m_pad11[0x103];
    int m_Field114; // +0x114
};

void Class_001F9AB0::sub_001F9AB0(int a1)
{
    int t2;

    if (!m_Field10) {
        sub_001FCEA0((int)(((char*)this + 0x11)), 256, a1);
        t2 = m_Field0C;
        m_Field10 = true;
        m_Field114 = t2;
    }
}
