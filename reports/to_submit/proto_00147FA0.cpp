// bin: proto
// va: 0x00147FA0
// what: 
// tool: the portal's starter code (no AI)

// sub_00147FA0 (Proto 0x00147FA0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D73C0(int);
};

class Class_00147FA0
{
public:
    void sub_00147FA0(int a1);
    char m_pad00[0x3E0];
    int m_Field3E0; // +0x3E0
};

void Class_00147FA0::sub_00147FA0(int a1)
{
    ((Object*)(int)(&a1))->sub_000D73C0(a1);
    m_Field3E0 = a1;
}
