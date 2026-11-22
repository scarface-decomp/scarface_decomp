// bin: proto
// va: 0x0007FF80
// what: 
// tool: the portal's starter code (no AI)

// sub_0007FF80 (Proto 0x0007FF80, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_003835FC;

class Class_0007FF80
{
public:
    int sub_0007FF80();
    char m_pad00[0x1B9C];
    unsigned char m_Field1B9C; // +0x1B9C
    char m_pad1B9D[0x7CF];
    int m_Field236C; // +0x236C
    char m_pad2370[0x8];
    int m_Field2378; // +0x2378
    float m_Field237C; // +0x237C
    char m_pad2380[0xB0];
    float m_Field2430; // +0x2430
    char m_pad2434[0x4];
    int m_Field2438; // +0x2438
};

int Class_0007FF80::sub_0007FF80()
{
    m_Field237C = DAT_003835FC;
    m_Field2430 = DAT_0037CE50;
    m_Field2438 = 4181;
    m_Field2378 = 0;
    m_Field236C = 0;
    m_Field1B9C = 255;
    return 0;
}
