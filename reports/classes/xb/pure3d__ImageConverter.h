// pure3d::ImageConverter (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class ImageConverter
{
public:
    virtual ImageConverter* vfunc_00(unsigned int flags);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int, int);
};
}
