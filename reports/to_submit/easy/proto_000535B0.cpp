// bin: proto
// va: 0x000535B0
// tool: the portal's starter code (no AI)
// renderer::VehicleContainer::vfunc_18 (0x000535B0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace renderer {

class VehicleContainer
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(float a1);
    char m_pad04[0xCC];
    float m_FieldD0; // +0xD0
};

void VehicleContainer::vfunc_18(float a1)
{
    m_FieldD0 = a1;
}

}
