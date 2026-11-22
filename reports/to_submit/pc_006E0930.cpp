// bin: pc
// va: 0x006E0930
// what: 
// tool: the portal's starter code (no AI)

// core::MemoryDlAllocator::vfunc_00 (PC 0x006E0930, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class MemoryDlAllocator
{
public:
    virtual void vfunc_00();
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};

void MemoryDlAllocator::vfunc_00()
{
    m_Field3C += 1;
}

}
