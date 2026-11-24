// bin: xb
// va: 0x0020CDB0
// what: 
// tool: the portal's starter code (no AI)

// sub_0020CDB0 (0x0020CDB0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000A76D0();
};

class Class_0020CDB0
{
public:
    void sub_0020CDB0();
};

void Class_0020CDB0::sub_0020CDB0()
{
    ((Object*)(int)this + 32)->sub_000A76D0();
}
