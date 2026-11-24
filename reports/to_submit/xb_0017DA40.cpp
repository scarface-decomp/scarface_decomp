// bin: xb
// va: 0x0017DA40
// what: If m_Field04 is greater than 0, returns sub_0017D8D0(m_Field04); otherwise returns false.
// tool: Gemini 4 Neon

class Class_0017DA40
{
public:
    bool sub_0017DA40();
    bool sub_0017D8D0(unsigned int count);
    char m_pad00[0x4];
    unsigned int m_Field04; // +0x04
};

bool Class_0017DA40::sub_0017DA40()
{
    if (m_Field04 > 0) {
        return sub_0017D8D0(m_Field04);
    }
    return false;
}
