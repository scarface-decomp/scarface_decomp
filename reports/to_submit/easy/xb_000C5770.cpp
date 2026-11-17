// bin: xb
// va: 0x000C5770
// tool: the portal's starter code (no AI)
// sub_000C5770 (0x000C5770, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00087430(int);
};

struct Object
{
    void sub_00026EC0(int);
    void sub_00026EE0();
};

extern "C" void __cdecl sub_00014BE0(int);

class Class_000C5770
{
public:
    void sub_000C5770(int a1);
    void sub_000C55E0(int);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    Field10 m_Field10; // +0x10
    char m_pad11[0x17];
    bool m_Field28; // +0x28
};

void Class_000C5770::sub_000C5770(int a1)
{
    int local_4, t1;

    if (!m_Field28) goto L_2C;
    t1 = m_Field0C;
    if (m_Field0C) {
        if (!*(unsigned char*)t1) goto L_21;
        sub_00014BE0(t1);
    }
L_21:
    m_Field0C = 0;
    m_Field28 = false;
L_2C:
    ((Object*)(int)(&local_4))->sub_00026EC0(14);
    sub_000C55E0(a1);
    m_Field10.sub_00087430(a1);
    ((Object*)(int)(&local_4))->sub_00026EE0();
    m_Field28 = true;
}
