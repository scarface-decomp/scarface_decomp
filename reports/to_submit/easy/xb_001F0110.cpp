// bin: xb
// va: 0x001F0110
// tool: the portal's starter code (no AI)
// sub_001F0110 (0x001F0110, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00088580(int, int);
};

class Class_001F0110
{
public:
    void sub_001F0110(int a1, int a2);
    char m_pad00[0xC8];
    int m_FieldC8; // +0xC8
};

void Class_001F0110::sub_001F0110(int a1, int a2)
{
    int t1;

    *(float*)(a2 + 8) = 0.0f;
    *(float*)(a2 + 4) = 0.0f;
    *(float*)a2 = 0.0f;
    t1 = m_FieldC8;
    if (m_FieldC8) {
        a2 = a2;
        ((Object*)t1)->sub_00088580(a1, a2);
        return;
    }
}
