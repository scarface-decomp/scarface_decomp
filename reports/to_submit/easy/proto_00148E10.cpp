// bin: proto
// va: 0x00148E10
// tool: the portal's starter code (no AI)
// sub_00148E10 (0x00148E10, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_00148E10
{
public:
    int sub_00148E10();
    char m_pad00[0x3DC];
    int m_Field3DC; // +0x3DC
};

int Class_00148E10::sub_00148E10()
{
    return sub_00028120(m_Field3DC) != 0;
}
