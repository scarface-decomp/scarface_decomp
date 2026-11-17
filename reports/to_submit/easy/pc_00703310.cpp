// bin: pc
// va: 0x00703310
// tool: the portal's starter code (no AI)
// pure3d::d3dDevice::vfunc_08 (0x00703310, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00654130(int, int);
};

extern "C" int __cdecl sub_0043CE00(int);

namespace pure3d {

class d3dDevice
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

int d3dDevice::vfunc_08(int a1)
{
    int local_4, t2;

    vfunc_04((int)(&local_4));
    t2 = sub_0043CE00(564);
    if (t2) {
        return ((Object*)t2)->sub_00654130(m_Field14 + (((a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8) + a1 + (a1 * 8)) - a1) * 4), m_Field18);
    }
    return 0;
}

}
