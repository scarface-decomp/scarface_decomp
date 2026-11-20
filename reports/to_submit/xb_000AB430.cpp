// bin: xb
// va: 0x000AB430
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: Projectile::SetGravity(float))
// sub_000AB430 (0x000AB430, 17 bytes)

class Class_000AB430
{
public:
    void sub_000AB430(float value);

    char m_pad00[0x1B0];
    float m_Field1B0; // +0x1B0
};

// Sets the value.
void Class_000AB430::sub_000AB430(float value)
{
    m_Field1B0 = value;
}
