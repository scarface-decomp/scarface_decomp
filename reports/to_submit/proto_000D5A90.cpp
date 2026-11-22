// bin: proto
// va: 0x000D5A90
// what: 
// tool: the portal's starter code (no AI)

// sub_000D5A90 (Proto 0x000D5A90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" char DAT_003871DC[];
extern "C" void __cdecl sub_00020610(void);

class Class_000D5A90
{
public:
    Class_000D5A90* sub_000D5A90();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
};

Class_000D5A90* Class_000D5A90::sub_000D5A90()
{
    float t2;

    sub_00020610();
    t2 = DAT_0037CE60;
    m_Field00 = (int)DAT_003871DC;
    m_Field1C = t2;
    m_Field20 = t2;
    return this;
}
