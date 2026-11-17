// bin: xb
// va: 0x000E85E0
// tool: the portal's starter code (no AI)
// sub_000E85E0 (0x000E85E0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
{
    void sub_00242DF0(int);
};

extern "C" char DAT_0039D520[];
extern "C" char DAT_003A85EC[];
extern "C" void __cdecl sub_00022990(void);

class Class_000E85E0
{
public:
    Class_000E85E0* sub_000E85E0();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    bool m_Field1C; // +0x1C
    bool m_Field1D; // +0x1D
    char m_pad1E[0x2];
    int m_Field20; // +0x20
    Field24 m_Field24; // +0x24
    char m_pad25[0x3];
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    float m_Field30; // +0x30
};

Class_000E85E0* Class_000E85E0::sub_000E85E0()
{
    sub_00022990();
    m_Field00 = (int)DAT_003A85EC;
    m_Field1C = false;
    m_Field1D = true;
    m_Field20 = 0;
    m_Field24.sub_00242DF0((int)DAT_0039D520);
    m_Field28 = 0.0f;
    m_Field2C = 0.0f;
    m_Field30 = 0.0f;
    return this;
}
