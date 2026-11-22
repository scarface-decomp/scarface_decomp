// bin: proto
// va: 0x0009D020
// what: 
// tool: the portal's starter code (no AI)

// sub_0009D020 (Proto 0x0009D020, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD90;
extern "C" float DAT_0037CE60;
extern "C" float DAT_00384014;
extern "C" float DAT_003841BC;

class Class_0009D020
{
public:
    Class_0009D020* sub_0009D020();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_0009D020* Class_0009D020::sub_0009D020()
{
    m_Field00 = 0.0f;
    m_Field04 = DAT_0037CE60;
    m_Field08 = DAT_00384014;
    m_Field0C = DAT_0037CD90;
    m_Field10 = DAT_003841BC;
    return this;
}
