// bin: pc
// va: 0x006E5E80
// tool: the portal's starter code (no AI)
// core::InstanceDrive::vfunc_03 (0x006E5E80, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_00772100[];
extern "C" char DAT_0077210C[];
extern "C" char DAT_0085CE14[];
extern "C" int DAT_0085CE2C;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual InstanceDrive* vfunc_03(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
};

InstanceDrive* InstanceDrive::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_0077210C;
    m_Field04 = (int)DAT_00772100;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CE14);
        ((Object*)DAT_0085CE2C)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CE14);
    }
    return this;
}

}
