// bin: xb
// va: 0x00012A20
// tool: the portal's starter code (no AI)
// CollisionBehaviourTypeGroup::vfunc_02 (0x00012A20, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CollisionBehaviourTypeGroup
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02();
    char m_pad04[0x1A];
    unsigned char : 2;
    unsigned char m_Field1E_bit2 : 1; // +0x1E, bit 2
};

bool CollisionBehaviourTypeGroup::vfunc_02()
{
    return m_Field1E_bit2;
}
