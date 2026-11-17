// bin: xb
// va: 0x000E99B0
// tool: the portal's starter code (no AI)
// sub_000E99B0 (0x000E99B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E99B0
{
public:
    bool sub_000E99B0();
    char m_pad00[0x1C];
    unsigned char m_Field1C_bit0 : 1; // +0x1C, bit 0
};

bool Class_000E99B0::sub_000E99B0()
{
    return m_Field1C_bit0;
}
