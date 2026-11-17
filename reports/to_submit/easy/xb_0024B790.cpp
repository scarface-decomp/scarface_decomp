// bin: xb
// va: 0x0024B790
// tool: the portal's starter code (no AI)
// sub_0024B790 (0x0024B790, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_0028D780(int);
};

class Class_0024B790
{
public:
    void sub_0024B790(int a1);
};

void Class_0024B790::sub_0024B790(int a1)
{
    ((Object*)(int)this + 52)->sub_0028D780(a1);
}
