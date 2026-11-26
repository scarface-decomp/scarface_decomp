// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/Drive.cpp (11 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 11 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::Drive::vfunc_00 (0x002AC390, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Takes one more reference to a drive, inside its lock.
// ============================================================================
// bin: xb
// va: 0x002AC390
// what: Takes one more reference to a drive, inside its lock.
// tool: Claude (from SPEC-017)

// A system semaphore's handle.
struct Semaphore
{
    void* m_Handle; // +0x0
};

struct Thread;

Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void __cdecl sub_00283BD0(Semaphore* semaphore);    // signal it once

namespace core
{
    class Drive;
    class DriveThread;

    // A piece of work queued for a drive.
    class Request
    {
    public:
        virtual ~Request();
        virtual int Do();
        virtual bool ShouldCancel(int key);
        virtual Drive* GetDrive();
        virtual int Prepare();
        virtual int vfunc_05();
        virtual int vfunc_06();

        Request* m_Next;    // +0x04
    };

    // A finished request whose owner is still to be told, kept in a list until its thread asks.
    class CompletionCallbackRequest
    {
    public:
        virtual ~CompletionCallbackRequest();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void Finish();
        bool sub_00239EC0(Thread* thread);      // whether this request belongs to that thread

        CompletionCallbackRequest* m_Next;      // +0x04
    };

    // What the game registers to be asked about a drive's errors.
    class ErrorHandler
    {
    public:
        virtual bool OnError(int error, const char* driveName, int a, int b, void* userData);
    };

    // The three base parts (SPEC-017 section 1).
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
        virtual void vfunc_02();
        virtual void vfunc_03();
    };

    class Object
    {
    public:
        virtual void Object00();
        void* m_Allocator;  // +0x08
    };

    class SafeRefCount
    {
    public:
        virtual void Lock();
        virtual void Unlock();
        virtual ~SafeRefCount();
        void sub_002AC3B0();
        void LockedIncrement();

        int m_RefCount;     // +0x10
    };

    class Drive : public IRefCount, public Object, public SafeRefCount
    {
    public:
        virtual void Service();
        virtual const char* GetName();
        void vfunc_00();

        char m_Libraries[0x40];             // +0x14  the list of file libraries
        CompletionCallbackRequest* m_Head;  // +0x54  finished requests waiting for their thread
        CompletionCallbackRequest* m_Tail;  // +0x58
        int m_ErrorBehaviour;               // +0x5C  0, or 2 once a handler or a semaphore is set
        Semaphore* m_ErrorSemaphore;        // +0x60
        Thread* m_HandlerThread;            // +0x64
        ErrorHandler* m_Handler;            // +0x68
        void* m_UserData;                   // +0x6C
        bool m_InError;                     // +0x70
        Request* m_Failed;                  // +0x74  the request that failed
        bool m_ReportClear;                 // +0x78
        bool m_InHandler;                   // +0x79
        char m_Media[0x54];                 // +0x7C  media information
        int m_LastError;                    // +0xD0
        DriveThread* m_Thread;              // +0xD4
    };
}

// core::SafeRefCount's locked increment, expanded into each class's own function.
inline void core::SafeRefCount::LockedIncrement()
{
    Lock();
    ++m_RefCount;
    Unlock();
}

void core::Drive::vfunc_00()
{
    LockedIncrement();
}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_06 (0x002AC750, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_06 (Proto 0x0026EE60), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_06 (Proto 0x002AC750, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1, int a2);
};

int Drive::vfunc_06(int a1, int a2)
{
    return a2;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_11 (0x002AC760, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::Drive: Always returns 0.
// ============================================================================
// Same machine code as core::Drive::vfunc_11 (Proto 0x0026EE70), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_11 (Proto 0x002AC760, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual int vfunc_11(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

int Drive::vfunc_11(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_15 (0x002AC770, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::Drive: Always returns 0.
// ============================================================================
// Same machine code as core::Drive::vfunc_15 (Proto 0x0026EE80), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_15 (Proto 0x002AC770, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
};

int Drive::vfunc_15(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_20 (0x002AC780, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::Drive: Always returns 0.
// ============================================================================
// Same machine code as core::Drive::vfunc_20 (Proto 0x0026EE90), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_20 (Proto 0x002AC780, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual int vfunc_20(int a1, int a2, int a3, int a4);
};

int Drive::vfunc_20(int a1, int a2, int a3, int a4)
{
    return 0;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_22 (0x002AC790, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::Drive: Always returns 1.
// ============================================================================
// Same machine code as core::Drive::vfunc_22 (Proto 0x0026EEA0), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_22 (Proto 0x002AC790, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual int vfunc_22(int a1);
};

int Drive::vfunc_22(int a1)
{
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_00 (0x002AC7A0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_00 (0x002AC7A0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x002AC860. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_002AC860(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_002AC860(); };

class Drive : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    Drive();
    virtual void sub_002AC860();          // the real function; the thunk jumps here
};

Drive::Drive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_02 (0x002AC7B0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_02 (Proto 0x0026EEC0), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_02 (Proto 0x002AC7B0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x002AC860. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Drive_Base0 { public: virtual void sub_002AC860(); char m_pad04[0x8]; };
class Drive_Base1 { public: virtual void sub_002AC860(); };

class Drive : public Drive_Base0, public Drive_Base1
{
public:
    Drive();
    virtual void sub_002AC860();          // the real function; the thunk jumps here
};

Drive::Drive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_03 (0x002AC860, 88 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: core::Drive's destructor: destroys its list of libraries and its base parts, then frees the object if asked to.
// ============================================================================
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

// ============================================================================
// [VERIFIED] core::Drive::vfunc_04 (0x002AC8C0, 259 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Runs the finished requests that belong to the calling thread, then, if the drive is in error, asks the error handler what to do.
// ============================================================================
// bin: xb
// va: 0x002AC8C0
// what: Runs the finished requests that belong to the calling thread, then, if the drive is in error, asks the error handler what to do.
// tool: Claude (from SPEC-017)

// A system semaphore's handle.
struct Semaphore
{
    void* m_Handle; // +0x0
};

struct Thread;

Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void __cdecl sub_00283BD0(Semaphore* semaphore);    // signal it once

namespace core
{
    class Drive;
    class DriveThread;

    // A piece of work queued for a drive.
    class Request
    {
    public:
        virtual ~Request();
        virtual int Do();
        virtual bool ShouldCancel(int key);
        virtual Drive* GetDrive();
        virtual int Prepare();
        virtual int vfunc_05();
        virtual int vfunc_06();

        Request* m_Next;    // +0x04
    };

    // A finished request whose owner is still to be told, kept in a list until its thread asks.
    class CompletionCallbackRequest
    {
    public:
        virtual ~CompletionCallbackRequest();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void Finish();
        bool sub_00239EC0(Thread* thread);      // whether this request belongs to that thread

        CompletionCallbackRequest* m_Next;      // +0x04
    };

    // What the game registers to be asked about a drive's errors.
    class ErrorHandler
    {
    public:
        virtual bool OnError(int error, const char* driveName, int a, int b, void* userData);
    };

    // The three base parts (SPEC-017 section 1).
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
        virtual void vfunc_02();
        virtual void vfunc_03();
    };

    class Object
    {
    public:
        virtual void Object00();
        void* m_Allocator;  // +0x08
    };

    class SafeRefCount
    {
    public:
        virtual void Lock();
        virtual void Unlock();
        virtual ~SafeRefCount();
        void sub_002AC3B0();
        void LockedIncrement();

        int m_RefCount;     // +0x10
    };

    class Drive : public IRefCount, public Object, public SafeRefCount
    {
    public:
        virtual void Service();
        virtual const char* GetName();
        void vfunc_04();
        void sub_002AC570(bool retry);

        char m_Libraries[0x40];             // +0x14  the list of file libraries
        CompletionCallbackRequest* m_Head;  // +0x54  finished requests waiting for their thread
        CompletionCallbackRequest* m_Tail;  // +0x58
        int m_ErrorBehaviour;               // +0x5C  0, or 2 once a handler or a semaphore is set
        Semaphore* m_ErrorSemaphore;        // +0x60
        Thread* m_HandlerThread;            // +0x64
        ErrorHandler* m_Handler;            // +0x68
        void* m_UserData;                   // +0x6C
        bool m_InError;                     // +0x70
        Request* m_Failed;                  // +0x74  the request that failed
        bool m_ReportClear;                 // +0x78
        bool m_InHandler;                   // +0x79
        char m_Media[0x54];                 // +0x7C  media information
        int m_LastError;                    // +0xD0
        DriveThread* m_Thread;              // +0xD4
    };
}

void core::Drive::vfunc_04()
{
    Thread* thread = sub_00283EB0();
    Lock();
    CompletionCallbackRequest** walk = &m_Head;
    CompletionCallbackRequest* lastKept = 0;
    CompletionCallbackRequest* next;
    while (*walk != 0)
    {
        if ((*walk)->sub_00239EC0(thread))
        {
            CompletionCallbackRequest* current = *walk;
            *walk = current->m_Next;
            Unlock();
            current->Finish();
            Lock();
            delete current;
        }
        else
        {
            lastKept = *walk;
            next = lastKept->m_Next;
            walk = &next;
        }
    }
    m_Tail = lastKept;
    if (m_InError == true && m_Handler != 0)
    {
        if (!m_InHandler)
        {
            m_InHandler = true;
            Unlock();
            sub_002AC570(m_Handler->OnError(m_LastError, GetName(), m_Failed->vfunc_06(), m_Failed->vfunc_05(), m_UserData));
            m_InHandler = false;
        }
        else
        {
            Unlock();
        }
    }
    else
    {
        Unlock();
    }
}

// ============================================================================
// [VERIFIED] core::Drive::vfunc_01 (0x002C1450, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::Drive::vfunc_01 (0x002C1450, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002AC3B0();
};

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void Drive::vfunc_01()
{
    ((Object*)(int)this + 12)->sub_002AC3B0();
}

}

