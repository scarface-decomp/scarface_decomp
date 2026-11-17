// bin: xb
// va: 0x00163CE0
// tool: the portal's starter code (no AI)
// sub_00163CE0 (0x00163CE0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000D89E0();
};

class Class_00163CE0
{
public:
    bool sub_00163CE0();
    char m_pad00[0x1AC];
    int m_Field1AC; // +0x1AC
};

bool Class_00163CE0::sub_00163CE0()
{
    int t2;

    t2 = *(int*)(m_Field1AC + 376);
    if (*(int*)(m_Field1AC + 376)) {
        return ((Object*)t2)->sub_000D89E0();
    }
    return false;
}
