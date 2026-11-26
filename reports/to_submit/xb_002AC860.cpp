// bin: xb
// va: 0x002AC860
// what: core::Drive's destructor: destroys its list of libraries and its base parts, then frees the object if asked to.
// tool: Claude (from SPEC-017 section 4.12)

extern "C" char DAT_0039E22C[];     // core::IRefCount's table
extern "C" char DAT_0039F08C[];     // core::BaseObject's table
extern "C" char DAT_0039F094[];     // core::Object's table
extern "C" char DAT_003DAC24[];     // core::SafeRefCount's table
extern "C" char DAT_003DAC34[];     // core::Drive's table for the part at +0xC
extern "C" char DAT_003DAC44[];     // core::Drive's table for the part at +0x4
extern "C" char DAT_003DAC4C[];     // core::Drive's main table
extern "C" void* DAT_0045894C;      // the allocator in use

// The three base parts, whose constructors and destructors the compiler expands (SPEC-017 section 1).
struct RefCountPart
{
    void* m_Table;      // +0x0
};

struct ObjectPart
{
    void* m_Table;      // +0x0
    void* m_Allocator;  // +0x4
};

struct SafeRefCountPart
{
    void* m_Table;      // +0x0
    int m_RefCount;     // +0x4
};

// The list of file libraries a drive keeps (0x40 bytes); its functions know what is inside.
struct LibraryList
{
    void sub_002AD160();    // its constructor
    void sub_002ACC30();    // its destructor
    char m_pad00[0x40];
};

namespace core
{
    class Drive
    {
    public:
        Drive* vfunc_03(unsigned int flags);

        void* m_Table00;            // +0x00
        void* m_Table04;            // +0x04
        void* m_Allocator;          // +0x08
        void* m_Table0C;            // +0x0C
        int m_RefCount;             // +0x10
        LibraryList m_Libraries;    // +0x14
        void* m_Head;               // +0x54
        void* m_Tail;               // +0x58
        int m_ErrorBehaviour;       // +0x5C
        void* m_ErrorSemaphore;     // +0x60
        void* m_HandlerThread;      // +0x64
        void* m_Handler;            // +0x68
        void* m_UserData;           // +0x6C
        bool m_InError;             // +0x70
        void* m_Failed;             // +0x74
        bool m_ReportClear;         // +0x78
        bool m_InHandler;           // +0x79
        char m_Media[0x54];         // +0x7C
        int m_LastError;            // +0xD0
        void* m_Thread;             // +0xD4
    };
}

void __cdecl sub_002444F0(void* allocator, void* memory);       // frees memory

inline void DestroySafeRefCount(SafeRefCountPart* part)
{
    part->m_Table = DAT_003DAC24;
}

inline void DestroyObject(ObjectPart* part)
{
    DAT_0045894C = part->m_Allocator;
    part->m_Table = DAT_0039F08C;
}

inline void DestroyRefCount(RefCountPart* part)
{
    part->m_Table = DAT_0039E22C;
}

core::Drive* core::Drive::vfunc_03(unsigned int flags)
{
    m_Table00 = DAT_003DAC4C;
    m_Table04 = DAT_003DAC44;
    m_Table0C = DAT_003DAC34;
    m_Libraries.sub_002ACC30();
    DestroySafeRefCount((SafeRefCountPart*)&m_Table0C);
    DestroyObject((ObjectPart*)&m_Table04);
    DestroyRefCount((RefCountPart*)&m_Table00);
    if (flags & 1)
    {
        sub_002444F0(DAT_0045894C, this);
    }
    return this;
}
