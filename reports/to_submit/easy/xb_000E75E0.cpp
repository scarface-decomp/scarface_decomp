// bin: xb
// va: 0x000E75E0
// tool: the portal's starter code (no AI)
// sub_000E75E0 (0x000E75E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E75E0
{
public:
    bool sub_000E75E0();
    char m_pad00[0x33];
    unsigned char m_Field33_bit0 : 1; // +0x33, bit 0
};

bool Class_000E75E0::sub_000E75E0()
{
    return m_Field33_bit0;
}
