// bin: proto
// va: 0x00053030
// tool: the portal's starter code (no AI)
// renderer::TraceFireRenderable::vfunc_09 (0x00053030, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

namespace renderer {

class TraceFireRenderable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(int a1);
    void sub_00052E50(int, int);
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

void TraceFireRenderable::vfunc_09(int a1)
{
    int r_ebp, r_ebx, r_edi, t2, t4;
    float t1;

    r_ebx = 0;
    if (m_Field84 > 0) {
        r_ebp = a1;
        r_edi = 0;
        do {
            t1 = DAT_0037CE50;
            t2 = m_Field80 + r_edi;
            if (t1 > *(float*)(m_Field80 + r_edi + 40)) {
                sub_00052E50(t2, r_ebp);
            }
            t4 = m_Field84;
            r_ebx += 1;
            r_edi += 116;
        } while (r_ebx < t4);
    }
}

}
