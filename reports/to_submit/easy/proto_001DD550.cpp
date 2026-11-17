// bin: proto
// va: 0x001DD550
// tool: the portal's starter code (no AI)
// sub_001DD550 (0x001DD550, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4E0(int);
};

extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;

class Class_001DD550
{
public:
    bool sub_001DD550();
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

bool Class_001DD550::sub_001DD550()
{
    int t2;

    t2 = DAT_00462DD4.sub_0008D4E0(DAT_00462DD8);
    if (t2) {
        return m_Field10 == *(int*)(t2 + 368);
    }
    return false;
}
