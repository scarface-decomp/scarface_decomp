// bin: proto
// va: 0x002066C0
// tool: the portal's starter code (no AI)
// sub_002066C0 (0x002066C0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025120(int);

class Class_002066C0
{
public:
    void sub_002066C0(int a1);
    char m_pad00[0x38];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
};

void Class_002066C0::sub_002066C0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_00025120(a1 * 4);
        m_Field38 = t1;
        if (!t1) goto L_37;
        m_Field40 = (a1 * 4) + t1;
        m_Field3C = t1;
        return;
    }
    m_Field38 = 0;
L_37:
    m_Field3C = 0;
    m_Field40 = 0;
}
