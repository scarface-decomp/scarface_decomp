// bin: xb
// va: 0x00257AD0
// what: 
// tool: the portal's starter code (no AI)

// sub_00257AD0 (0x00257AD0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D5910[];
extern "C" int __cdecl sub_00027590(int);

class Class_00257AD0
{
public:
    Class_00257AD0* sub_00257AD0(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_00257AD0* Class_00257AD0::sub_00257AD0(int a1, int a2)
{
    m_Field04 = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field08 = a1;
    m_Field00 = (int)DAT_003D5910;
    m_Field0C = a2;
    m_Field10 = sub_00027590((a2 + (a2 * 2)) << 2);
    m_Field14 = sub_00027590(m_Field0C);
    return this;
}
