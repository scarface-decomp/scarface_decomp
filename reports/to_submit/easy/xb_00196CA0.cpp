// bin: xb
// va: 0x00196CA0
// tool: the portal's starter code (no AI)
// sub_00196CA0 (0x00196CA0, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000EB690();
    void sub_000EBA00();
};

extern "C" int __stdcall sub_000EB680(int, int);

class Class_00196CA0
{
public:
    void sub_00196CA0(bool a1);
    void sub_00195C40();
    void sub_00196730();
    void sub_00196950(int);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x50];
    unsigned char m_Field58; // +0x58
};

void Class_00196CA0::sub_00196CA0(bool a1)
{
    if (m_Field58 & 1) {
        ((Object*)sub_000EB680(121, (int)(&m_Field04)))->sub_000EBA00();
        if (((Object*)sub_000EB680(121, 0))->sub_000EB690() == 1) {
            sub_00196950(0);
        }
        if (a1) {
            sub_00195C40();
        }
        sub_00196730();
        m_Field58 &= 254;
    }
}
