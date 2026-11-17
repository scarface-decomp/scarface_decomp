// bin: xb
// va: 0x0008A9C0
// tool: the portal's starter code (no AI)
// sub_0008A9C0 (0x0008A9C0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003A4038;

class Class_0008A9C0
{
public:
    int sub_0008A9C0();
    char m_pad00[0x1D2C];
    unsigned char m_Field1D2C; // +0x1D2C
    char m_pad1D2D[0x7CF];
    int m_Field24FC; // +0x24FC
    char m_pad2500[0x8];
    int m_Field2508; // +0x2508
    float m_Field250C; // +0x250C
    char m_pad2510[0xA8];
    float m_Field25B8; // +0x25B8
    char m_pad25BC[0x4];
    int m_Field25C0; // +0x25C0
};

int Class_0008A9C0::sub_0008A9C0()
{
    m_Field250C = DAT_003A4038;
    m_Field25B8 = DAT_0039D664;
    m_Field25C0 = 4181;
    m_Field2508 = 0;
    m_Field24FC = 0;
    m_Field1D2C = 255;
    return 0;
}
