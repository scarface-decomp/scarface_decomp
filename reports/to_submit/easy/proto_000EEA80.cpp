// bin: proto
// va: 0x000EEA80
// tool: the portal's starter code (no AI)
// sub_000EEA80 (0x000EEA80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_000EEA80
{
public:
    int sub_000EEA80();
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

int Class_000EEA80::sub_000EEA80()
{
    return sub_00028120(m_Field20) != 0;
}
