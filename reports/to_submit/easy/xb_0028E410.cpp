// bin: xb
// va: 0x0028E410
// tool: the portal's starter code (no AI)
// sub_0028E410 (0x0028E410, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D88A8[];
extern "C" void __stdcall sub_0028D900(int);

class Class_0028E410
{
public:
    Class_0028E410* sub_0028E410(int a1);
    int m_Field00; // +0x00
};

Class_0028E410* Class_0028E410::sub_0028E410(int a1)
{
    sub_0028D900(a1);
    m_Field00 = (int)DAT_003D88A8;
    return this;
}
