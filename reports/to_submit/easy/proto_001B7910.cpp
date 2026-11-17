// bin: proto
// va: 0x001B7910
// tool: the portal's starter code (no AI)
// StatePropWaterCollisionBehaviour::vfunc_02 (0x001B7910, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class StatePropWaterCollisionBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x8];
    bool m_Field0C; // +0x0C
    char m_pad0D[0x3];
    float m_Field10; // +0x10
};

void StatePropWaterCollisionBehaviour::vfunc_02()
{
    float t1;

    t1 = DAT_0037CE60;
    m_Field0C = false;
    m_Field10 = t1;
}
