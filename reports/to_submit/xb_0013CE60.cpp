// bin: xb
// va: 0x0013CE60
// what: Says whether a timer value in an object is still above zero.
// tool: Claude Opus 5.5 (symcov hint: BarrageEffect::ActivationTimerIsActive)
// sub_0013CE60 (0x0013CE60, 26 bytes)

class Class_0013CE60
{
public:
    bool sub_0013CE60() const;

    char m_pad00[0x138];
    float m_Field138; // +0x138
};

// True while the value is greater than zero.
bool Class_0013CE60::sub_0013CE60() const
{
    return m_Field138 > 0.0f;
}
