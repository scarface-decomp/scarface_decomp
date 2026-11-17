// bin: proto
// va: 0x00112B10
// tool: the portal's starter code (no AI)
// sub_00112B10 (0x00112B10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F320[];

class Class_00112B10
{
public:
    Class_00112B10* sub_00112B10(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_00112B10* Class_00112B10::sub_00112B10(float a1)
{
    m_Field04 = 8;
    m_Field00 = (int)DAT_0038F320;
    m_Field08 = a1;
    return this;
}
