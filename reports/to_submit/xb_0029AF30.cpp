// bin: xb
// va: 0x0029AF30
// what: Returns bit 4 of the flags field at +0x3C.
// tool: Gemini 4 Neon

namespace pure3d {

class d3dDisplay
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
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual unsigned char vfunc_23();
    char m_pad04[0x38];
    unsigned int m_Field3C; // +0x3C
};

unsigned char d3dDisplay::vfunc_23()
{
    unsigned char v = (unsigned char)(m_Field3C >> 4);
    v &= 1;
    return v;
}

}
