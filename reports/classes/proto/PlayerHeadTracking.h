// PlayerHeadTracking (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class PlayerHeadTracking
{
public:
    virtual void* vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(int a1);
    bool sub_00145370(int);
    bool sub_00145410(int);
    bool sub_001457B0(int);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
};
