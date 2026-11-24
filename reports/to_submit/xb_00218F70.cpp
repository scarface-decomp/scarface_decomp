// bin: xb
// va: 0x00218F70
// what: 
// tool: the portal's starter code (no AI)

// sub_00218F70 (0x00218F70, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00218070(int);
};

class Class_00218F70
{
public:
    void sub_00218F70(int a1);
    char m_pad00[0xC4];
    int m_FieldC4; // +0xC4
};

void Class_00218F70::sub_00218F70(int a1)
{
    int t1;

    t1 = m_FieldC4;
    if (m_FieldC4) {
        ((Object*)t1)->sub_00218070(a1);
        return;
    }
}
