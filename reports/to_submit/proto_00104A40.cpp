// bin: proto
// va: 0x00104A40
// what: Passes the call on to the object this one holds.
// tool: Claude Fable 5.2 (look-alike of xb 0x000E5480, names and addresses swapped)
// AIActionStrengthenInvariant::vfunc_03 (0x00104A40, 8 bytes)
struct Field08
{
    void sub_00102FB0();
};

class AIActionStrengthenInvariant
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIActionStrengthenInvariant::vfunc_03()
{
    m_Field08->sub_00102FB0();
}
