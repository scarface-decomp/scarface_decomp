// bin: xb
// va: 0x00177F80
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: cMissionData::SetMissionTimerLimit)
// sub_00177F80 (0x00177F80, 17 bytes)

class Class_00177F80
{
public:
    void sub_00177F80(float value);

    char m_pad00[0x174];
    float m_Field174; // +0x174
};

// Sets the value.
void Class_00177F80::sub_00177F80(float value)
{
    m_Field174 = value;
}
