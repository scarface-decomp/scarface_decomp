// bin: proto
// va: 0x00148030
// tool: the portal's starter code (no AI)
// sub_00148030 (0x00148030, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field188
{
    int sub_000BEEF0();
};

class Class_00148030
{
public:
    bool sub_00148030();
    char m_pad00[0x188];
    Field188* m_Field188; // +0x188
};

bool Class_00148030::sub_00148030()
{
    if (m_Field188) {
        return m_Field188->sub_000BEEF0() == 3;
    }
    return false;
}
