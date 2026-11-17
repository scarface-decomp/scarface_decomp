// bin: xb
// va: 0x0020E6F0
// tool: the portal's starter code (no AI)
// VehicleRenderMaskTemplate::vfunc_04 (0x0020E6F0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0002B700(int);

class VehicleRenderMaskTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
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

void VehicleRenderMaskTemplate::vfunc_04(int a1)
{
    int t2;

    sub_0002B700(0);
    if (m_Field22) {
        t2 = m_Field30;
        m_Field24 = 65535;
        m_Field28 = 0;
        if (!m_Field30) goto L_35;
        if (!*(unsigned char*)t2) goto L_35;
        m_Field24 = m_Field20;
        m_Field28 = t2;
    }
L_35:
    ;
}
