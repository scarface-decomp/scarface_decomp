// bin: xb
// va: 0x00239FC0
// tool: the portal's starter code (no AI)
// sub_00239FC0 (0x00239FC0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __stdcall sub_0023A4F0(int);

class Class_00239FC0
{
public:
    void sub_00239FC0(int a1);
};

void Class_00239FC0::sub_00239FC0(int a1)
{
    sub_0023A4F0(a1);
}
