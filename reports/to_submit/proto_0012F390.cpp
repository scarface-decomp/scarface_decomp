// bin: proto
// va: 0x0012F390
// what: 
// tool: the portal's starter code (no AI)

// sub_0012F390 (Proto 0x0012F390, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003850C8;
extern "C" float DAT_0038980C;

class Class_0012F390
{
public:
    Class_0012F390* sub_0012F390();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
};

Class_0012F390* Class_0012F390::sub_0012F390()
{
    float t1, t2;

    t1 = DAT_0038980C;
    m_Field00 = 0;
    m_Field04 = t1;
    m_Field08 = t1;
    t2 = DAT_003850C8;
    m_Field0C = t2;
    m_Field10 = t2;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = false;
    return this;
}
