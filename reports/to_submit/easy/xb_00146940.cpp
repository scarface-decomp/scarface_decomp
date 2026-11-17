// bin: xb
// va: 0x00146940
// tool: the portal's starter code (no AI)
// sub_00146940 (0x00146940, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0013CFE0(float);
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_00146940
{
public:
    void sub_00146940(float a1);
    char m_pad00[0x28];
    int m_Field28; // +0x28
    char m_pad2C[0x18];
    float m_Field44; // +0x44
};

void Class_00146940::sub_00146940(float a1)
{
    int t2;

    m_Field44 = a1;
    t2 = sub_0002AC90(m_Field28);
    if (t2) {
        ((Object*)t2)->sub_0013CFE0(a1);
        return;
    }
}
