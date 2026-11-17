// bin: proto
// va: 0x0009ACD0
// tool: the portal's starter code (no AI)
// sub_0009ACD0 (0x0009ACD0, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002BC2C0();
};

extern "C" float DAT_0037CE50;
extern "C" float DAT_0037CE6C;
extern "C" float DAT_00384198;
extern "C" float DAT_0038419C;
extern "C" int DAT_003BB940;
extern "C" int __stdcall sub_002BBEC0(int);

class Class_0009ACD0
{
public:
    Class_0009ACD0* sub_0009ACD0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_0009ACD0* Class_0009ACD0::sub_0009ACD0()
{
    float t4;

    m_Field04 = DAT_0037CE6C;
    m_Field08 = DAT_0038419C;
    m_Field0C = DAT_00384198;
    t4 = DAT_0037CE50;
    m_Field10 = t4;
    m_Field14 = t4;
    m_Field00 = ((Object*)sub_002BBEC0(DAT_003BB940))->sub_002BC2C0();
    return this;
}
