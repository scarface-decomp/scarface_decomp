// bin: xb
// va: 0x0028D590
// tool: the portal's starter code (no AI)
// sub_0028D590 (0x0028D590, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __stdcall sub_0028D8C0(int);

class Class_0028D590
{
public:
    void sub_0028D590(int a1);
};

void Class_0028D590::sub_0028D590(int a1)
{
    sub_0028D8C0(a1);
}
