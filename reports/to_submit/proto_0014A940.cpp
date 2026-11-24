// bin: proto
// va: 0x0014A940
// what: 
// tool: the portal's starter code (no AI)

// sub_0014A940 (Proto 0x0014A940, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000DDE80(int);
};

extern "C" int __cdecl sub_00028120(int);

class Class_0014A940
{
public:
    void sub_0014A940(int a1);
    char m_pad00[0xDC];
    int m_FieldDC; // +0xDC
};

void Class_0014A940::sub_0014A940(int a1)
{
    int t2;

    t2 = sub_00028120(m_FieldDC);
    if (t2) {
        ((Object*)t2)->sub_000DDE80(a1);
        return;
    }
}
