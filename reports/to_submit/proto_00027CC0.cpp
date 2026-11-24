// bin: proto
// va: 0x00027CC0
// what: 
// tool: the portal's starter code (no AI)

// sub_00027CC0 (Proto 0x00027CC0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00027CC0
{
public:
    int sub_00027CC0();
    char m_pad00[0x94];
    int m_Field94; // +0x94
};

int Class_00027CC0::sub_00027CC0()
{
    int t1;

    t1 = m_Field94;
    if (m_Field94) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
