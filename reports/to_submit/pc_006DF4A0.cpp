// bin: pc
// va: 0x006DF4A0
// what: 
// tool: the portal's starter code (no AI)

// LoadSet::vfunc_00 (PC 0x006DF4A0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class LoadSet
{
public:
    virtual void vfunc_00();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void LoadSet::vfunc_00()
{
    m_Field14 += 1;
}
