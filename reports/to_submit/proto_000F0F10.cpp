// bin: proto
// va: 0x000F0F10
// what: 
// tool: the portal's starter code (no AI)

// sub_000F0F10 (Proto 0x000F0F10, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0(int);
};

class Class_000F0F10
{
public:
    void sub_000F0F10(int a1);
};

void Class_000F0F10::sub_000F0F10(int a1)
{
    a1 = 0;
    ((Object*)(int)this + 232)->sub_0008D4C0(a1);
}
