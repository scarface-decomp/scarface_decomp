// bin: proto
// va: 0x0013CC30
// tool: the portal's starter code (no AI)
// sub_0013CC30 (0x0013CC30, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_0013CC30
{
public:
    int sub_0013CC30();
    int m_Field00; // +0x00
};

int Class_0013CC30::sub_0013CC30()
{
    return !sub_00028120(m_Field00);
}
