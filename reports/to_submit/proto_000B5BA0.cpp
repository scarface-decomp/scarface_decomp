// bin: proto
// va: 0x000B5BA0
// what: 
// tool: the portal's starter code (no AI)

// sub_000B5BA0 (Proto 0x000B5BA0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B5BA0
{
public:
    void sub_000B5BA0(int a1, int a2);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_000B5BA0::sub_000B5BA0(int a1, int a2)
{
    int t1;

    t1 = m_Field04;
    if (m_Field04) {
        *(int*)(t1 + 8) = a1;
        *(int*)(t1 + 28) = a1;
        m_Field08 = a2;
        return;
    }
    m_Field08 = a2;
}
