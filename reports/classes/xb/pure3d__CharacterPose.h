// pure3d::CharacterPose (xb): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class CharacterPose
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CharacterPose* vfunc_03(unsigned int flags);
    virtual int vfunc_04(int a1);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(bool a1);
    virtual void vfunc_10();
    void sub_00282360();
    char m_pad04[0x19];
    unsigned char m_Field1D; // +0x1D
    char m_pad1E[0x6];
    int m_Field24; // +0x24
    char m_pad28[0x4];
    unsigned char m_Field2C; // +0x2C
};
}
