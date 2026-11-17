// bin: proto
// va: 0x00133F50
// tool: the portal's starter code (no AI)
// sub_00133F50 (0x00133F50, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_00133F50
{
public:
    int sub_00133F50();
    char m_pad00[0xC0];
    int m_FieldC0; // +0xC0
};

int Class_00133F50::sub_00133F50()
{
    return sub_00028120(m_FieldC0);
}
