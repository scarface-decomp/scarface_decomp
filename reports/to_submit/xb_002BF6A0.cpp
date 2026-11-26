// bin: xb
// va: 0x002BF6A0
// what: Asks the system which memory units were inserted or removed and updates the present and changed masks.
// tool: Claude (from SPEC-016)

extern "C" int __stdcall sub_00396663(void* type, unsigned int* inserted, unsigned int* removed);    // XGetDeviceChanges
extern "C" char DAT_00395660[];     // the memory-unit device type

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
    void sub_002BF6A0();
    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

void MemoryUnits::sub_002BF6A0()
{
    unsigned int inserted;
    unsigned int removed;

    if (sub_00396663(DAT_00395660, &inserted, &removed))
    {
        unsigned char in = (unsigned char)((inserted & 0xF) | ((inserted >> 12) & 0xF0));
        unsigned char out = (unsigned char)((removed & 0xF) | ((removed >> 12) & 0xF0));
        m_Present ^= in ^ out;
        m_Changed |= in | out;
    }
}
