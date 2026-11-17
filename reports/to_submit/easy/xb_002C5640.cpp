// bin: xb
// va: 0x002C5640
// tool: the portal's starter code (no AI)
// sub_002C5640 (0x002C5640, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003DBA7C[];
extern "C" void __stdcall sub_0029FDB0(int);

class Class_002C5640
{
public:
    Class_002C5640* sub_002C5640(int a1);
    int m_Field00; // +0x00
};

Class_002C5640* Class_002C5640::sub_002C5640(int a1)
{
    sub_0029FDB0(a1);
    m_Field00 = (int)DAT_003DBA7C;
    return this;
}
