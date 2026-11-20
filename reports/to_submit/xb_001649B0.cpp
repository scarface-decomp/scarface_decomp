// bin: xb
// va: 0x001649B0
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: cEffectSpikes::SetScale(float))
// sub_001649B0 (0x001649B0, 17 bytes)

class Class_001649B0
{
public:
    void sub_001649B0(float value);

    char m_pad00[0x12C];
    float m_Field12C; // +0x12C
};

// Sets the value.
void Class_001649B0::sub_001649B0(float value)
{
    m_Field12C = value;
}
