// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/InstanceDrive.cpp (33 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 33 of 37 functions matched (89.19%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_01 (0x0026DE50, 127 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_01 (0x002AB6F0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DE50
// what: Drops a reference under the lock; at zero it queues a find-close request if a search is open, else destroys itself.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveFindCloseRequest
    {
    public:
        DriveFindCloseRequest* sub_0026D520(InstanceDrive* drive);     // the constructor
        char m_Data[0xC];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_01();

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_01()
{
    Lock();
    m_RefCount--;
    if (m_RefCount == 0)
    {
        if (m_FindOpen)
        {
            m_FindOpen = false;
            Unlock();
            DriveFindCloseRequest* memory = (DriveFindCloseRequest*)sub_0026C140(sizeof(DriveFindCloseRequest));
            DriveFindCloseRequest* request = memory ? memory->sub_0026D520(this) : 0;
            m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
        }
        else
        {
            m_RefCount = 0x5DC;
            Unlock();
            Destroy(1);
        }
    }
    else
    {
        Unlock();
    }
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_00 (0x0026DED0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_00 (0x0026DED0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0048E9B4[];
extern "C" void __cdecl sub_0023F190(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
};

void InstanceDrive::vfunc_00()
{
    sub_0023F190((int)DAT_0048E9B4);
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_01 (0x0026DEE0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_01 (0x0026DEE0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0048E9B4[];
extern "C" void __cdecl sub_0023F180(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_01();
};

void InstanceDrive::vfunc_01()
{
    sub_0023F180((int)DAT_0048E9B4);
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_04 (0x0026DEF0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_04 (Proto 0x0026DEF0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
};

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_04()
{
    m_Field0C->vfunc_08();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_05 (0x0026DF00, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_08 (0x002AB0F0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DF00
// what: Queues a request for this file's size; the answer goes where the argument points.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileGetSizeRequest
    {
    public:
        FileGetSizeRequest* sub_0026D360(InstanceDrive* file, int a);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_05(int a);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_05(int a)
{
    FileGetSizeRequest* memory = (FileGetSizeRequest*)sub_0026C140(sizeof(FileGetSizeRequest));
    FileGetSizeRequest* request = memory ? memory->sub_0026D360(this, a) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_06 (0x0026DF50, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_09 (0x002AAF70), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DF50
// what: Queues a commit request for this file on its drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCommitRequest
    {
    public:
        FileCommitRequest* sub_0026D400(InstanceDrive* file);     // the constructor
        char m_Data[0xC];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_06();

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_06()
{
    FileCommitRequest* memory = (FileCommitRequest*)sub_0026C140(sizeof(FileCommitRequest));
    FileCommitRequest* request = memory ? memory->sub_0026D400(this) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_07 (0x0026DF90, 135 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_07 (0x002AB830), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026DF90
// what: Splits the name and queues a create-directory request for it on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_0020DDB0(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveCreateDirectoryRequest
    {
    public:
        DriveCreateDirectoryRequest* sub_0026D420(InstanceDrive* drive, const char* path);     // the constructor
        char m_Data[0x20];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_07(const char* name);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_07(const char* name)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_0020DDB0(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveCreateDirectoryRequest* memory = (DriveCreateDirectoryRequest*)sub_0026C140(sizeof(DriveCreateDirectoryRequest));
    DriveCreateDirectoryRequest* request = memory ? memory->sub_0026D420(this, path) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_08 (0x0026E020, 135 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_07 (0x002AB830), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026E020
// what: Splits the name and queues a create-directory request for it on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_0020DDB0(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_08();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveCreateDirectoryRequest
    {
    public:
        DriveCreateDirectoryRequest* sub_0026D460(InstanceDrive* drive, const char* path);     // the constructor
        char m_Data[0x20];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_08(const char* name);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_08(const char* name)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_0020DDB0(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveCreateDirectoryRequest* memory = (DriveCreateDirectoryRequest*)sub_0026C140(sizeof(DriveCreateDirectoryRequest));
    DriveCreateDirectoryRequest* request = memory ? memory->sub_0026D460(this, path) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_09 (0x0026E0B0, 146 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_09 (0x002AB950), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026E0B0
// what: Splits the name and queues a find-first request (a directory search) on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_0020DDB0(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveFindFirstRequest
    {
    public:
        DriveFindFirstRequest* sub_0026D4A0(InstanceDrive* drive, const char* path, int b);     // the constructor
        char m_Data[0x114];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_09(const char* name, int b);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_09(const char* name, int b)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_0020DDB0(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveFindFirstRequest* memory = (DriveFindFirstRequest*)sub_0026C140(sizeof(DriveFindFirstRequest));
    DriveFindFirstRequest* request = memory ? memory->sub_0026D4A0(this, path, b) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_10 (0x0026E150, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_06 (0x002AB050), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026E150
// what: Queues a request that sets this file's position.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_10();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileSetPositionRequest
    {
    public:
        FileSetPositionRequest* sub_0026D4F0(InstanceDrive* file, int a);     // the constructor
        char m_Data[0x10];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_10(int a);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_10(int a)
{
    FileSetPositionRequest* memory = (FileSetPositionRequest*)sub_0026C140(sizeof(FileSetPositionRequest));
    FileSetPositionRequest* request = memory ? memory->sub_0026D4F0(this, a) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_11 (0x0026E1A0, 138 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_11 (0x002ABA40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026E1A0
// what: Splits the name and queues a request that deletes that file on the real drive.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_0020DDB0(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class DriveFileDestroyRequest
    {
    public:
        DriveFileDestroyRequest* sub_0026D540(InstanceDrive* drive, const char* path);     // the constructor
        char m_Data[0x110];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_11(const char* name);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_11(const char* name)
{
    const char* full = 0;
    const char* tail = 0;
    char extension[0x14];
    char directory[0x104];
    sub_0020DDB0(name, directory, extension, &tail, &full);
    const char* path = tail;
    if (m_Drive->GetCapabilities() & 0x80)
    {
        path = full;
    }
    DriveFileDestroyRequest* memory = (DriveFileDestroyRequest*)sub_0026C140(sizeof(DriveFileDestroyRequest));
    DriveFileDestroyRequest* request = memory ? memory->sub_0026D540(this, path) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_12 (0x0026E230, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_12 (Proto 0x0026E230, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a1);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_12(int a1)
{
    vfunc_05(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_13 (0x0026E250, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_13 (Proto 0x0026E250, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_13()
{
    vfunc_06();
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_14 (0x0026E260, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_14 (Proto 0x0026E260, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(int a1);
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_14(int a1)
{
    vfunc_07(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_15 (0x0026E280, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_15 (Proto 0x0026E280, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_08(int);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(int a1);
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_15(int a1)
{
    vfunc_08(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_16 (0x0026E2A0, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_16 (Proto 0x0026E2A0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_09(int, int);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(int a1, int a2);
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_16(int a1, int a2)
{
    vfunc_09(a1, a2);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_17 (0x0026E2C0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_17 (Proto 0x0026E2C0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_10(int);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int a1);
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_17(int a1)
{
    vfunc_10(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_18 (0x0026E2E0, 26 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_18 (Proto 0x0026E2E0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class InstanceDrive
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
    virtual void vfunc_11(int);
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int a1);
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

void InstanceDrive::vfunc_18(int a1)
{
    vfunc_11(a1);
    vfunc_23();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_19 (0x0026E300, 61 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_18 (0x002AB220), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026E300
// what: Queues a cancel request for this file at the head of the drive's queue.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCancelRequest
    {
    public:
        FileCancelRequest* sub_0026D580(InstanceDrive* file);     // the constructor
        char m_Data[0xC];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_19();

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_19()
{
    FileCancelRequest* memory = (FileCancelRequest*)sub_0026C140(sizeof(FileCancelRequest));
    FileCancelRequest* request = memory ? memory->sub_0026D580(this) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, true);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_20 (0x0026E340, 85 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_19 (0x002AB260), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0026E340
// what: Queues a request that calls the caller's thread back once this file's earlier requests are done.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_0023F4C0();                     // the calling thread's record
void* __cdecl sub_0026C140(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::InstanceDrive's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class InstanceDrive;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_0026EE10(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCompletionRequest
    {
    public:
        FileCompletionRequest* sub_0026CF40(Thread* thread, InstanceDrive* file, int a, int b);     // the constructor
        char m_Data[0x18];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class InstanceDrive : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_20(int a, int b);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::InstanceDrive::vfunc_20(int a, int b)
{
    FileCompletionRequest* memory = (FileCompletionRequest*)sub_0026C140(sizeof(FileCompletionRequest));
    FileCompletionRequest* request = memory ? memory->sub_0026CF40(sub_0023F4C0(), this, a, b) : 0;
    m_Drive->sub_0026EE10((Request*)request, m_Priority, false);
}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_23 (0x0026E420, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_23 (Proto 0x0026E420, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

extern "C" void __cdecl sub_0023F0F0(int);

namespace core {

class InstanceDrive
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
    virtual bool vfunc_22();
    virtual void vfunc_23();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_23()
{
    if (!vfunc_22()) {
        do {
            m_Field0C->vfunc_04();
            sub_0023F0F0(0);
        } while (!vfunc_22());
    }
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_25 (0x0026E490, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (Proto 0x0026E4C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_25 (0x0026E490, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026EC00();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_25()
{
    m_Field0C->sub_0026EC00();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_26 (0x0026E4A0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (Proto 0x0026E4C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_26 (0x0026E4A0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026EC40();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_26()
{
    m_Field0C->sub_0026EC40();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_27 (0x0026E4B0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (Proto 0x0026E4C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_27 (0x0026E4B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026EC70();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_27()
{
    m_Field0C->sub_0026EC70();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_29 (0x0026E4C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_29 (0x0026E4C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026ED30();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_29()
{
    m_Field0C->sub_0026ED30();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_30 (0x0026E4D0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_30 (0x0026E4D0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026ECF0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_30();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_30()
{
    m_Field0C->sub_0026ECF0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_31 (0x0026E4E0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (Proto 0x0026E4C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_31 (0x0026E4E0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026ECA0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_31()
{
    m_Field0C->sub_0026ECA0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_32 (0x0026E4F0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (Proto 0x0026E4C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_32 (0x0026E4F0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026EDF0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_32()
{
    m_Field0C->sub_0026EDF0();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_33 (0x0026E500, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (Proto 0x0026E4C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_33 (0x0026E500, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_0026ED90();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_33()
{
    m_Field0C->sub_0026ED90();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_35 (0x0026E5E0, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_35 (Proto 0x0026E5E0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_22();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34(int, int, int, int, int, int, int, int);
    virtual void vfunc_35(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void InstanceDrive::vfunc_35(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int t2;

    vfunc_34(a1, a2, a3, a4, a5, a6, a7, a8);
    t2 = *(int*)a1;
    if (*(int*)a1) {
        ((Object*)t2)->vfunc_22();
    }
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_37 (0x0026E6F0, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_37 (Proto 0x0026E6F0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
    virtual void vfunc_22();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36(int, int, int, int, int, int, int);
    virtual void vfunc_37(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

void InstanceDrive::vfunc_37(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int t2;

    vfunc_36(a1, a2, a3, a4, a5, a6, a7);
    t2 = *(int*)a1;
    if (*(int*)a1) {
        ((Object*)t2)->vfunc_22();
    }
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_41 (0x0026E740, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_41 (Proto 0x0026E740, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_41()
{
    m_Field0C->vfunc_06();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_03 (0x0026E7B0, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::InstanceDrive::vfunc_03 (Proto 0x0026E7B0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003B3F38[];
extern "C" char DAT_003B3F44[];
extern "C" char DAT_0048E9B4[];
extern "C" int DAT_0048E9D0;
extern "C" void __cdecl sub_0023F180(int);
extern "C" void __cdecl sub_0023F190(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual InstanceDrive* vfunc_03(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
};

InstanceDrive* InstanceDrive::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_003B3F44;
    m_Field04 = (int)DAT_003B3F38;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_0023F190((int)DAT_0048E9B4);
        ((Object*)DAT_0048E9D0)->vfunc_05((int)this);
        sub_0023F180((int)DAT_0048E9B4);
    }
    return this;
}

}

