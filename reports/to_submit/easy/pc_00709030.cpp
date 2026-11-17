// bin: pc
// va: 0x00709030
// tool: the portal's starter code (no AI)
// sub_00709030 (0x00709030, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774D94[];
extern "C" void __stdcall sub_006524F0(int);

class Class_00709030
{
public:
    Class_00709030* sub_00709030(int a1);
    void sub_00517CE0(int);
    int m_Field00; // +0x00
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

Class_00709030* Class_00709030::sub_00709030(int a1)
{
    sub_006524F0(a1);
    m_Field00 = (int)DAT_00774D94;
    m_Field80 = 0;
    sub_00517CE0(0);
    return this;
}
