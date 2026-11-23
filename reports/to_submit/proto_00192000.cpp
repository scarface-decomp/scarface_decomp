// bin: proto
// va: 0x00192000
// what: 
// tool: the portal's starter code (no AI)

// sub_00192000 (Proto 0x00192000, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00192000
{
public:
    int sub_00192000();
    char m_pad00[0x8C];
    int m_Field8C; // +0x8C
};

int Class_00192000::sub_00192000()
{
    return m_Field8C;
}
