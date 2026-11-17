// bin: pc
// va: 0x006E8190
// tool: the portal's starter code (no AI)
// sub_006E8190 (0x006E8190, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E62B0(int);
};

extern "C" void __cdecl sub_006DF0C0(int);

class Class_006E8190
{
public:
    void sub_006E8190(int a1, int a2);
};

void Class_006E8190::sub_006E8190(int a1, int a2)
{
    ((Object*)a1)->sub_006E62B0(a2);
    sub_006DF0C0((int)this + 172);
}
