// bin: xb
// va: 0x000A4CE0
// tool: the portal's starter code (no AI)
// sub_000A4CE0 (0x000A4CE0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BB8A0(int, int);
};

class Class_000A4CE0
{
public:
    void sub_000A4CE0(int a1);
    int m_Field00; // +0x00
};

void Class_000A4CE0::sub_000A4CE0(int a1)
{
    int t1;

    t1 = m_Field00;
    if (m_Field00) {
        ((Object*)(int)this + 32)->sub_000BB8A0(a1, t1);
    }
}
