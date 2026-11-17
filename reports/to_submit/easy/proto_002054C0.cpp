// bin: proto
// va: 0x002054C0
// tool: the portal's starter code (no AI)
// core::ControllerInputPointXBox::vfunc_06 (0x002054C0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;
extern "C" float DAT_0037CE50;

namespace core {

class ControllerInputPointXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(float a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void ControllerInputPointXBox::vfunc_06(float a1)
{
    if (a1 < DAT_0037CD94) {
        m_Field14 = 0;
        return;
    }
    if (a1 > DAT_0037CE50) {
        m_Field14 = 0x3F800000;
        return;
    }
    *(float*)((char*)this + 0x14) = a1;
}

}
