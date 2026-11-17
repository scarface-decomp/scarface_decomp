// bin: proto
// va: 0x00118F90
// tool: the portal's starter code (no AI)
// sub_00118F90 (0x00118F90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F6F8[];

class Class_00118F90
{
public:
    Class_00118F90* sub_00118F90(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_00118F90* Class_00118F90::sub_00118F90(float a1)
{
    m_Field04 = 8;
    m_Field00 = (int)DAT_0038F6F8;
    m_Field08 = a1;
    return this;
}
