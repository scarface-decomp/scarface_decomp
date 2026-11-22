// bin: proto
// va: 0x00011CE0
// what: 
// tool: the portal's starter code (no AI)

// sub_00011CE0 (Proto 0x00011CE0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00011CE0
{
public:
    int sub_00011CE0();
    char m_pad00[0x20];
    unsigned short m_Field20; // +0x20
};

int Class_00011CE0::sub_00011CE0()
{
    return m_Field20 != 65535;
}
