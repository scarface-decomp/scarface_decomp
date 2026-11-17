// bin: xb
// va: 0x000E7F20
// tool: the portal's starter code (no AI)
// sub_000E7F20 (0x000E7F20, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" char DAT_003A8274[];
extern "C" void __cdecl sub_00022990(void);

class Class_000E7F20
{
public:
    Class_000E7F20* sub_000E7F20();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
};

Class_000E7F20* Class_000E7F20::sub_000E7F20()
{
    float t2;

    sub_00022990();
    t2 = DAT_0039D65C;
    m_Field00 = (int)DAT_003A8274;
    m_Field1C = t2;
    m_Field20 = t2;
    return this;
}
