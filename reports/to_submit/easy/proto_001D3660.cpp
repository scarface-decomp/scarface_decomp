// bin: proto
// va: 0x001D3660
// tool: the portal's starter code (no AI)
// VehicleRenderMaskTemplate::vfunc_11 (0x001D3660, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D1720(void);

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
    virtual void vfunc_11();
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x9];
    unsigned short m_Field2C; // +0x2C
    char m_pad2E[0x2];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
};

void VehicleRenderMaskTemplate::vfunc_11()
{
    int t2;

    if (!m_Field22) {
        sub_001D1720();
        t2 = m_Field38;
        if (!m_Field38) goto L_26;
        if (!*(unsigned char*)t2) goto L_26;
        m_Field2C = m_Field20;
        m_Field30 = t2;
    }
L_26:
    ;
}
