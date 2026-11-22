// bin: proto
// va: 0x0003C050
// what: 
// tool: the portal's starter code (no AI)

// sub_0003C050 (Proto 0x0003C050, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0003BE90(int);
};

class Class_0003C050
{
public:
    void sub_0003C050();
    char m_pad00[0x10];
    Field10* m_Field10; // +0x10
    char m_pad14[0x1];
    bool m_Field15; // +0x15
};

void Class_0003C050::sub_0003C050()
{
    if (m_Field10) {
        if (!m_Field15) goto L_1B;
        m_Field10->sub_0003BE90((int)this);
        m_Field15 = false;
    }
L_1B:
    ;
}
