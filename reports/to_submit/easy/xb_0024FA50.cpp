// bin: xb
// va: 0x0024FA50
// tool: the portal's starter code (no AI)
// sub_0024FA50 (0x0024FA50, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int);
};

class Class_0024FA50
{
public:
    void sub_0024FA50(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x88];
    char m_Field98; // +0x98
};

void Class_0024FA50::sub_0024FA50(int a1)
{
    int r_edi, r_esi;
    char t2;

    r_esi = 0;
    if (m_Field98 > 0) {
        r_edi = (int)(&m_Field0C);
        do {
            ((Object*)*(int*)r_edi)->vfunc_07(a1);
            t2 = m_Field98;
            r_esi += 1;
            r_edi += 4;
        } while (r_esi < t2);
    }
}
