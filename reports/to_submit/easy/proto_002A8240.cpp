// bin: proto
// va: 0x002A8240
// tool: the portal's starter code (no AI)
// audio::SeqActionVarPitch::vfunc_06 (0x002A8240, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    int m_Field04; // +0x04
};

void SeqActionVarPitch::vfunc_06(int a1)
{
    *(int*)(*(int*)(a1 + 4) + 40) = m_Field04 + 48;
}

}
