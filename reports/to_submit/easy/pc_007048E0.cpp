// bin: pc
// va: 0x007048E0
// tool: the portal's starter code (no AI)
// sub_007048E0 (0x007048E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774994[];
extern "C" void __stdcall sub_006524F0(int);

class Class_007048E0
{
public:
    Class_007048E0* sub_007048E0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x44];
    bool m_Field48; // +0x48
    char m_pad49[0x7];
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
    int m_Field5C; // +0x5C
};

Class_007048E0* Class_007048E0::sub_007048E0(int a1)
{
    sub_006524F0(a1);
    m_Field58 = -0x1000000;
    m_Field50 = -0x1000000;
    m_Field54 = -0x1000000;
    m_Field00 = (int)DAT_00774994;
    m_Field48 = true;
    m_Field5C = -32513;
    return this;
}
