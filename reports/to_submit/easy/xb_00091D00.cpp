// bin: xb
// va: 0x00091D00
// tool: the portal's starter code (no AI)
// sub_00091D00 (0x00091D00, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);

class Class_00091D00
{
public:
    int sub_00091D00();
    char m_pad00[0x14];
    int m_Field14; // +0x14
    unsigned short m_Field18; // +0x18
};

int Class_00091D00::sub_00091D00()
{
    if ((unsigned int)m_Field18 > (unsigned int)1) {
        sub_00027600(m_Field14);
    }
    m_Field14 = 0;
    m_Field18 = 0;
    return 0;
}
