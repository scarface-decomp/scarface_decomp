// bin: xb
// va: 0x00260F70
// what: 
// tool: the portal's starter code (no AI)

// pure3d::Ocean::vfunc_03 (0x00260F70, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D5F28[];
extern "C" int DAT_004BC0C8;
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class Ocean
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Ocean* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Ocean* Ocean::vfunc_03(int a1)
{
    int t3;

    *(int*)this = (int)DAT_003D5F28;
    sub_00027600(m_Field08);
    sub_00027600(m_Field0C);
    t3 = m_Field10;
    if (m_Field10) {
        ((Object*)t3)->vfunc_00(1);
    }
    DAT_004BC0C8 = 0;
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}
