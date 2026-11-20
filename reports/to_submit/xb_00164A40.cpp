// bin: xb
// va: 0x00164A40
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: EARS::Audio::AMixer::MixChannel::SetUIAttenuation)
// sub_00164A40 (0x00164A40, 17 bytes)

class Class_00164A40
{
public:
    void sub_00164A40(float value);

    char m_pad00[0x124];
    float m_Field124; // +0x124
};

// Sets the value.
void Class_00164A40::sub_00164A40(float value)
{
    m_Field124 = value;
}
