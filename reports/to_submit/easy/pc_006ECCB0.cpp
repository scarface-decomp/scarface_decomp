// bin: pc
// va: 0x006ECCB0
// tool: the portal's starter code (no AI)
// GlobalVehicleSound::vfunc_00 (0x006ECCB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
};

void GlobalVehicleSound::vfunc_00()
{
    m_Field20 += 1;
}
