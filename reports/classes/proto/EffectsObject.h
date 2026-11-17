// EffectsObject (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class EffectsObject
{
public:
    virtual void* vfunc_00();
    virtual EffectsObject* vfunc_01(int a1);
    void sub_00027AE0();
    char m_pad04[0xA0];
    int m_FieldA4; // +0xA4
    char m_padA8[0x38];
    int m_FieldE0; // +0xE0
};
