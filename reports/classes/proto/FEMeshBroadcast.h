// FEMeshBroadcast (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class FEMeshBroadcast
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual FEMeshBroadcast* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    virtual float vfunc_06();
    char m_pad04[0xC];
    float m_Field10; // +0x10
    int m_Field14; // +0x14
};
