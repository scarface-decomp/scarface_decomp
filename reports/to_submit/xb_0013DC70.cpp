// bin: xb
// va: 0x0013DC70
// what: Calls sub_00217380 on m_Field94 and passes 0 to sub_00218050 on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_0013DC70
{
    void sub_00218050(int value);
};

struct Field94_0013DC70
{
    ResultObj_0013DC70* sub_00217380();
};

class Class_0013DC70
{
public:
    void sub_0013DC70();
    char m_pad00[0x94];
    Field94_0013DC70* m_Field94; // +0x94
};

void Class_0013DC70::sub_0013DC70()
{
    ResultObj_0013DC70* obj = m_Field94->sub_00217380();
    obj->sub_00218050(0);
}
