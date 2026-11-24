// bin: xb
// va: 0x0022C880
// what: Copies m_Field14 to m_Field1C, fetches the singleton from sub_001C3490, and calls sub_001C4500(1).
// tool: Gemini 4 Neon

struct Singleton_001C3490
{
    void sub_001C4500(int flag);
};

extern "C" Singleton_001C3490* __cdecl sub_001C3490();

class Class_0022C880
{
public:
    void sub_0022C880();
    char m_pad00[0x14];
    int m_Field14; // +0x14
    char m_pad18[0x4];
    int m_Field1C; // +0x1C
};

void Class_0022C880::sub_0022C880()
{
    m_Field1C = m_Field14;
    sub_001C3490()->sub_001C4500(1);
}
