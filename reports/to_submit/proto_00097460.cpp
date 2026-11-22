// bin: proto
// va: 0x00097460
// what: 
// tool: the portal's starter code (no AI)

// sub_00097460 (Proto 0x00097460, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class Class_00097460
{
public:
    Class_00097460* sub_00097460();
    bool m_Field00; // +0x00
    bool m_Field01; // +0x01
    char m_pad02[0x2];
    float m_Field04; // +0x04
};

Class_00097460* Class_00097460::sub_00097460()
{
    float t1;

    t1 = DAT_0037CE60;
    m_Field00 = true;
    m_Field01 = true;
    m_Field04 = t1;
    return this;
}
