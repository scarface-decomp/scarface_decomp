// bin: proto
// va: 0x001062C0
// what: Passes the call on to the object this one holds.
// tool: Claude Fable 5.2 (look-alike of xb 0x000E5480, names and addresses swapped)
// AIConditionSampleIsPlaying::vfunc_04 (0x001062C0, 8 bytes)
struct Field08
{
    void sub_001479D0();
};

class AIConditionSampleIsPlaying
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIConditionSampleIsPlaying::vfunc_04()
{
    m_Field08->sub_001479D0();
}
