// bin: xb
// va: 0x000E6040
// tool: the portal's starter code (no AI)
// sub_000E6040 (0x000E6040, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0017E700();
};

struct Field0C
{
    int sub_000CFF30();
};

extern "C" char DAT_0039E23C[];
extern "C" void __cdecl sub_0006FB50(int, int, int);

class Class_000E6040
{
public:
    void sub_000E6040();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
    bool m_Field10; // +0x10
};

void Class_000E6040::sub_000E6040()
{
    int t1, t2;

    t1 = m_Field0C->sub_000CFF30();
    t2 = m_Field08->sub_0017E700();
    if (t2) {
        if (!*(unsigned char*)t2) goto L_2E;
        sub_0006FB50((int)DAT_0039E23C, t1, t2);
    }
L_2E:
    m_Field10 = true;
}
