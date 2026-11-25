// bin: xb
// va: 0x002BFE10
// what: Turns a Win32 error code into the save drive's own error value; for a disconnected device it asks whether the memory unit is still present.
// tool: Claude (from SPEC-016)

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
    void sub_002BF6A0();                    // refresh both masks from the system
    bool sub_002BF700(int port, int slot);  // is the unit at (port, slot) present
    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

extern "C" MemoryUnits DAT_004BDDF0;

class XboxSaveDrive
{
public:
    int sub_002BFE10(unsigned int code);
    void sub_002BF8F0(int* port, int* slot);
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
