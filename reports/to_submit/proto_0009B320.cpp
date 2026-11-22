// bin: proto
// va: 0x0009B320
// what: 
// tool: the portal's starter code (no AI)

// sub_0009B320 (Proto 0x0009B320, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003841AC;
extern "C" float DAT_003915CC;
extern "C" float DAT_003A1754;

class Class_0009B320
{
public:
    Class_0009B320* sub_0009B320();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_0009B320* Class_0009B320::sub_0009B320()
{
    m_Field00 = DAT_003915CC;
    m_Field04 = DAT_003A1754;
    m_Field08 = DAT_003841AC;
    return this;
}
