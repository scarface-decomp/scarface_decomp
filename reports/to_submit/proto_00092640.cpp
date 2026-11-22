// bin: proto
// va: 0x00092640
// what: 
// tool: the portal's starter code (no AI)

// sub_00092640 (Proto 0x00092640, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0038ADF0;

class Class_00092640
{
public:
    Class_00092640* sub_00092640();
    float m_Field00; // +0x00
};

Class_00092640* Class_00092640::sub_00092640()
{
    m_Field00 = DAT_0038ADF0;
    return this;
}
