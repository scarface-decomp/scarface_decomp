// bin: xb
// va: 0x00163EA0
// tool: the portal's starter code (no AI)
// sub_00163EA0 (0x00163EA0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000CF820();
};

class Class_00163EA0
{
public:
    bool sub_00163EA0();
    char m_pad00[0x1AC];
    int m_Field1AC; // +0x1AC
};

bool Class_00163EA0::sub_00163EA0()
{
    int t1;

    t1 = m_Field1AC;
    if (m_Field1AC) {
        return ((Object*)t1)->sub_000CF820();
    }
    return false;
}
