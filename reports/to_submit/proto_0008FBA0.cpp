// bin: proto
// va: 0x0008FBA0
// what: 
// tool: the portal's starter code (no AI)

// AirplanePlaneCollisionReceiver::vfunc_03 (Proto 0x0008FBA0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual bool vfunc_12();
};

class AirplanePlaneCollisionReceiver
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual bool vfunc_03();
    Field04* m_Field04; // +0x04
    char m_pad08[0x8];
    bool m_Field10; // +0x10
};

bool AirplanePlaneCollisionReceiver::vfunc_03()
{
    if (m_Field10) {
        return m_Field04->vfunc_12();
    }
    return true;
}
