// bin: xb
// va: 0x000D84C0
// what: Returns the float value at +0x1D8 multiplied by 1000.0.
// tool: Gemini 4 Neon

class Class_000D84C0
{
public:
    float sub_000D84C0();
    char m_pad00[0x1D8];
    float m_Field1D8; // +0x1D8
};

float Class_000D84C0::sub_000D84C0()
{
    return m_Field1D8 * 1000.0f;
}
