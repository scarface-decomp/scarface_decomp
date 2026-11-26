// bin: xb
// va: 0x002BF930
// what: Unmounts the save drive's memory unit: closes any directory searches still open, then unmounts the unit.
// tool: Claude (from SPEC-016)

extern "C" int __stdcall sub_0030A4EB(void* search);                            // XFindClose
extern "C" unsigned int __stdcall sub_00396CB7(int port, int slot);             // XUnmountMU

// One directory search in progress: the pattern and the system's handle (SPEC-016 section 7.1).
struct Search
{
    char m_Pattern[0x204];  // +0x0
    void* m_Handle;         // +0x204
};

class XboxSaveDrive
{
public:
    void sub_002BF930();

    void GetPortAndSlot(int* port, int* slot)
    {
        if (m_Name[0] == 'U')
        {
            *port = -1;
            *slot = -1;
        }
        else
        {
            *port = m_Name[7] - '1';
            *slot = m_Name[8] - 'A';
        }
    }

    char m_pad00[0xE8];
    char m_Name[0x11];          // +0xE8
    bool m_Mounted;             // +0xF9
    char m_DriveLetter;         // +0xFA
    char m_padFB[0x11];
    Search m_Searches[4];       // +0x10C
};

void XboxSaveDrive::sub_002BF930()
{
    if (m_DriveLetter == 'U')
    {
        return;
    }
    if (!m_Mounted)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (m_Searches[i].m_Handle != (void*)0xFFFFFFFF)
        {
            sub_0030A4EB(m_Searches[i].m_Handle);
            m_Searches[i].m_Handle = (void*)0xFFFFFFFF;
        }
    }

    int port;
    int slot;
    GetPortAndSlot(&port, &slot);
    sub_00396CB7(port, slot);
    m_Mounted = false;
}
