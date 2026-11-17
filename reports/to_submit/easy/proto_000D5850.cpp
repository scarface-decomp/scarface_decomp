// bin: proto
// va: 0x000D5850
// tool: the portal's starter code (no AI)
// sub_000D5850 (0x000D5850, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037FCE4;
extern "C" float DAT_00382FC8;
extern "C" float DAT_003850E8;
extern "C" char DAT_003870E4[];
extern "C" float DAT_003A968C;
extern "C" void __cdecl sub_00020610(void);

class Class_000D5850
{
public:
    Class_000D5850* sub_000D5850();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
};

Class_000D5850* Class_000D5850::sub_000D5850()
{
    float t2, t5;

    sub_00020610();
    t2 = DAT_0037FCE4;
    m_Field1C = t2;
    m_Field20 = t2;
    m_Field24 = DAT_003850E8;
    m_Field28 = DAT_00382FC8;
    t5 = DAT_003A968C;
    m_Field00 = (int)DAT_003870E4;
    m_Field2C = t5;
    return this;
}
