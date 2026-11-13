// bin: xb
// va: 0x001078B0
// what: Passes the call on to the object this one holds.
// tool: Claude Fable 5.2 (look-alike of 0x000E5480, names and addresses swapped)
// LazyEvaluatorOnSidewalk::vfunc_00 (0x001078B0, 8 bytes)
struct Field08
{
    void sub_00164C90();
};

class LazyEvaluatorOnSidewalk
{
public:
    virtual void vfunc_00();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void LazyEvaluatorOnSidewalk::vfunc_00()
{
    m_Field08->sub_00164C90();
}
