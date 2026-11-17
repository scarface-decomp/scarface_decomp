// bin: proto
// va: 0x001A62D0
// tool: the portal's starter code (no AI)
// sub_001A62D0 (0x001A62D0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_0002BC20();
};

class Class_001A62D0
{
public:
    bool sub_001A62D0();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

bool Class_001A62D0::sub_001A62D0()
{
    int t1;

    t1 = m_Field0C;
    if (m_Field0C) {
        return ((Object*)t1)->sub_0002BC20();
    }
    return false;
}
