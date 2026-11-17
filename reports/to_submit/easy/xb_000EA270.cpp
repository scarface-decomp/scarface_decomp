// bin: xb
// va: 0x000EA270
// tool: the portal's starter code (no AI)
// sub_000EA270 (0x000EA270, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A4AC8;
extern "C" char DAT_003A92A4[];
extern "C" void __cdecl sub_00022950(void);

class Class_000EA270
{
public:
    Class_000EA270* sub_000EA270();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    bool m_Field14; // +0x14
    char m_pad15[0x3];
    float m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    char m_pad1D[0x3];
    int m_Field20; // +0x20
};

Class_000EA270* Class_000EA270::sub_000EA270()
{
    float t2;

    sub_00022950();
    t2 = DAT_003A4AC8;
    m_Field14 = false;
    m_Field20 = 0;
    m_Field00 = (int)DAT_003A92A4;
    m_Field18 = t2;
    m_Field1C = true;
    return this;
}
