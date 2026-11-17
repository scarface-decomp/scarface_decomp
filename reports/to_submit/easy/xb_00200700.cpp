// bin: xb
// va: 0x00200700
// tool: the portal's starter code (no AI)
// VehicleDropObjectProperties::vfunc_04 (0x00200700, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_004416F8;
extern "C" void __stdcall sub_0002B700(int);

class VehicleDropObjectProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x40];
    float m_Field44; // +0x44
    float m_Field48; // +0x48
};

void VehicleDropObjectProperties::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field44 = m_Field48 * DAT_004416F8;
}
