// bin: xb
// va: 0x00212EC0
// what: 
// tool: the portal's starter code (no AI)

// sub_00212EC0 (0x00212EC0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00097AF0(int);
};

class Class_00212EC0
{
public:
    void sub_00212EC0(int a1);
    char m_pad00[0x74];
    int m_Field74; // +0x74
};

void Class_00212EC0::sub_00212EC0(int a1)
{
    int t1;

    t1 = m_Field74;
    if (m_Field74) {
        ((Object*)t1)->sub_00097AF0(a1);
        return;
    }
}
