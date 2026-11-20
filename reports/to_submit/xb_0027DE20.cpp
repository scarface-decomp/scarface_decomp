// bin: xb
// va: 0x0027DE20
// what: Passes the call on to an object held in a global pointer.
// tool: Claude Opus 5.5 (symcov hint: IkeSoundMgr::PropagateForAudio)
// pure3d::TextureFont::vfunc_17 (0x0027DE20)
// Class shape from reports/classes/xb/pure3d__TextureFont.h.
// pure3d is built with frame pointers (push ebp; mov ebp, esp), like the other pure3d functions.
#pragma optimize("y", off)

class Class_00492F00
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
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33(int a1);
};

extern "C" Class_00492F00 *DAT_00492F00;
namespace pure3d {
class TextureFont
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TextureFont* vfunc_03(unsigned int flags);
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
    virtual void vfunc_17(int a1);
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(float a1);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int a1);
    void sub_0027E1F0();
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    char m_pad20[0x4];
    int m_Field24; // +0x24
};
}

namespace pure3d {

// Forwards the argument to slot 33 of the global object.
void TextureFont::vfunc_17(int a1)
{
    DAT_00492F00->vfunc_33(a1);
}

}
