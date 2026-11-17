// bin: pc
// va: 0x006EB580
// tool: the portal's starter code (no AI)
// content::LoadRequest::vfunc_03 (0x006EB580, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_00772428[];
extern "C" void __cdecl sub_006E9810(int);

namespace content {

class LoadRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadRequest* vfunc_03(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0x104];
    int m_Field124; // +0x124
};

LoadRequest* LoadRequest::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field18;
    *(int*)this = (int)DAT_00772428;
    if (m_Field18) {
        ((Object*)t1)->vfunc_01();
    }
    t3 = m_Field124;
    if (m_Field124) {
        ((Object*)t3)->vfunc_01();
    }
    t5 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t5)->vfunc_01();
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}
