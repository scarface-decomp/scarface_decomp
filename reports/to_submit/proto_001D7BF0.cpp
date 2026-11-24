// bin: proto
// va: 0x001D7BF0
// what: 
// tool: the portal's starter code (no AI)

// sub_001D7BF0 (Proto 0x001D7BF0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008C2E0(int);
};

class Class_001D7BF0
{
public:
    void sub_001D7BF0(int a1);
    char m_pad00[0x78];
    int m_Field78; // +0x78
};

void Class_001D7BF0::sub_001D7BF0(int a1)
{
    int t1;

    t1 = m_Field78;
    if (m_Field78) {
        ((Object*)t1)->sub_0008C2E0(a1);
        return;
    }
}
