// bin: xb
// va: 0x000EC3C0
// tool: the portal's starter code (no AI)
// sub_000EC3C0 (0x000EC3C0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000EC3C0
{
public:
    float sub_000EC3C0(int a1);
    int m_Field00; // +0x00
};

float Class_000EC3C0::sub_000EC3C0(int a1)
{
    return *(float*)(m_Field00 + (a1 * 4));
}
