// bin: xb
// va: 0x001D3C50
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: UIBarMeter::SetGrowBarLevel(float))
// sub_001D3C50 (0x001D3C50, 17 bytes)

class Class_001D3C50
{
public:
    void sub_001D3C50(float value);

    char m_pad00[0xE8];
    float m_FieldE8; // +0xE8
};

// Sets the value.
void Class_001D3C50::sub_001D3C50(float value)
{
    m_FieldE8 = value;
}
