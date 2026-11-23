// bin: proto
// va: 0x000F83C0
// what: 
// tool: the portal's starter code (no AI)

// sub_000F83C0 (Proto 0x000F83C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000F7B40(void);

class Class_000F83C0
{
public:
    int sub_000F83C0(int a1, int a2);
    char m_pad00[0x58];
    int m_Field58; // +0x58
};

int Class_000F83C0::sub_000F83C0(int a1, int a2)
{
    int t2;

    sub_000F7B40();
    t2 = m_Field58;
    *(int*)(m_Field58 + 52) = a1;
    *(int*)(t2 + 56) = a2;
    *(int*)(t2 + 48) = 1;
    return t2;
}
