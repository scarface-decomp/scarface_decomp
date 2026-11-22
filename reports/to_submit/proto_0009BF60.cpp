// bin: proto
// va: 0x0009BF60
// what: 
// tool: the portal's starter code (no AI)

// sub_0009BF60 (Proto 0x0009BF60, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009B410(int, int);
};

class Class_0009BF60
{
public:
    void sub_0009BF60(int a1);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_0009BF60::sub_0009BF60(int a1)
{
    int t1;

    if (a1) {
        t1 = m_Field08;
        if (!m_Field08) goto L_26;
        if (!*(unsigned char*)t1) goto L_26;
        m_Field04 = ((Object*)a1)->sub_0009B410(t1, 1);
        return;
    }
L_26:
    m_Field04 = -1;
}
