// bin: proto
// va: 0x001D7C00
// what: 
// tool: the portal's starter code (no AI)

// sub_001D7C00 (Proto 0x001D7C00, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001D7C00
{
public:
    bool sub_001D7C00();
    char m_pad00[0x78];
    int m_Field78; // +0x78
};

bool Class_001D7C00::sub_001D7C00()
{
    int t1;

    t1 = m_Field78;
    if (m_Field78) {
        return *(int*)t1 != 4;
    }
    return false;
}
