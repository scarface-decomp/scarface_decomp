// SoundLocationObject (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field88;
class SoundLocationObject
{
public:
    virtual void* vfunc_00();
    virtual SoundLocationObject* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x84];
    Field88* m_Field88; // +0x88
    int m_Field8C; // +0x8C
};
