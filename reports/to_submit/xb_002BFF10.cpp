// bin: xb
// va: 0x002BFF10
// what: Mounts the save drive's memory unit: fails if the unit was swapped while files are open, otherwise unmounts a changed unit, mounts it and records the result.
// tool: Claude (from SPEC-016)

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
    void sub_002BF6A0();                    // refresh both masks from the system
    bool sub_002BF700(int port, int slot);  // is the unit at (port, slot) present

    bool HasChanged(int port, int slot)
    {
        if (port < 0 || slot < 0)
        {
            return false;
        }
        return (m_Changed & (unsigned char)(1 << (port + slot * 4))) != 0;
    }

    void ClearChanged(int port, int slot)
    {
        m_Changed &= ~(unsigned char)(1 << (port + slot * 4));
    }

    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

extern "C" MemoryUnits DAT_004BDDF0;
extern "C" unsigned int __stdcall sub_00396B85(int port, int slot, char* driveLetter);     // XMountMU

class XboxSaveDrive
{
public:
    int sub_002BFE10(unsigned int code);
    bool sub_002BFF10();
    void sub_002BF8F0(int* port, int* slot);
    void sub_002BF930();

    char m_pad00[0xD0];
    int m_LastError;            // +0xD0
    char m_padD4[0x10];
    unsigned int m_OpenFiles;   // +0xE4
    char m_Name[0x11];          // +0xE8
    bool m_Mounted;             // +0xF9
    char m_DriveLetter;         // +0xFA
};

int XboxSaveDrive::sub_002BFE10(unsigned int code)
{
    switch (code)
    {
    case 0:         // ERROR_SUCCESS
        return 0;
    case 2:         // ERROR_FILE_NOT_FOUND
    case 3:         // ERROR_PATH_NOT_FOUND
    case 15:        // ERROR_INVALID_DRIVE
        return 1;
    case 11:        // ERROR_BAD_FORMAT
        return 5;
    case 14:        // ERROR_OUTOFMEMORY
        return 8;
    case 17:        // ERROR_NOT_SAME_DEVICE
        return 3;
    case 0x1A:      // ERROR_NOT_DOS_DISK
        return 0xB;
    case 0x1B:      // ERROR_SECTOR_NOT_FOUND
        return 5;
    case 0x22:      // ERROR_WRONG_DISK
        return 3;
    case 0x55:      // ERROR_ALREADY_ASSIGNED
        return 0;
    case 0x70:      // ERROR_DISK_FULL
        return 7;
    case 0x3ED:     // ERROR_UNRECOGNIZED_VOLUME
        return 5;
    case 0x48F:     // ERROR_DEVICE_NOT_CONNECTED
    {
        int port;
        int slot;

        DAT_004BDDF0.sub_002BF6A0();
        sub_002BF8F0(&port, &slot);
        if (DAT_004BDDF0.sub_002BF700(port, slot))
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
    default:
        return 8;
    }
}

bool XboxSaveDrive::sub_002BFF10()
{
    int port;
    int slot;

    if (m_Name[0] == 'U')
    {
        port = -1;
        slot = -1;
    }
    else
    {
        port = m_Name[7] - '1';
        slot = m_Name[8] - 'A';
    }

    DAT_004BDDF0.sub_002BF6A0();
    if (DAT_004BDDF0.HasChanged(port, slot))
    {
        if (m_OpenFiles > 0)
        {
            m_LastError = sub_002BFE10(0x48F);      // ERROR_DEVICE_NOT_CONNECTED
            return false;
        }
        DAT_004BDDF0.ClearChanged(port, slot);
        sub_002BF930();
    }

    if (!m_Mounted)
    {
        unsigned int result = sub_00396B85(port, slot, &m_DriveLetter);
        if (result != 0)
        {
            if (result == 0x70)     // ERROR_DISK_FULL
            {
                m_LastError = 0xD;
                return false;
            }
            m_LastError = sub_002BFE10(result);
            return false;
        }
    }

    m_Mounted = true;
    m_LastError = 0;
    return true;
}
