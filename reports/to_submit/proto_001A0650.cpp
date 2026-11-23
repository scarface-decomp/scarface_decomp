// bin: proto
// va: 0x001A0650
// what: 
// tool: the portal's starter code (no AI)

// sub_001A0650 (Proto 0x001A0650, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0006D1F0(void);

class Class_001A0650
{
public:
    void sub_001A0650();
    int sub_001A0540(int);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    char m_pad38[0x7];
    bool m_Field3F; // +0x3F
};

void Class_001A0650::sub_001A0650()
{
    sub_0006D1F0();
    m_Field3F = false;
    m_Field34 = sub_001A0540(m_Field30);
}
