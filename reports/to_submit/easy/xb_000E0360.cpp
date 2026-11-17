// bin: xb
// va: 0x000E0360
// tool: the portal's starter code (no AI)
// sub_000E0360 (0x000E0360, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E0360
{
public:
    float sub_000E0360();
    char m_pad00[0xA0];
    int m_FieldA0; // +0xA0
};

float Class_000E0360::sub_000E0360()
{
    return *(float*)m_FieldA0;
}
