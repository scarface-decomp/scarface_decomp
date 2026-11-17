// bin: xb
// va: 0x002D72C0
// tool: the portal's starter code (no AI)
// sub_002D72C0 (0x002D72C0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_002D4D90(int);
};

struct Object
{
    void sub_002D05F0();
    void sub_002D0610();
};

class Class_002D72C0
{
public:
    void sub_002D72C0(int a1);
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x1F];
    bool m_Field34; // +0x34
    bool m_Field35; // +0x35
};

void Class_002D72C0::sub_002D72C0(int a1)
{
    m_Field14.sub_002D4D90(a1 + 16);
    if (m_Field35) {
        ((Object*)*(int*)(a1 + 32))->sub_002D05F0();
    }
    if (m_Field34) {
        ((Object*)*(int*)(a1 + 32))->sub_002D0610();
    }
}
