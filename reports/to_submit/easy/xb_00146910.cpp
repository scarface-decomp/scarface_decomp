// bin: xb
// va: 0x00146910
// tool: the portal's starter code (no AI)
// sub_00146910 (0x00146910, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00146910
{
public:
    void sub_00146910(float a1);
    char m_pad00[0x28];
    int m_Field28; // +0x28
    char m_pad2C[0x14];
    float m_Field40; // +0x40
};

void Class_00146910::sub_00146910(float a1)
{
    int t2;

    m_Field40 = a1;
    t2 = sub_0002AC90(m_Field28);
    if (t2) {
        *(float*)(t2 + 40) = a1;
    }
}
