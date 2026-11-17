// bin: pc
// va: 0x00704BE0
// tool: the portal's starter code (no AI)
// sub_00704BE0 (0x00704BE0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774A24[];
extern "C" void __stdcall sub_006524F0(int);

class Class_00704BE0
{
public:
    Class_00704BE0* sub_00704BE0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
};

Class_00704BE0* Class_00704BE0::sub_00704BE0(int a1)
{
    sub_006524F0(a1);
    m_Field80 = 0;
    m_Field84 = 0;
    m_Field00 = (int)DAT_00774A24;
    m_Field88 = -0x7F7F7F80;
    return this;
}
