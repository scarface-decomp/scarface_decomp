// bin: proto
// va: 0x00147290
// what: 
// tool: the portal's starter code (no AI)

// sub_00147290 (Proto 0x00147290, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00200280(int);

class Class_00147290
{
public:
    void sub_00147290(int a1);
    char m_pad00[0xAC];
    int m_FieldAC; // +0xAC
};

void Class_00147290::sub_00147290(int a1)
{
    m_FieldAC = sub_00200280(a1);
}
