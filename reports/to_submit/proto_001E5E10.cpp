// bin: proto
// va: 0x001E5E10
// what: 
// tool: the portal's starter code (no AI)

// sub_001E5E10 (Proto 0x001E5E10, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008B070(int);
};

class Class_001E5E10
{
public:
    void sub_001E5E10(int a1);
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

void Class_001E5E10::sub_001E5E10(int a1)
{
    int t1;

    t1 = m_Field20;
    if (m_Field20) {
        ((Object*)t1)->sub_0008B070(a1);
        return;
    }
}
