// bin: proto
// va: 0x00147FC0
// what: 
// tool: the portal's starter code (no AI)

// sub_00147FC0 (Proto 0x00147FC0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000D74C0(void);

class Class_00147FC0
{
public:
    int sub_00147FC0();
    char m_pad00[0x3E0];
    int m_Field3E0; // +0x3E0
};

int Class_00147FC0::sub_00147FC0()
{
    int t1, t2;

    t1 = sub_000D74C0();
    t2 = *(int*)t1;
    m_Field3E0 = *(int*)t1;
    return t2;
}
