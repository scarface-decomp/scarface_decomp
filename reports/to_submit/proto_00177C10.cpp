// bin: proto
// va: 0x00177C10
// what: 
// tool: the portal's starter code (no AI)

// sub_00177C10 (Proto 0x00177C10, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0016E3C0(int, int);

class Class_00177C10
{
public:
    void sub_00177C10();
    char m_pad00[0x4C];
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
};

void Class_00177C10::sub_00177C10()
{
    m_Field50 = 0;
    m_Field4C = 0;
    m_Field54 = 0;
    m_Field58 = 0;
    sub_0016E3C0(0, 1);
}
