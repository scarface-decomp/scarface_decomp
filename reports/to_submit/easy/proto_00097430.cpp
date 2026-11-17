// bin: proto
// va: 0x00097430
// tool: the portal's starter code (no AI)
// sub_00097430 (0x00097430, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00383FC0;

class Class_00097430
{
public:
    int sub_00097430();
    char m_pad00[0x20];
    float m_Field20; // +0x20
};

int Class_00097430::sub_00097430()
{
    if (m_Field20 > DAT_00383FC0) {
        return 1;
    }
    return 0;
}
