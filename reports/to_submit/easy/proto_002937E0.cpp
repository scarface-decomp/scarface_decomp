// bin: proto
// va: 0x002937E0
// tool: the portal's starter code (no AI)
// sub_002937E0 (0x002937E0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003834C4[];
extern "C" char DAT_003B92A4[];
extern "C" void __cdecl sub_002CB933(int);

class Class_002937E0
{
public:
    void sub_002937E0();
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    bool m_Field24; // +0x24
};

void Class_002937E0::sub_002937E0()
{
    m_Field00 = (int)DAT_003B92A4;
    if (m_Field24) {
        sub_002CB933(m_Field20);
    }
    m_Field00 = (int)DAT_003834C4;
}
