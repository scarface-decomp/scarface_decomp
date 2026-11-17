// bin: proto
// va: 0x00249480
// tool: the portal's starter code (no AI)
// sub_00249480 (0x00249480, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025120(int);

class Class_00249480
{
public:
    void sub_00249480(int a1);
    char m_pad00[0x14];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

void Class_00249480::sub_00249480(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_00025120(a1 * 4);
        m_Field14 = t1;
        if (!t1) goto L_37;
        m_Field1C = (a1 * 4) + t1;
        m_Field18 = t1;
        return;
    }
    m_Field14 = 0;
L_37:
    m_Field18 = 0;
    m_Field1C = 0;
}
