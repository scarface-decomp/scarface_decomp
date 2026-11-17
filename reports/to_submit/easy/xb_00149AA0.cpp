// bin: xb
// va: 0x00149AA0
// tool: the portal's starter code (no AI)
// sub_00149AA0 (0x00149AA0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00149AA0
{
public:
    void sub_00149AA0(float a1);
    char m_pad00[0x2C];
    int m_Field2C; // +0x2C
    char m_pad30[0xC];
    float m_Field3C; // +0x3C
};

void Class_00149AA0::sub_00149AA0(float a1)
{
    int t2;

    m_Field3C = a1;
    t2 = sub_0002AC90(m_Field2C);
    if (t2) {
        *(float*)(t2 + 40) = a1;
    }
}
