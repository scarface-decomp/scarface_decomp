// bin: proto
// va: 0x000BF400
// tool: the portal's starter code (no AI)
// sub_000BF400 (0x000BF400, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000BF400
{
public:
    void sub_000BF400();
    char m_pad00[0x11C];
    int m_Field11C; // +0x11C
    int m_Field120; // +0x120
    char m_pad124[0x78];
    unsigned char m_Field19C; // +0x19C
};

void Class_000BF400::sub_000BF400()
{
    m_Field11C = 0;
    m_Field120 = 0;
    m_Field19C &= 254;
}
