// EffectsObject (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class EffectsObject
{
public:
    virtual void* vfunc_00();
    virtual EffectsObject* vfunc_01(int a1);
    void sub_0002A3A0();
    char m_pad04[0xA8];
    int m_FieldAC; // +0xAC
    char m_padB0[0x38];
    int m_FieldE8; // +0xE8
};
