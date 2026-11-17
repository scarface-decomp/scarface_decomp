// bin: xb
// va: 0x00217620
// tool: the portal's starter code (no AI)
// sub_00217620 (0x00217620, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00217620
{
public:
    bool sub_00217620();
    char m_pad00[0xE9];
    unsigned char m_FieldE9_bit0 : 1; // +0xE9, bit 0
};

bool Class_00217620::sub_00217620()
{
    return m_FieldE9_bit0;
}
