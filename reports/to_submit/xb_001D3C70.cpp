// bin: xb
// va: 0x001D3C70
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: UIBarMeter::SetShrinkRate(float))
// sub_001D3C70 (0x001D3C70, 17 bytes)

class Class_001D3C70
{
public:
    void sub_001D3C70(float value);

    char m_pad00[0xEC];
    float m_FieldEC; // +0xEC
};

// Sets the value.
void Class_001D3C70::sub_001D3C70(float value)
{
    m_FieldEC = value;
}
