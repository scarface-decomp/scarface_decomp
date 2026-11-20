// bin: xb
// va: 0x00164A10
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: cEffectSpikes::SetScale)
// sub_00164A10 (0x00164A10, 17 bytes)

class Class_00164A10
{
public:
    void sub_00164A10(float value);

    char m_pad00[0x120];
    float m_Field120; // +0x120
};

// Sets the value.
void Class_00164A10::sub_00164A10(float value)
{
    m_Field120 = value;
}
