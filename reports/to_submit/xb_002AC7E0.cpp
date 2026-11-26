// bin: xb
// va: 0x002AC7E0
// what: core::Drive's constructor: an empty list of libraries, no error handler, no pending requests, and 3 as its last error.
// tool: Claude (from SPEC-017 section 4.11)

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
        Drive* sub_002AC7E0();

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

void __cdecl sub_00250EB0();

inline void ConstructRefCount(RefCountPart* part)
{
    part->m_Table = DAT_0039E22C;
}

inline void ConstructObject(ObjectPart* part)
{
    part->m_Table = DAT_0039F094;
    part->m_Allocator = DAT_0045894C;
}

inline void ConstructSafeRefCount(SafeRefCountPart* part)
{
    part->m_Table = DAT_003DAC24;
    part->m_RefCount = 1;
}

core::Drive* core::Drive::sub_002AC7E0()
{
    ConstructRefCount((RefCountPart*)&m_Table00);
    ConstructObject((ObjectPart*)&m_Table04);
    ConstructSafeRefCount((SafeRefCountPart*)&m_Table0C);
    m_Table00 = DAT_003DAC4C;
    m_Table04 = DAT_003DAC44;
    m_Table0C = DAT_003DAC34;
    m_Libraries.sub_002AD160();
    m_Head = 0;
    m_Tail = 0;
    m_ErrorBehaviour = 0;
    m_ErrorSemaphore = 0;
    m_HandlerThread = 0;
    m_Handler = 0;
    m_UserData = 0;
    m_InError = false;
    m_Failed = 0;
    m_ReportClear = true;
    m_InHandler = false;
    m_LastError = 3;
    m_Thread = 0;
    sub_00250EB0();
    return this;
}
