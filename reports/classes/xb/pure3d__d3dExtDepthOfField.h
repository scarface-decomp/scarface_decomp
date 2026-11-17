// pure3d::d3dExtDepthOfField (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dExtDepthOfField
{
public:
    virtual d3dExtDepthOfField* vfunc_00(unsigned int flags);
    virtual void vfunc_01();
    virtual bool vfunc_02(bool a1);
    void sub_002A1720();
    char m_pad04[0x4A];
    bool m_Field4E; // +0x4E
};
}
