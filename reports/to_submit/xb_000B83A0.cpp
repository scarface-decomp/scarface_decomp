// bin: xb
// va: 0x000B83A0
// what: Returns sub_00012180(m_Field00) if the pointer at +0x00 is non-null, otherwise false.
// tool: Gemini 4 Neon

extern "C" bool __cdecl sub_00012180(void* obj);

class Class_000B83A0
{
public:
    bool sub_000B83A0();
    void* m_Field00; // +0x00
};

bool Class_000B83A0::sub_000B83A0()
{
    bool result = false;
    void* p = m_Field00;
    if (p) {
        result = sub_00012180(p);
    }
    return result;
}
