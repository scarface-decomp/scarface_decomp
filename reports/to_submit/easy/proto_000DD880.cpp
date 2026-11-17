// bin: proto
// va: 0x000DD880
// tool: the portal's starter code (no AI)
// sub_000DD880 (0x000DD880, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;

class Class_000DD880
{
public:
    void sub_000DD880(bool a1);
    char m_pad00[0x408];
    int m_Field408; // +0x408
    char m_pad40C[0x1F3];
    bool m_Field5FF; // +0x5FF
    bool m_Field600; // +0x600
};

void Class_000DD880::sub_000DD880(bool a1)
{
    if (!m_Field5FF) {
        m_Field5FF = true;
        m_Field600 = a1;
        m_Field408 = *(int*)(DAT_0045A0EC + 44);
    }
}
