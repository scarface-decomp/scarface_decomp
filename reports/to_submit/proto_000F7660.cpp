// bin: proto
// va: 0x000F7660
// what: 
// tool: the portal's starter code (no AI)

// sub_000F7660 (Proto 0x000F7660, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000F7660
{
public:
    int sub_000F7660(int a1, int a2);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};

int Class_000F7660::sub_000F7660(int a1, int a2)
{
    m_Field34 = a1;
    m_Field38 = a2;
    m_Field30 = 1;
    return a1;
}
