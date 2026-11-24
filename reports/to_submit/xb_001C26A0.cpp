// verify: python portal/verify.py reports/to_submit/xb_001C26A0.cpp --va 0x001C26A0 --bin xb --flags "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE"
// bin: xb
// va: 0x001C26A0
// what: Stores the float argument into the member at +0x78 if it is greater than zero.
// tool: Gemini 4 Neon

class Class_001C26A0
{
public:
    void sub_001C26A0(float value);
    char m_pad00[0x78];
    float m_Field78; // +0x78
};

void Class_001C26A0::sub_001C26A0(float value)
{
    if (value <= 0.0f)
        return;
    m_Field78 = value;
}
