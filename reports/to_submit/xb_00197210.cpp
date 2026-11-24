// bin: xb
// va: 0x00197210
// what: Stores a non-null value into m_Field48.
// tool: Gemini 4 Neon

class Class_00197210
{
public:
    void sub_00197210(int value);
    char m_pad00[0x48];
    int m_Field48; // +0x48
};

void Class_00197210::sub_00197210(int value)
{
    if (value) {
        m_Field48 = value;
    }
}
