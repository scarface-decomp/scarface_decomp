// bin: proto
// va: 0x00139210
// tool: the portal's starter code (no AI)
// sub_00139210 (0x00139210, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD90;

class Class_00139210
{
public:
    void sub_00139210();
    char m_pad00[0x204];
    float m_Field204; // +0x204
};

void Class_00139210::sub_00139210()
{
    m_Field204 = DAT_0037CD90;
}
