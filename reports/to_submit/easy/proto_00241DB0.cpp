// bin: proto
// va: 0x00241DB0
// tool: the portal's starter code (no AI)
// sub_00241DB0 (0x00241DB0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025120(int);

class Class_00241DB0
{
public:
    void sub_00241DB0(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void Class_00241DB0::sub_00241DB0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_00025120(a1 * 4);
        m_Field0C = t1;
        if (!t1) goto L_37;
        m_Field14 = (a1 * 4) + t1;
        m_Field10 = t1;
        return;
    }
    m_Field0C = 0;
L_37:
    m_Field10 = 0;
    m_Field14 = 0;
}
