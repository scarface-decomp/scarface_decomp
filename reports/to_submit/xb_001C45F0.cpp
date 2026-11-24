// bin: xb
// va: 0x001C45F0
// what: Stores a non-null first argument into m_Field10.
// tool: Gemini 4 Neon

class Class_001C45F0
{
public:
    void sub_001C45F0(int value, int a2);
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

void Class_001C45F0::sub_001C45F0(int value, int)
{
    if (value) {
        m_Field10 = value;
    }
}
