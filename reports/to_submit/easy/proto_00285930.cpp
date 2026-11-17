// bin: proto
// va: 0x00285930
// tool: the portal's starter code (no AI)
// sub_00285930 (0x00285930, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00317B60(int);

class Class_00285930
{
public:
    void sub_00285930(int a1);
    char m_pad00[0x108];
    int m_Field108; // +0x108
};

void Class_00285930::sub_00285930(int a1)
{
    if (a1 != m_Field108) {
        m_Field108 = a1;
        a1 = a1;
        sub_00317B60(a1);
        return;
    }
}
