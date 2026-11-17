// bin: proto
// va: 0x001C5130
// tool: the portal's starter code (no AI)
// VehicleDropObjectProperties::vfunc_05 (0x001C5130, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0041AFBC;
extern "C" void __stdcall sub_00028C40(int);

class VehicleDropObjectProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x40];
    float m_Field44; // +0x44
    float m_Field48; // +0x48
};

void VehicleDropObjectProperties::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field44 = m_Field48 * DAT_0041AFBC;
}
