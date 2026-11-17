// bin: xb
// va: 0x00250E00
// tool: the portal's starter code (no AI)
// sub_00250E00 (0x00250E00, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D5388[];
extern "C" void __stdcall sub_0028D900(int);

class Class_00250E00
{
public:
    Class_00250E00* sub_00250E00(int a1);
    int m_Field00; // +0x00
};

Class_00250E00* Class_00250E00::sub_00250E00(int a1)
{
    sub_0028D900(a1);
    m_Field00 = (int)DAT_003D5388;
    return this;
}
