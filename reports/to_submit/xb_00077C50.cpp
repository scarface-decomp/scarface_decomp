// bin: xb
// va: 0x00077C50
// what: Calls sub_00081DA0 on the member object pointer at +0x04 of the argument.
// tool: Gemini 4 Neon

struct Field04_00077C50
{
    void sub_00081DA0();
};

struct Wrapper_00077C50
{
    int m_Field00;
    Field04_00077C50* m_Field04; // +0x04
};

void __cdecl sub_00077C50(Wrapper_00077C50* wrapper)
{
    wrapper->m_Field04->sub_00081DA0();
}
