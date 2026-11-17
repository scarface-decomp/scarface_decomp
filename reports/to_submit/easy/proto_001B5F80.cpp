// bin: proto
// va: 0x001B5F80
// tool: the portal's starter code (no AI)
// sub_001B5F80 (0x001B5F80, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0007E280(int, int);
};

class Class_001B5F80
{
public:
    void sub_001B5F80(int a1, int a2);
    char m_pad00[0xC0];
    int m_FieldC0; // +0xC0
};

void Class_001B5F80::sub_001B5F80(int a1, int a2)
{
    int t1;

    *(float*)(a2 + 8) = 0.0f;
    *(float*)(a2 + 4) = 0.0f;
    *(float*)a2 = 0.0f;
    t1 = m_FieldC0;
    if (m_FieldC0) {
        a2 = a2;
        ((Object*)t1)->sub_0007E280(a1, a2);
        return;
    }
}
