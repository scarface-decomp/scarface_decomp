// bin: proto
// va: 0x0017C920
// what: 
// tool: the portal's starter code (no AI)

// sub_0017C920 (Proto 0x0017C920, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039AB24[];
extern "C" int __cdecl sub_00028CF0(int, int);

class Class_0017C920
{
public:
    void sub_0017C920();
    char m_pad00[0x64];
    int m_Field64; // +0x64
};

void Class_0017C920::sub_0017C920()
{
    m_Field64 = sub_00028CF0((int)DAT_0039AB24, 0);
}
