// bin: xb
// va: 0x002A55E0
// what: 
// tool: the portal's starter code (no AI)

// sub_002A55E0 (0x002A55E0, 148 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    int sub_002751E0(int, int);
};

extern "C" char DAT_003DA04C[];

class Class_002A55E0
{
public:
    Class_002A55E0* sub_002A55E0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_002A55E0* Class_002A55E0::sub_002A55E0(int a1)
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_003DA04C;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0;
    if (a1) {
        m_Field08 = ((Object*)a1)->sub_002751E0(0x544457, 0x31544C46);
        m_Field0C = ((Object*)a1)->sub_002751E0(0x544748, 0x31544C46);
        m_Field10 = ((Object*)a1)->sub_002751E0(0x50534F48, 0x31544C46);
        m_Field14 = ((Object*)a1)->sub_002751E0(0x50534556, 0x31544C46);
        m_Field18 = ((Object*)a1)->sub_002751E0(0x41564452, 0x31544C46);
    }
    return this;
}
