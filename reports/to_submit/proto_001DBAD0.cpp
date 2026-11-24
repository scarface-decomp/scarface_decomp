// bin: proto
// va: 0x001DBAD0
// what: 
// tool: the portal's starter code (no AI)

// sub_001DBAD0 (Proto 0x001DBAD0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001DBAD0
{
public:
    int sub_001DBAD0(float a1);
    char m_pad00[0xBC];
    int m_FieldBC; // +0xBC
};

int Class_001DBAD0::sub_001DBAD0(float a1)
{
    int t1;

    t1 = m_FieldBC;
    *(float*)(m_FieldBC + 200) = a1;
    return t1;
}
