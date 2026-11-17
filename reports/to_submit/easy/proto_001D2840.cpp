// bin: proto
// va: 0x001D2840
// tool: the portal's starter code (no AI)
// VehicleRenderMaskTemplate::vfunc_12 (0x001D2840, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D1760(void);

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
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x9];
    unsigned short m_Field2C; // +0x2C
    char m_pad2E[0x2];
    int m_Field30; // +0x30
};

void VehicleRenderMaskTemplate::vfunc_12()
{
    if (m_Field22) {
        sub_001D1760();
        m_Field2C = 65535;
        m_Field30 = 0;
    }
}
