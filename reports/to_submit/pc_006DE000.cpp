// bin: pc
// va: 0x006DE000
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerDirectInput::vfunc_07 (PC 0x006DE000, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08();
};

extern "C" char DAT_00771830[];

namespace core {

class ControllerDirectInput
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0x278];
    int m_Field27C; // +0x27C
};

int ControllerDirectInput::vfunc_07()
{
    int t1;

    t1 = m_Field27C;
    if (m_Field27C) {
        return ((Object*)t1)->vfunc_08();
    }
    return (int)DAT_00771830;
}

}
