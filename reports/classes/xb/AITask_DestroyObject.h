// AITask_DestroyObject (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Driver;
class AITask_DestroyObject
{
public:
    virtual void* vfunc_00();
    virtual AITask_DestroyObject* vfunc_01(unsigned int flags);
    void sub_0002C720();
    char m_pad04[0x34];
    int m_target; // +0x38
    int m_lastTarget; // +0x3C
    char m_pad40[0x4];
    Driver* m_driver; // +0x44
};
