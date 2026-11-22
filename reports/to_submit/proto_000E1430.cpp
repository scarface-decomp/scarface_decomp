// bin: proto
// va: 0x000E1430
// what: 
// tool: the portal's starter code (no AI)

// sub_000E1430 (Proto 0x000E1430, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014A290();
};

extern "C" int __cdecl sub_00028120(int);

class Class_000E1430
{
public:
    int sub_000E1430();
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

int Class_000E1430::sub_000E1430()
{
    return ((Object*)sub_00028120(m_Field84))->sub_0014A290() != 0;
}
