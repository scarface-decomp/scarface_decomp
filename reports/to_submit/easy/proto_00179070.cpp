// bin: proto
// va: 0x00179070
// tool: the portal's starter code (no AI)
// sub_00179070 (0x00179070, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_00179030(int);

class Class_00179070
{
public:
    void sub_00179070(int a1);
    char m_pad00[0x3A0];
    int m_Field3A0; // +0x3A0
};

void Class_00179070::sub_00179070(int a1)
{
    int t1;

    t1 = sub_00179030(a1);
    if (t1 != -1) {
        m_Field3A0 = (t1 * 68) + (int)this + 180;
        return;
    }
    m_Field3A0 = 0;
}
