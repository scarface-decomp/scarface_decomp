// bin: xb
// va: 0x001C4B30
// tool: the portal's starter code (no AI)
// sub_001C4B30 (0x001C4B30, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001C4B30
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    void sub_001C4B30(float a1);
    char m_pad04[0x4];
    float m_Field08; // +0x08
};

void Class_001C4B30::sub_001C4B30(float a1)
{
    m_Field08 = a1;
    vfunc_04();
}
