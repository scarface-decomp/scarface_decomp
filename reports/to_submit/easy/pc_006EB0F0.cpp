// bin: pc
// va: 0x006EB0F0
// tool: the portal's starter code (no AI)
// sub_006EB0F0 (0x006EB0F0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F204;

class Class_006EB0F0
{
public:
    void sub_006EB0F0(int a1);
};

void Class_006EB0F0::sub_006EB0F0(int a1)
{
    ((void (__cdecl*)(int, int, int))DAT_0072F204)((int)this, a1, 127);
}
