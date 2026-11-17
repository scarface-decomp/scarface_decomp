// bin: proto
// va: 0x0008F3A0
// tool: the portal's starter code (no AI)
// sub_0008F3A0 (0x0008F3A0, 96 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002BC2C0();
};

extern "C" float DAT_0037CE50;
extern "C" float DAT_003836C4;
extern "C" float DAT_003850D4;
extern "C" int DAT_003BB940;
extern "C" int __stdcall sub_002BBEC0(int);

class Class_0008F3A0
{
public:
    Class_0008F3A0* sub_0008F3A0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    int m_Field24; // +0x24
};

Class_0008F3A0* Class_0008F3A0::sub_0008F3A0()
{
    float t1, t2, t3;

    t1 = DAT_003850D4;
    t2 = DAT_003836C4;
    m_Field00 = t1;
    t3 = DAT_0037CE50;
    m_Field04 = t3;
    m_Field08 = t3;
    m_Field0C = t3;
    m_Field10 = t3;
    m_Field14 = t3;
    m_Field18 = t3;
    m_Field1C = t2;
    m_Field20 = t3;
    m_Field24 = ((Object*)sub_002BBEC0(DAT_003BB940))->sub_002BC2C0();
    return this;
}
