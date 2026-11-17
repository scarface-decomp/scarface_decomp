// bin: xb
// va: 0x000A4D00
// tool: the portal's starter code (no AI)
// sub_000A4D00 (0x000A4D00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field00
{
    int sub_001DE0E0();
};

struct Field20
{
    void sub_000B8910(int);
    void sub_000B89A0(int);
};

class Class_000A4D00
{
public:
    void sub_000A4D00();
    Field00* m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

void Class_000A4D00::sub_000A4D00()
{
    if (m_Field00) {
        m_Field20.sub_000B8910(m_Field00->sub_001DE0E0());
        m_Field20.sub_000B89A0(1);
    }
}
