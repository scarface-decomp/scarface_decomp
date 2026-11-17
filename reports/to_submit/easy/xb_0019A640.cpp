// bin: xb
// va: 0x0019A640
// tool: the portal's starter code (no AI)
// sub_0019A640 (0x0019A640, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" char DAT_003BBF9C[];
extern "C" char DAT_003BBFA4[];

class Class_0019A640
{
public:
    Class_0019A640* sub_0019A640(int a1, int a2);
    void sub_00199FE0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x30];
    int m_Field98; // +0x98
    int m_Field9C; // +0x9C
    bool m_FieldA0; // +0xA0
    char m_padA1[0x3];
    float m_FieldA4; // +0xA4
    char m_padA8[0x4];
    float m_FieldAC; // +0xAC
    float m_FieldB0; // +0xB0
};

Class_0019A640* Class_0019A640::sub_0019A640(int a1, int a2)
{
    sub_00199FE0(a1, a2);
    m_FieldA4 = DAT_0039D65C;
    m_Field98 = 0;
    m_Field9C = 0;
    m_FieldA0 = false;
    m_Field00 = (int)DAT_003BBFA4;
    m_Field64 = (int)DAT_003BBF9C;
    m_FieldAC = 0.0f;
    m_FieldB0 = 0.0f;
    return this;
}
