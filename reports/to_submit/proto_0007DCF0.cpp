// bin: proto
// va: 0x0007DCF0
// what: 
// tool: the portal's starter code (no AI)

// sub_0007DCF0 (Proto 0x0007DCF0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000ABE20(int);
};

class Class_0007DCF0
{
public:
    void sub_0007DCF0(int a1);
    char m_pad00[0xB0];
    int m_FieldB0; // +0xB0
};

void Class_0007DCF0::sub_0007DCF0(int a1)
{
    m_FieldB0 = a1;
    if (a1) {
        a1 = a1 + 84;
        ((Object*)(int)this + 256)->sub_000ABE20(a1);
        return;
    }
}
