// bin: xb
// va: 0x002BF700
// what: Says whether the memory unit at a port and slot is present; a negative port or slot counts as present.
// tool: Claude (from SPEC-016)

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
    bool sub_002BF700(int port, int slot);
    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

bool MemoryUnits::sub_002BF700(int port, int slot)
{
    if (port < 0 || slot < 0)
    {
        return true;
    }
    return (m_Present & (unsigned char)(1 << (port + slot * 4))) != 0;
}
