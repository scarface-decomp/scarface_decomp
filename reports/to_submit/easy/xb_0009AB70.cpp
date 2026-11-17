// bin: xb
// va: 0x0009AB70
// tool: the portal's starter code (no AI)
// sub_0009AB70 (0x0009AB70, 96 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002EEB20();
};

extern "C" float DAT_0039D664;
extern "C" float DAT_003B22B0;
extern "C" float DAT_003D1058;
extern "C" int DAT_003E1B08;
extern "C" int __stdcall sub_002EE720(int);

class Class_0009AB70
{
public:
    Class_0009AB70* sub_0009AB70();
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

Class_0009AB70* Class_0009AB70::sub_0009AB70()
{
    float t1, t2, t3;

    t1 = DAT_003D1058;
    t2 = DAT_003B22B0;
    m_Field00 = t1;
    t3 = DAT_0039D664;
    m_Field04 = t3;
    m_Field08 = t3;
    m_Field0C = t3;
    m_Field10 = t3;
    m_Field14 = t3;
    m_Field18 = t3;
    m_Field1C = t2;
    m_Field20 = t3;
    m_Field24 = ((Object*)sub_002EE720(DAT_003E1B08))->sub_002EEB20();
    return this;
}
