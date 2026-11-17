// bin: proto
// va: 0x0001F9E0
// tool: the portal's starter code (no AI)
// sub_0001F9E0 (0x0001F9E0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0008D490(int);
};

struct Object
{
    void sub_001B7A10();
};

class Class_0001F9E0
{
public:
    void sub_0001F9E0(int a1, float a2);
    char m_pad00[0x10];
    Field10 m_Field10; // +0x10
    char m_pad11[0x3];
    float m_Field14; // +0x14
};

void Class_0001F9E0::sub_0001F9E0(int a1, float a2)
{
    m_Field10.sub_0008D490((int)(&a1));
    m_Field14 = a2;
    ((Object*)(int)(&a1))->sub_001B7A10();
}
