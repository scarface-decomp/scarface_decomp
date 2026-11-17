// bin: proto
// va: 0x000AFE40
// tool: the portal's starter code (no AI)
// sub_000AFE40 (0x000AFE40, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000ABFE0();
};

extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0009EFE0(void);

class Class_000AFE40
{
public:
    void sub_000AFE40();
    char m_pad00[0x1FC];
    int m_Field1FC; // +0x1FC
};

void Class_000AFE40::sub_000AFE40()
{
    int t2;

    if (m_Field1FC) {
        sub_0009EFE0();
        t2 = m_Field1FC;
        if (m_Field1FC) {
            ((Object*)t2)->sub_000ABFE0();
            sub_00025160(t2);
        }
        m_Field1FC = 0;
    }
}
