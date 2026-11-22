// bin: proto
// va: 0x000A8670
// what: 
// tool: the portal's starter code (no AI)

// sub_000A8670 (Proto 0x000A8670, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_000A8670
{
public:
    int sub_000A8670();
    char m_pad00[0x10];
    float m_Field10; // +0x10
};

int Class_000A8670::sub_000A8670()
{
    if (DAT_0037CE50 > m_Field10) {
        return 1;
    }
    return 0;
}
