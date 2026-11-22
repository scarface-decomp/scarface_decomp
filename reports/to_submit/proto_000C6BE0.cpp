// bin: proto
// va: 0x000C6BE0
// what: 
// tool: the portal's starter code (no AI)

// sub_000C6BE0 (Proto 0x000C6BE0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000C6BE0
{
public:
    void sub_000C6BE0(bool a1);
    char m_pad00[0x236];
    unsigned char m_Field236; // +0x236
};

void Class_000C6BE0::sub_000C6BE0(bool a1)
{
    unsigned char t1;

    t1 = m_Field236;
    if (((unsigned char)(m_Field236 >> 7)) != a1) {
        m_Field236 = (unsigned char)(((unsigned char)(t1 & 127)) | ((unsigned char)(a1 << 7)));
    }
}
