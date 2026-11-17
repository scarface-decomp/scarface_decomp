// bin: proto
// va: 0x002BA820
// tool: the portal's starter code (no AI)
// sub_002BA820 (0x002BA820, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" unsigned short DAT_004390D8;

class Class_002BA820
{
public:
    unsigned short sub_002BA820();
    unsigned char m_Field00; // +0x00
    char m_pad01[0x7];
    unsigned short m_Field08; // +0x08
    char m_pad0A[0xD2];
    int m_FieldDC; // +0xDC
    char m_padE0[0x4];
    int m_FieldE4; // +0xE4
};

unsigned short Class_002BA820::sub_002BA820()
{
    unsigned short t1;

    m_Field00 &= 254;
    m_FieldDC = 0;
    m_FieldE4 = 0;
    t1 = DAT_004390D8;
    m_Field08 = DAT_004390D8;
    return t1;
}
