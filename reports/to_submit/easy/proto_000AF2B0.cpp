// bin: proto
// va: 0x000AF2B0
// tool: the portal's starter code (no AI)
// sub_000AF2B0 (0x000AF2B0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field208
{
    void sub_000AC2F0(int);
};

struct Field230
{
    void sub_000AC6E0(int);
};

struct Field238
{
    void sub_000AADD0(int);
};

class Class_000AF2B0
{
public:
    void sub_000AF2B0(int a1);
    char m_pad00[0x204];
    unsigned char m_Field204; // +0x204
    char m_pad205[0x3];
    Field208 m_Field208; // +0x208
    char m_pad209[0x27];
    Field230 m_Field230; // +0x230
    char m_pad231[0x7];
    Field238 m_Field238; // +0x238
};

void Class_000AF2B0::sub_000AF2B0(int a1)
{
    if (m_Field204 != ((unsigned char)a1)) {
        m_Field204 = (unsigned char)a1;
        m_Field208.sub_000AC2F0(a1);
        m_Field230.sub_000AC6E0(a1);
        m_Field238.sub_000AADD0(a1);
    }
}
