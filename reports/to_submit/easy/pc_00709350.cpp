// bin: pc
// va: 0x00709350
// tool: the portal's starter code (no AI)
// sub_00709350 (0x00709350, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774EA4[];
extern "C" void __stdcall sub_0065BD30(int);

class Class_00709350
{
public:
    Class_00709350* sub_00709350(int a1);
    int m_Field00; // +0x00
};

Class_00709350* Class_00709350::sub_00709350(int a1)
{
    sub_0065BD30(a1);
    m_Field00 = (int)DAT_00774EA4;
    return this;
}
