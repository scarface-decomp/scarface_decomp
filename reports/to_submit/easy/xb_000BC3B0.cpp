// bin: xb
// va: 0x000BC3B0
// tool: the portal's starter code (no AI)
// sub_000BC3B0 (0x000BC3B0, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00011770();
};

class Class_000BC3B0
{
public:
    void sub_000BC3B0(int a1, int a2);
    void sub_000B82B0(int, int);
    void sub_000BB6D0(int);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void Class_000BC3B0::sub_000BC3B0(int a1, int a2)
{
    int t2;

    if (a1) {
        m_Field14 = *(int*)(a1 + 12);
        sub_000B82B0(a1, a2);
        t2 = m_Field00;
        if (!m_Field00) goto L_44;
        if (!*(bool*)(a1 + 16)) goto L_44;
        m_Field08 = *(int*)(((Object*)*(int*)t2)->sub_00011770() + 44);
        sub_000BB6D0(m_Field10);
    }
L_44:
    ;
}
