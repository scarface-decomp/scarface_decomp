// bin: proto
// va: 0x001DD2E0
// what: 
// tool: the portal's starter code (no AI)

// sub_001DD2E0 (Proto 0x001DD2E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001DC8E0();
};

class Class_001DD2E0
{
public:
    void sub_001DD2E0();
    char m_pad00[0xBC];
    int m_FieldBC; // +0xBC
};

void Class_001DD2E0::sub_001DD2E0()
{
    int t1;

    t1 = m_FieldBC;
    if (m_FieldBC) {
        ((Object*)t1)->sub_001DC8E0();
        return;
    }
}
