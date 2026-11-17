// bin: proto
// va: 0x000AF330
// tool: the portal's starter code (no AI)
// sub_000AF330 (0x000AF330, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    int sub_0009F190();
};

struct Field240
{
    void sub_000ADCF0(int, int, int);
};

class Class_000AF330
{
public:
    void sub_000AF330(int a1);
    char m_pad00[0x4];
    Field04* m_Field04; // +0x04
    char m_pad08[0x1B0];
    int m_Field1B8; // +0x1B8
    char m_pad1BC[0x3C];
    bool m_Field1F8; // +0x1F8
    char m_pad1F9[0x47];
    Field240 m_Field240; // +0x240
};

void Class_000AF330::sub_000AF330(int a1)
{
    int t2;

    if (m_Field1F8) {
        t2 = m_Field04->sub_0009F190();
        if (!t2) goto L_31;
        m_Field240.sub_000ADCF0(a1, t2, (int)(&m_Field1B8));
    }
L_31:
    ;
}
