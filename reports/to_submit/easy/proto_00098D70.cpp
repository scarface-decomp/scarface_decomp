// bin: proto
// va: 0x00098D70
// tool: the portal's starter code (no AI)
// sub_00098D70 (0x00098D70, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000AE210(int, int);
};

class Class_00098D70
{
public:
    void sub_00098D70(int a1);
    int m_Field00; // +0x00
};

void Class_00098D70::sub_00098D70(int a1)
{
    int t1;

    t1 = m_Field00;
    if (m_Field00) {
        ((Object*)(int)this + 32)->sub_000AE210(a1, t1);
    }
}
