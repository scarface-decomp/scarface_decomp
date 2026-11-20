// bin: xb
// va: 0x001C4640
// what: Stores two numbers in an object.
// tool: Claude Opus 5.5 (symcov hint: EARS::Modules::Attitude::SetBrowTilt)
// sub_001C4640 (0x001C4640, 25 bytes)

class Class_001C4640
{
public:
    void sub_001C4640(float a1, float a2);

    char m_pad00[0x2C];
    float m_Field2C; // +0x2C
    float m_Field30; // +0x30
};

// Sets both values.
void Class_001C4640::sub_001C4640(float a1, float a2)
{
    m_Field2C = a1;
    m_Field30 = a2;
}
