// bin: xb
// va: 0x002C04C0
// what: Refreshes the drive's media information: checks the memory unit is there and mounted, reads its name, then its free space and sector size.
// tool: Claude (from SPEC-016)

extern "C" void* __cdecl memset(void* to, int value, unsigned int count);
#pragma intrinsic(memset)

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
    void sub_002BF6A0();                    // refresh both masks from the system

    bool IsPresent(int port, int slot)
    {
        if (port < 0 || slot < 0)
        {
            return true;
        }
        return (m_Present & (unsigned char)(1 << (port + slot * 4))) != 0;
    }

    bool HasChanged(int port, int slot)
    {
        if (port < 0 || slot < 0)
        {
            return false;
        }
        return (m_Changed & (unsigned char)(1 << (port + slot * 4))) != 0;
    }

    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

extern "C" MemoryUnits DAT_004BDDF0;

struct Size64
{
    unsigned int m_Low;     // +0x0
    unsigned int m_High;    // +0x4
};

extern "C" unsigned int __stdcall sub_0023699D(char driveLetter, unsigned short* name, unsigned int nameLength);   // XMUNameFromDriveLetter
extern "C" int __stdcall sub_002363D3(const char* drive, Size64* freeToCaller, Size64* total, Size64* totalFree);  // GetDiskFreeSpaceExA
extern "C" unsigned int __stdcall sub_00236902(const char* drive);                                                 // XGetDiskSectorSizeA
extern "C" unsigned int __stdcall sub_00234B47();                                                                  // GetLastError

int __cdecl sub_002C0480(char* destination, const unsigned short* source, int a, int capacity, int c);

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        void sub_002BF930();
        void sub_002C04C0();

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

        char m_pad00[0x7C];
        int m_MediaState;           // +0x7C: the error value again (SPEC-016 section 12.1)
        unsigned int m_FreeBytes;   // +0x80
        unsigned int m_FreeSectors; // +0x84
        unsigned int m_SectorSize;  // +0x88
        char m_VolumeName[0x41];    // +0x8C
        char m_padCD[0x3];
        int m_LastError;            // +0xD0
        char m_padD4[0x10];
        unsigned int m_OpenFiles;   // +0xE4
        char m_Name[0x11];          // +0xE8
        bool m_Mounted;             // +0xF9
        char m_DriveLetter;         // +0xFA
    };
}

void core::XboxSaveDrive::sub_002C04C0()
{
    m_SectorSize = 0x200;
    m_FreeBytes = 0;
    m_FreeSectors = 0;

    if (m_DriveLetter != 'U')
    {
        m_VolumeName[0] = 0;

        int port;
        int slot;
        GetPortAndSlot(&port, &slot);
        DAT_004BDDF0.sub_002BF6A0();
        if (DAT_004BDDF0.HasChanged(port, slot))
        {
            sub_002BF930();
        }
        if (DAT_004BDDF0.IsPresent(port, slot))
        {
            if (!sub_002BFF10())
            {
                m_MediaState = m_LastError;
                return;
            }

            unsigned short wideName[0x20];
            int code = sub_002BFE10(sub_0023699D(m_DriveLetter, wideName, 0x20));
            if (code != 0)
            {
                m_MediaState = code;
                m_VolumeName[0] = 0;
                return;
            }
            memset(m_VolumeName, 0, sizeof(m_VolumeName));
            sub_002C0480(m_VolumeName, wideName, 0, sizeof(m_VolumeName), 0);
        }
        else
        {
            m_MediaState = 4;       // no media
            m_LastError = 4;
            return;
        }
    }

    char drive[4];
    Size64 freeToCaller;
    Size64 totalFree;
    Size64 total;
    drive[0] = m_DriveLetter;
    drive[1] = ':';
    drive[2] = '\\';
    drive[3] = 0;
    if (!sub_002363D3(drive, &freeToCaller, &total, &totalFree))
    {
        m_VolumeName[0] = 0;
        int error = sub_002BFE10(sub_00234B47());
        m_MediaState = error;
        m_LastError = error;
        return;
    }
    m_MediaState = 0;
    m_LastError = 0;

    if (freeToCaller.m_High != 0)
    {
        m_FreeBytes = 0xFFFFFFFF;
    }
    else
    {
        m_FreeBytes = freeToCaller.m_Low;
    }

    unsigned int sectorSize = sub_00236902(drive);
    if (sectorSize != 0)
    {
        m_SectorSize = sectorSize;
    }
    else
    {
        m_SectorSize = 0x200;
    }
    m_FreeSectors = m_FreeBytes / m_SectorSize;
}
