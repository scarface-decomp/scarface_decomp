// bin: xb
// va: 0x00164490
// tool: the portal's starter code (no AI)
// sub_00164490 (0x00164490, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1AC
{
    int sub_000CF6B0();
};

class Class_00164490
{
public:
    bool sub_00164490();
    char m_pad00[0x1AC];
    Field1AC* m_Field1AC; // +0x1AC
};

bool Class_00164490::sub_00164490()
{
    if (m_Field1AC) {
        return m_Field1AC->sub_000CF6B0() == 3;
    }
    return false;
}
