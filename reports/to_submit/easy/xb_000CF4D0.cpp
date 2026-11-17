// bin: xb
// va: 0x000CF4D0
// tool: the portal's starter code (no AI)
// sub_000CF4D0 (0x000CF4D0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CF4D0
{
public:
    bool sub_000CF4D0();
    char m_pad00[0x198];
    unsigned char : 2;
    unsigned char m_Field198_bit2 : 1; // +0x198, bit 2
};

bool Class_000CF4D0::sub_000CF4D0()
{
    return m_Field198_bit2;
}
