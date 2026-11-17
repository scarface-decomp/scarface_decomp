// bin: proto
// va: 0x0022FF40
// tool: the portal's starter code (no AI)
// pure3d::TextureFont::vfunc_21 (0x0022FF40, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

namespace pure3d {

class TextureFont
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
    virtual void vfunc_21(float a1);
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
};

void TextureFont::vfunc_21(float a1)
{
    if (a1 > DAT_0037CD94) {
        m_Field1C = a1;
        return;
    }
    *(int*)((char*)this + 0x1C) = 0;
}

}
