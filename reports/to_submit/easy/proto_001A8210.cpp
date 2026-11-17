// bin: proto
// va: 0x001A8210
// tool: the portal's starter code (no AI)
// sub_001A8210 (0x001A8210, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001AF720(int, int);
};

extern "C" int DAT_00460C24;

class Class_001A8210
{
public:
    void sub_001A8210(int a1);
    char m_pad00[0x98];
    int m_Field98; // +0x98
    char m_pad9C[0x4];
    int m_FieldA0; // +0xA0
};

void Class_001A8210::sub_001A8210(int a1)
{
    int t2;

    *(int*)(m_Field98 + (m_FieldA0 * 4)) = ((Object*)DAT_00460C24)->sub_001AF720(a1, 0);
    t2 = m_FieldA0;
    if (*(int*)(m_Field98 + (m_FieldA0 * 4))) {
        m_FieldA0 = t2 + 1;
    }
}
