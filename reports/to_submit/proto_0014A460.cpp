// bin: proto
// va: 0x0014A460
// what: 
// tool: the portal's starter code (no AI)

// sub_0014A460 (Proto 0x0014A460, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_0002BC00();
};

extern "C" int DAT_00462DD4;
extern "C" int __cdecl sub_00144F30(void);

class Class_0014A460
{
public:
    bool sub_0014A460();
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

bool Class_0014A460::sub_0014A460()
{
    int t1;

    t1 = sub_00144F30();
    if (m_Field10 == DAT_00462DD4) {
        if (!t1) goto L_1F;
        return ((Object*)t1)->sub_0002BC00();
    }
L_1F:
    return false;
}
