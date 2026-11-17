// bin: xb
// va: 0x00296D70
// tool: the portal's starter code (no AI)
// pure3d::xboxOceanRenderer::vfunc_07 (0x00296D70, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field10
{
    void sub_002B7A40(int);
    void sub_002B7D40();
};

extern "C" bool DAT_0045C0A0;

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
};

void xboxOceanRenderer::vfunc_07(int a1)
{
    if (a1) {
        if (!m_Field10) goto L_2B;
        m_Field10->sub_002B7A40(a1);
        if (!DAT_0045C0A0) goto L_2B;
        m_Field10->sub_002B7D40();
    }
L_2B:
    ;
}

}
