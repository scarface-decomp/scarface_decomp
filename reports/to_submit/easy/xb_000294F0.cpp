// bin: xb
// va: 0x000294F0
// tool: the portal's starter code (no AI)
// GameObject::vfunc_18 (0x000294F0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameObject
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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual bool vfunc_18();
    char m_pad04[0x1A];
    unsigned char : 3;
    unsigned char m_Field1E_bit3 : 1; // +0x1E, bit 3
};

bool GameObject::vfunc_18()
{
    return m_Field1E_bit3;
}
