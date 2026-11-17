// bin: xb
// va: 0x000AB570
// tool: the portal's starter code (no AI)
// sub_000AB570 (0x000AB570, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

class Class_000AB570
{
public:
    void sub_000AB570(int a1);
    char m_pad00[0x474];
    unsigned char m_Field474; // +0x474
    char m_pad475[0x3];
    int m_Field478; // +0x478
};

void Class_000AB570::sub_000AB570(int a1)
{
    int t1;

    if (m_Field474 != ((unsigned char)a1)) {
        m_Field474 = (unsigned char)a1;
        t1 = m_Field478;
        if (!m_Field478) goto L_24;
        a1 = a1;
        ((Object*)t1)->vfunc_00(a1);
        return;
    }
L_24:
    ;
}
