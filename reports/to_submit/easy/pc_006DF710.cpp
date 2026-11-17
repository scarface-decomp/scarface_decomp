// bin: pc
// va: 0x006DF710
// tool: the portal's starter code (no AI)
// core::MemorySpaceAsyncRequest_Copy::vfunc_01 (0x006DF710, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class MemorySpaceAsyncRequest_Copy
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    int m_Field04; // +0x04
};

void MemorySpaceAsyncRequest_Copy::vfunc_01()
{
    m_Field04 += -1;
}

}
