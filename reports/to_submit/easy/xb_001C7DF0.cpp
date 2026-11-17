// bin: xb
// va: 0x001C7DF0
// tool: the portal's starter code (no AI)
// sub_001C7DF0 (0x001C7DF0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00244450(int, int);

class Class_001C7DF0
{
public:
    void sub_001C7DF0(int a1);
    char m_pad00[0x10];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void Class_001C7DF0::sub_001C7DF0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_00244450(9, a1 * 8);
        m_Field10 = t1;
        if (!t1) goto L_39;
        m_Field18 = (a1 * 8) + t1;
        m_Field14 = t1;
        return;
    }
    m_Field10 = 0;
L_39:
    m_Field14 = 0;
    m_Field18 = 0;
}
