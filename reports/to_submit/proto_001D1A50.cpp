// bin: proto
// va: 0x001D1A50
// what: 
// tool: the portal's starter code (no AI)

// sub_001D1A50 (Proto 0x001D1A50, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009B800();
};

class Class_001D1A50
{
public:
    void sub_001D1A50();
};

void Class_001D1A50::sub_001D1A50()
{
    ((Object*)(int)this + 32)->sub_0009B800();
}
