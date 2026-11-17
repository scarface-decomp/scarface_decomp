// NISManager (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class NISManager
{
public:
    virtual NISManager* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, int a2, int a3);
    void sub_000BC010(int, int);
    void sub_000BC060(int, int);
    int sub_000BC360(int, int);
    void sub_000BCB90(int, int);
    char m_pad04[0xE0];
    int m_FieldE4; // +0xE4
};
