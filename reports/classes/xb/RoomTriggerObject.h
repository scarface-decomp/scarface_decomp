// RoomTriggerObject (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class RoomTriggerObject
{
public:
    virtual void* vfunc_00();
    virtual RoomTriggerObject* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};
