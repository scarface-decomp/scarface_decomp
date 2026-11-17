// bin: xb
// va: 0x00163C60
// tool: the portal's starter code (no AI)
// sub_00163C60 (0x00163C60, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1AC
{
    bool sub_000D2130(int);
};

class Class_00163C60
{
public:
    bool sub_00163C60();
    char m_pad00[0x1AC];
    Field1AC* m_Field1AC; // +0x1AC
};

bool Class_00163C60::sub_00163C60()
{
    if (m_Field1AC) {
        return m_Field1AC->sub_000D2130(1);
    }
    return false;
}
