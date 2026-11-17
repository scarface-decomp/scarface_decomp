// bin: xb
// va: 0x000F4E60
// tool: the portal's starter code (no AI)
// sub_000F4E60 (0x000F4E60, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00164210(int);
    bool sub_00164430();
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_000F4E60
{
public:
    void sub_000F4E60(bool a1);
    char m_pad00[0x84];
    int m_Field84; // +0x84
    char m_pad88[0x4D9];
    bool m_Field561; // +0x561
};

void Class_000F4E60::sub_000F4E60(bool a1)
{
    int t2;

    m_Field561 = a1;
    if (!a1) {
        t2 = sub_0002AC90(m_Field84);
        if (!((Object*)t2)->sub_00164430()) {
            ((Object*)t2)->sub_00164210(0);
        }
    }
}
