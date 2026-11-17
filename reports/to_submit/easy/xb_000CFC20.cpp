// bin: xb
// va: 0x000CFC20
// tool: the portal's starter code (no AI)
// sub_000CFC20 (0x000CFC20, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00021EE0();
};

class Class_000CFC20
{
public:
    bool sub_000CFC20();
    char m_pad00[0x17C];
    int m_Field17C; // +0x17C
};

bool Class_000CFC20::sub_000CFC20()
{
    int t1;

    t1 = m_Field17C;
    if (m_Field17C) {
        return ((Object*)t1)->sub_00021EE0();
    }
    return false;
}
