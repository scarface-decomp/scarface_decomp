// bin: xb
// va: 0x00053400
// what: Dereferences the pointer chain at +0x84 -> +0x44 -> +0x00 and calls sub_00051780 with the argument.
// tool: Gemini 4 Neon

struct Object_00053400
{
    void sub_00051780(int a1);
};

class Class_00053400
{
public:
    void sub_00053400(int a1);
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

void Class_00053400::sub_00053400(int a1)
{
    ((Object_00053400*)*(int*)*(int*)(m_Field84 + 68))->sub_00051780(a1);
}
