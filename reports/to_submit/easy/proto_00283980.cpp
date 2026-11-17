// bin: proto
// va: 0x00283980
// tool: the portal's starter code (no AI)
// core::XboxSaveDrive::vfunc_15 (0x00283980, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0028EC30(int, int, int);
};

namespace core {

class XboxSaveDrive
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
    virtual int vfunc_15(int a1, int a2, int a3);
};

int XboxSaveDrive::vfunc_15(int a1, int a2, int a3)
{
    a3 = a2;
    a2 = a1;
    a1 = (int)this;
    return ((Object*)(int)this + 220)->sub_0028EC30(a1, a2, a3);
}

}
