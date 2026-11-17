// bin: xb
// va: 0x0005D0D0
// tool: the portal's starter code (no AI)
// renderer::TraceFireRenderable::vfunc_09 (0x0005D0D0, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_0041DB40;

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
    char m_pad04[0x80];
    int m_Field84; // +0x84
    int m_Field88; // +0x88
};

void TraceFireRenderable::vfunc_09(int a1)
{
    int r_edi, r_edx, r_esi, t3, t6;
    float t1, t2;

    r_esi = 0;
    if (m_Field88 <= 0) goto L_5A;
    t1 = DAT_0041DB40;
    t2 = DAT_0039D664;
    r_edi = a1;
    r_edx = 0;
L_24:
    t3 = m_Field84 + r_edx;
    if (t2 > *(float*)(m_Field84 + r_edx)) {
        if (*(float*)t3 >= t2) goto L_4B;
        *(float*)t3 = (*(float*)(r_edi + 8) / t1) + *(float*)t3;
    }
L_4B:
    t6 = m_Field88;
    r_esi += 1;
    r_edx += 76;
    if (r_esi < t6) goto L_24;
L_5A:
    ;
}

}
