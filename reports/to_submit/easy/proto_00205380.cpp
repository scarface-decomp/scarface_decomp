// bin: proto
// va: 0x00205380
// tool: the portal's starter code (no AI)
// core::ControllerOutputPointXBox::vfunc_07 (0x00205380, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;
extern "C" float DAT_0037CE50;

namespace core {

class ControllerOutputPointXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(float a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void ControllerOutputPointXBox::vfunc_07(float a1)
{
    if (a1 < DAT_0037CD94) {
        m_Field0C = 0;
        return;
    }
    if (a1 > DAT_0037CE50) {
        m_Field0C = 0x3F800000;
        return;
    }
    *(float*)((char*)this + 0xC) = a1;
}

}
