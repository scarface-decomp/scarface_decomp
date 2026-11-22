// bin: proto
// va: 0x0007D010
// what: 
// tool: the portal's starter code (no AI)

// sub_0007D010 (Proto 0x0007D010, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_0007D010
{
public:
    Class_0007D010* sub_0007D010();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

Class_0007D010* Class_0007D010::sub_0007D010()
{
    float t1;

    t1 = DAT_0037CE50;
    m_Field00 = t1;
    m_Field04 = t1;
    return this;
}
