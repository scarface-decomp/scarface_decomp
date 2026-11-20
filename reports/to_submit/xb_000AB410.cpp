// bin: xb
// va: 0x000AB410
// what: Stores one number in an object.
// tool: Claude Opus 5.5 (symcov hint: Projectile::SetSplashDamageValue(float))
// sub_000AB410 (0x000AB410, 17 bytes)

class Class_000AB410
{
public:
    void sub_000AB410(float value);

    char m_pad00[0x1AC];
    float m_Field1AC; // +0x1AC
};

// Sets the value.
void Class_000AB410::sub_000AB410(float value)
{
    m_Field1AC = value;
}
