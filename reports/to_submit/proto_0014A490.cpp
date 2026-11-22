// bin: proto
// va: 0x0014A490
// what: 
// tool: the portal's starter code (no AI)

// sub_0014A490 (Proto 0x0014A490, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00142CE0();
};

extern "C" int DAT_00462DD4;
extern "C" int __cdecl sub_00142FC0(void);

class Class_0014A490
{
public:
    bool sub_0014A490();
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

bool Class_0014A490::sub_0014A490()
{
    if (m_Field10 == DAT_00462DD4) {
        return ((Object*)sub_00142FC0())->sub_00142CE0();
    }
    return false;
}
