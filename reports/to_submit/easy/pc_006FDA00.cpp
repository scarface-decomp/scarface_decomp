// bin: pc
// va: 0x006FDA00
// tool: the portal's starter code (no AI)
// sub_006FDA00 (0x006FDA00, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006FDA00
{
public:
    unsigned short sub_006FDA00();
    char m_pad00[0x34];
    unsigned short m_Field34; // +0x34
};

unsigned short Class_006FDA00::sub_006FDA00()
{
    return m_Field34;
}
