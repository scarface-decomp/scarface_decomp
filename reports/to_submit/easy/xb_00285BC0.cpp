// bin: xb
// va: 0x00285BC0
// tool: the portal's starter code (no AI)
// sub_00285BC0 (0x00285BC0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_0028D780(int);
};

class Class_00285BC0
{
public:
    void sub_00285BC0(int a1);
};

void Class_00285BC0::sub_00285BC0(int a1)
{
    ((Object*)(int)this + 12)->sub_0028D780(a1);
}
