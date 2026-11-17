// bin: xb
// va: 0x000E7A20
// tool: the portal's starter code (no AI)
// sub_000E7A20 (0x000E7A20, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E7A20
{
public:
    bool sub_000E7A20(int a1);
    char m_pad00[0x24];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
};

bool Class_000E7A20::sub_000E7A20(int a1)
{
    m_Field24 = *(int*)a1;
    m_Field28 = *(int*)(a1 + 4);
    m_Field2C = *(int*)(a1 + 8);
    *(float*)((char*)this + 0x2C) = 0.0f - *(float*)((char*)this + 0x2C);
    return true;
}
