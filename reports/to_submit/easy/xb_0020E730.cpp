// bin: xb
// va: 0x0020E730
// tool: the portal's starter code (no AI)
// VehicleRenderMaskTemplate::vfunc_10 (0x0020E730, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class VehicleRenderMaskTemplate
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    unsigned short m_Field24; // +0x24
    char m_pad26[0x2];
    int m_Field28; // +0x28
    char m_pad2C[0x4];
    int m_Field30; // +0x30
};

void VehicleRenderMaskTemplate::vfunc_10()
{
    int t1;

    if (!m_Field22) {
        t1 = m_Field30;
        m_Field22 = true;
        if (!m_Field30) goto L_22;
        if (!*(unsigned char*)t1) goto L_22;
        m_Field24 = m_Field20;
        m_Field28 = t1;
    }
L_22:
    ;
}
