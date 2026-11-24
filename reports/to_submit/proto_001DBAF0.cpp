// bin: proto
// va: 0x001DBAF0
// what: 
// tool: the portal's starter code (no AI)

// sub_001DBAF0 (Proto 0x001DBAF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009F460(int, int);
    void sub_0009F4B0(int, int);
};

class Class_001DBAF0
{
public:
    void sub_001DBAF0(int a1);
    char m_pad00[0xBC];
    int m_FieldBC; // +0xBC
};

void Class_001DBAF0::sub_001DBAF0(int a1)
{
    ((Object*)m_FieldBC + 72)->sub_0009F460(a1, 0);
    ((Object*)m_FieldBC + 72)->sub_0009F4B0(a1, 0x3C23D70A);
}
