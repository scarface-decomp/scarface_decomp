// bin: xb
// va: 0x00217670
// what: 
// tool: the portal's starter code (no AI)

// sub_00217670 (0x00217670, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EC0F0();
};

extern "C" int __stdcall sub_000EB680(int, int, int);

class Class_00217670
{
public:
    void sub_00217670(int a1);
    char m_pad00[0xB0];
    int m_FieldB0; // +0xB0
};

void Class_00217670::sub_00217670(int a1)
{
    m_FieldB0 = a1;
    ((Object*)sub_000EB680(20, a1, 0))->sub_000EC0F0();
}
