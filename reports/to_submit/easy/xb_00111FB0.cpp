// bin: xb
// va: 0x00111FB0
// tool: the portal's starter code (no AI)
// sub_00111FB0 (0x00111FB0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00111FB0
{
public:
    int sub_00111FB0(int a1, int a2);
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

int Class_00111FB0::sub_00111FB0(int a1, int a2)
{
    return *(int*)(m_Field14 + ((((((unsigned int)*(int*)(a1 + 116)) >> 4) & 127) + (((((unsigned int)*(int*)(a1 + 116)) >> 4) & 127) * 2)) * 4) + 4) == *(int*)(a2 + 16);
}
