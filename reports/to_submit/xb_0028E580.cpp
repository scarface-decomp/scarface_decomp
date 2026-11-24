// bin: xb
// va: 0x0028E580
// what: 
// tool: the portal's starter code (no AI)

// pure3d::Language::vfunc_03 (0x0028E580, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D88F8[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0023F7A0(int);

namespace pure3d {

class Language
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Language* vfunc_03(int a1);
    void sub_002A6940();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
};

Language* Language::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D88F8;
    sub_00027600(m_Field18);
    sub_00027600(m_Field1C);
    sub_00027600(m_Field20);
    sub_002A6940();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}
