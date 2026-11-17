// bin: proto
// va: 0x000F9C60
// tool: the portal's starter code (no AI)
// sub_000F9C60 (0x000F9C60, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000F9C60
{
public:
    void sub_000F9C60(int a1, bool a2);
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

void Class_000F9C60::sub_000F9C60(int a1, bool a2)
{
    *(bool*)(m_Field14 + ((((((unsigned int)*(int*)(a1 + 120)) >> 4) & 127) + (((((unsigned int)*(int*)(a1 + 120)) >> 4) & 127) * 2)) * 4) + 9) = a2;
}
