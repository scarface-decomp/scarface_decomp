// bin: xb
// va: 0x0009ACA0
// what: Resets a four-number rotation to "no rotation" (0, 0, 0, 1).
// tool: Claude Opus 5.5 (symcov hint: RSQuat::Identity, link-order)
// sub_0009ACA0 (0x0009ACA0, 33 bytes)

class Class_0009ACA0
{
public:
    Class_0009ACA0 *sub_0009ACA0();

    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

// Sets the first three components to zero and the last to one.
Class_0009ACA0 *Class_0009ACA0::sub_0009ACA0()
{
    m_Field00 = 0.0f;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field0C = 1.0f;
    return this;
}
