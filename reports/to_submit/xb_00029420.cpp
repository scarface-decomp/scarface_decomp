// bin: xb
// va: 0x00029420
// what: Copies a 64-byte (4x4 matrix) structure from the argument pointer into the member at +0x34.
// tool: Gemini 4 Neon

struct Matrix4x4_00029420
{
    float m[16];
};

class Class_00029420
{
public:
    void sub_00029420(const Matrix4x4_00029420* src);
    char m_pad00[0x34];
    Matrix4x4_00029420 m_Field34; // +0x34
};

void Class_00029420::sub_00029420(const Matrix4x4_00029420* src)
{
    m_Field34 = *src;
}
