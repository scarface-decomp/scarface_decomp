// bin: proto
// va: 0x00098D90
// what: 
// tool: the portal's starter code (no AI)

// sub_00098D90 (Proto 0x00098D90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field00
{
    int sub_00084DA0();
};

struct Field20
{
    void sub_000AB1D0(int);
    void sub_000AB260(int);
};

class Class_00098D90
{
public:
    void sub_00098D90();
    Field00* m_Field00; // +0x00
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

void Class_00098D90::sub_00098D90()
{
    if (m_Field00) {
        m_Field20.sub_000AB1D0(m_Field00->sub_00084DA0());
        m_Field20.sub_000AB260(1);
    }
}
