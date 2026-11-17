// bin: xb
// va: 0x000E7D30
// tool: the portal's starter code (no AI)
// sub_000E7D30 (0x000E7D30, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D8D4;
extern "C" float DAT_003A4974;
extern "C" float DAT_003A4A2C;
extern "C" char DAT_003A817C[];
extern "C" float DAT_003CA880;
extern "C" void __cdecl sub_00022990(void);

class Class_000E7D30
{
public:
    Class_000E7D30* sub_000E7D30();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
};

Class_000E7D30* Class_000E7D30::sub_000E7D30()
{
    float t2, t5;

    sub_00022990();
    t2 = DAT_003A4A2C;
    m_Field1C = t2;
    m_Field20 = t2;
    m_Field24 = DAT_003CA880;
    m_Field28 = DAT_0039D8D4;
    t5 = DAT_003A4974;
    m_Field00 = (int)DAT_003A817C;
    m_Field2C = t5;
    return this;
}
