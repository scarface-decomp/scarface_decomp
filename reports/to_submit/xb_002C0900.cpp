// bin: xb
// va: 0x002C0900
// what: Ends a save-drive operation: records wrong or no media if the unit was swapped with files open, else clears its changed mark; true if no error.
// tool: Claude (from the bytes; SPEC-016 sections 1 and 9)

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
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

    void ClearChanged(int port, int slot)
    {
        if (port < 0 || slot < 0)
        {
            return;
        }
        m_Changed &= ~(unsigned char)(1 << (port + slot * 4));
    }

    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

extern "C" MemoryUnits DAT_004BDDF0;

namespace core
{
    class XboxSaveDrive
    {
    public:
        void sub_002C04C0();
        int vfunc_09();

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
        int m_Field7C;              // +0x7C: a copy of the error, kept in the base part of the object
        char m_pad80[0x50];
        int m_LastError;            // +0xD0
        char m_padD4[0x10];
        unsigned int m_OpenFiles;   // +0xE4
        char m_Name[0x11];          // +0xE8
        bool m_Mounted;             // +0xF9
        char m_DriveLetter;         // +0xFA
    };
}

int core::XboxSaveDrive::vfunc_09()
{
    sub_002C04C0();
    if (m_DriveLetter != 'U')
    {
        int port;
        int slot;
        GetPortAndSlot(&port, &slot);
        if (m_OpenFiles != 0)
        {
            if (DAT_004BDDF0.HasChanged(port, slot))
            {
                if (DAT_004BDDF0.IsPresent(port, slot))
                {
                    m_Field7C = 3;
                    m_LastError = 3;
                }
                else
                {
                    m_Field7C = 4;
                    m_LastError = 4;
                }
                return 0;
            }
        }
        else
        {
            DAT_004BDDF0.ClearChanged(port, slot);
        }
    }
    return m_LastError == 0;
}
