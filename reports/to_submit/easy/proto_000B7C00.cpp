// bin: proto
// va: 0x000B7C00
// tool: the portal's starter code (no AI)
// sub_000B7C00 (0x000B7C00, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0007CF10(int);
};

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
};

extern "C" void __cdecl sub_00015510(int);

class Class_000B7C00
{
public:
    void sub_000B7C00(int a1);
    void sub_000B7A70(int);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    Field10 m_Field10; // +0x10
    char m_pad11[0x17];
    bool m_Field28; // +0x28
};

void Class_000B7C00::sub_000B7C00(int a1)
{
    int local_4, t1;

    if (!m_Field28) goto L_2C;
    t1 = m_Field0C;
    if (m_Field0C) {
        if (!*(unsigned char*)t1) goto L_21;
        sub_00015510(t1);
    }
L_21:
    m_Field0C = 0;
    m_Field28 = false;
L_2C:
    ((Object*)(int)(&local_4))->sub_00024AB0(14);
    sub_000B7A70(a1);
    m_Field10.sub_0007CF10(a1);
    ((Object*)(int)(&local_4))->sub_00024AD0();
    m_Field28 = true;
}
