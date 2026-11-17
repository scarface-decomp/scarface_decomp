// bin: xb
// va: 0x000C7940
// tool: the portal's starter code (no AI)
// sub_000C7940 (0x000C7940, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field40
{
    int sub_000C6300();
    int sub_000C6340(int);
};

struct Object
{
    void sub_001C42C0();
};

extern "C" int __stdcall sub_001C3490(int, int, int, int, int, int, int, int);

class Class_000C7940
{
public:
    void sub_000C7940(int a1);
    void sub_000C7630(int, int, int);
    char m_pad00[0x40];
    Field40* m_Field40; // +0x40
    char m_pad44[0x24];
    int m_Field68; // +0x68
    char m_pad6C[0xA];
    bool m_Field76; // +0x76
};

void Class_000C7940::sub_000C7940(int a1)
{
    if (!m_Field40->sub_000C6300()) {
        if (m_Field40->sub_000C6340(m_Field68)) goto L_49;
        if (!m_Field76) goto L_58;
        ((Object*)sub_001C3490(0, a1, 1, 16, 0, 0, 0, 0))->sub_001C42C0();
        return;
    }
L_49:
    sub_000C7630(m_Field68, 0, 1);
L_58:
    ;
}
