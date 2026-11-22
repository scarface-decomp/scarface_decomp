// bin: proto
// va: 0x002A7060
// what: Writes the address 48 bytes into this action's data into the object it is given.
// tool: Claude Opus 5.5 (transplanted from pc:0x006F9310, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarVolume
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

void SeqActionVarVolume::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04 + 48;
    *(int*)(*(int*)(a1 + 4) + 36) = m_Field04 + 48;
}

}