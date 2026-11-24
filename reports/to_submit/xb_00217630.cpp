// bin: xb
// va: 0x00217630
// what: 
// tool: the portal's starter code (no AI)

// sub_00217630 (0x00217630, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000AB620(int, int);
    void sub_000AB670(int, int);
};

class Class_00217630
{
public:
    void sub_00217630(int a1);
    char m_pad00[0xC4];
    int m_FieldC4; // +0xC4
};

void Class_00217630::sub_00217630(int a1)
{
    ((Object*)m_FieldC4 + 72)->sub_000AB620(a1, 0);
    ((Object*)m_FieldC4 + 72)->sub_000AB670(a1, 0x3C23D70A);
}
