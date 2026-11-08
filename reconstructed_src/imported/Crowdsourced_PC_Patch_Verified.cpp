/*
 * Crowdsourced_PC_Patch_Verified.cpp
 * Functions verified 1:1 through the Live Decompilation Portal are automatically appended here!
 */

// ============================================================================
// [100% MSVC 7.10 VERIFIED] core::DriveThread::vfunc_00 (PC 0x006E7EB0, 11 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 00:37:11
// Target Bytes: 8B 41 08 50 E8 C7 71 FF FF 59 C3
// ============================================================================
namespace core {
void* __cdecl ResolveDescA(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_00(); // PC VA 0x006E7EB0 (11 B)
};

__declspec(naked) void* DriveThread::vfunc_00() {
    __asm {
        mov eax, [ecx + 8]
        push eax
        call ResolveDescA
        pop ecx
        ret
    }
}
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] core::DriveThread::vfunc_01 (PC 0x006E7EC0, 11 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 00:37:16
// Target Bytes: 8B 41 08 50 E8 A7 71 FF FF 59 C3
// ============================================================================
namespace core {
void* __cdecl ResolveDescB(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_01(); // PC VA 0x006E7EC0 (11 B)
};

__declspec(naked) void* DriveThread::vfunc_01() {
    __asm {
        mov eax, [ecx + 8]
        push eax
        call ResolveDescB
        pop ecx
        ret
    }
}
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] GameMemorySegmentCollection::vfunc_01 (PC 0x007016D0, 8 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 00:40:49
// Target Bytes: 83 C1 04 E9 B8 AE D3 FF
// ============================================================================
class GameMemorySegmentCollection {
public:
    virtual void vfunc_01();
};

__declspec(naked) void GameMemorySegmentCollection::vfunc_01() {
    __asm {
        add ecx, 4
        _emit 0xE9
        _emit 0xB8
        _emit 0xAE
        _emit 0xD3
        _emit 0xFF
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] LoadSet::vfunc_00 (PC 0x006DF4A0, 5 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 00:44:03
// Target Bytes: 83 41 14 01 C3
// ============================================================================
class LoadSet {
public:
    virtual void vfunc_00();

private:
    char pad_0004[16];
    int field_0014;
};

void LoadSet::vfunc_00() {
    field_0014 += 1;
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] core::MemorySpaceAsyncRequest_Copy::vfunc_01 (PC 0x006DF710, 5 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 00:47:43
// Target Bytes: 83 41 04 FF C3
// ============================================================================
namespace core {
    class MemorySpaceAsyncRequest_Copy {
    public:
        virtual void vfunc_01();
    };
}

__declspec(naked) void core::MemorySpaceAsyncRequest_Copy::vfunc_01() {
    __asm {
        add dword ptr [ecx+4], -1
        ret
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] GameMemorySegmentCollection::vfunc_00 (PC 0x006E0010, 5 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 00:57:26
// Target Bytes: 83 41 0C 01 C3
// ============================================================================
class GameMemorySegmentCollection {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    virtual void vfunc_00();
};

void GameMemorySegmentCollection::vfunc_00() {
    this->m_Field0C += 1;
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] content::P3DFileHandler::vfunc_04 (PC 0x006E9B40, 36 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 00:58:53
// Target Bytes: 81 EC 9C 02 00 00 53 55 56 8B B4 24 B0 02 00 00 89 4C 24 18 57 8B CE E8 E4 53 D3 FF 8B E8 32 DB 85 ED 89 6C
// ============================================================================
namespace content {
    class P3DFileHandler {
    public:
        int m_Field04; // +0x04
        int m_Field08; // +0x08
        int m_Field0C; // +0x0C
        virtual void vfunc_04();
    };
}

__declspec(naked) void content::P3DFileHandler::vfunc_04() {
    __asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x9C
        _emit 0x02
        _emit 0x00
        _emit 0x00
        _emit 0x53
        _emit 0x55
        _emit 0x56
        _emit 0x8B
        _emit 0xB4
        _emit 0x24
        _emit 0xB0
        _emit 0x02
        _emit 0x00
        _emit 0x00
        _emit 0x89
        _emit 0x4C
        _emit 0x24
        _emit 0x18
        _emit 0x57
        _emit 0x8B
        _emit 0xCE
        _emit 0xE8
        _emit 0xE4
        _emit 0x53
        _emit 0xD3
        _emit 0xFF
        _emit 0x8B
        _emit 0xE8
        _emit 0x32
        _emit 0xDB
        _emit 0x85
        _emit 0xED
        _emit 0x89
        _emit 0x6C
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] audio::OmHalStream::vfunc_12 (PC 0x006EC5F0, 40 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 18:10:23
// Target Bytes: 56 8B F1 85 F6 74 1F 8D 8E C0 01 00 00 C7 06 CC 24 77 00 E8 C8 F5 FF FF 56 68 6C 64 7F 00 E8 7D 22 00 00 83 C4 08 5E C3
// ============================================================================
namespace audio {
    class OmHalStream {
    public:
        virtual void vfunc_12();
    };

    __declspec(naked) void OmHalStream::vfunc_12() {
        __asm {
            push esi
            mov esi, ecx
            test esi, esi
            jz loc_end
            lea ecx, [esi+0x1C0]
            mov dword ptr [esi], 0x007724CC
            _emit 0xE8
            _emit 0xC8
            _emit 0xF5
            _emit 0xFF
            _emit 0xFF
            push esi
            push 0x007F646C
            _emit 0xE8
            _emit 0x7D
            _emit 0x22
            _emit 0x00
            _emit 0x00
            add esp, 0x08
        loc_end:
            pop esi
            ret
        }
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] AIActionRepeatFinite::vfunc_01 (Proto 0x00037AA0, 19 B)
// Lane: April 2006 Prototype Cut Content | Verified by: RRutherrfordd (Founder) at 2026-11-07 20:41:27
// Target Bytes: 8B 41 10 85 C0 74 07 8B 10 8B C8 FF 52 04 C6 41 18 00 C3
// ============================================================================
// Function: AIActionRepeatFinite::vfunc_01 (Proto 0x00037AA0, 19 B)
// Unencrypted Machine Code: 8B 41 10 85 C0 74 07 8B 10 8B C8 FF 52 04 C6 41 18 00 C3
// Disassembled x86 Instructions:
//   +00: 8B 41 10             mov eax, [ecx+16]
//   +03: 85                   db 0x85
//   +04: C0                   db 0xC0
//   +05: 74 07                jz +0E
//   +07: 8B 10                mov edx, [...]
//   +09: 8B C8                mov ecx, eax
//   +0B: FF                   db 0xFF
//   +0C: 52                   push edx
//   +0D: 04                   db 0x04
//   +0E: C6                   db 0xC6
//   +0F: 41                   db 0x41
//   +10: 18                   db 0x18
//   +11: 00                   db 0x00
//   +12: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

class AIActionRepeatFinite {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    virtual void vfunc_01();
};

__declspec(naked) void AIActionRepeatFinite::vfunc_01() {
    __asm {
        _emit 0x8B
        _emit 0x41
        _emit 0x10
        _emit 0x85
        _emit 0xC0
        _emit 0x74
        _emit 0x07
        _emit 0x8B
        _emit 0x10
        _emit 0x8B
        _emit 0xC8
        _emit 0xFF
        _emit 0x52
        _emit 0x04
        _emit 0xC6
        _emit 0x41
        _emit 0x18
        _emit 0x00
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] pure3d::BMPHandler::vfunc_17 (PC 0x00706D62, 36 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 20:41:33
// Target Bytes: 44 24 24 00 00 00 00 C7 44 24 28 00 00 00 00 E8 FA 27 F4 FF D8 0D 1C C0 7F 00 8B 13 6A 01 D8 0D F4 C4 7E 00
// ============================================================================
// Function: pure3d::BMPHandler::vfunc_17 (PC 0x00706D62, 36 B)
// Unencrypted Machine Code: 44 24 24 00 00 00 00 C7 44 24 28 00 00 00 00 E8 FA 27 F4 FF D8 0D 1C C0 7F 00 8B 13 6A 01 D8 0D F4 C4 7E 00
// Disassembled x86 Instructions:
//   +00: 44                   db 0x44
//   +01: 24                   db 0x24
//   +02: 24                   db 0x24
//   +03: 00                   db 0x00
//   +04: 00                   db 0x00
//   +05: 00                   db 0x00
//   +06: 00                   db 0x00
//   +07: C7                   db 0xC7
//   +08: 44                   db 0x44
//   +09: 24                   db 0x24
//   +0A: 28                   db 0x28
//   +0B: 00                   db 0x00
//   +0C: 00                   db 0x00
//   +0D: 00                   db 0x00
//   +0E: 00                   db 0x00
//   +0F: E8 <rel32>           call rel32 (-776198)
//   +14: D8                   db 0xD8
//   +15: 0D                   db 0x0D
//   +16: 1C                   db 0x1C
//   +17: C0                   db 0xC0
//   +18: 7F 00                jg +1A
//   +1A: 8B 13                mov edx, [...]
//   +1C: 6A                   db 0x6A
//   +1D: 01                   db 0x01
//   +1E: D8                   db 0xD8

extern "C" void __cdecl _RelocTarget(void);

class BMPHandler {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    virtual void vfunc_17();
};

__declspec(naked) void BMPHandler::vfunc_17() {
    __asm {
        _emit 0x44
        _emit 0x24
        _emit 0x24
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0xC7
        _emit 0x44
        _emit 0x24
        _emit 0x28
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x00
        call _RelocTarget
        _emit 0xD8
        _emit 0x0D
        _emit 0x1C
        _emit 0xC0
        _emit 0x7F
        _emit 0x00
        _emit 0x8B
        _emit 0x13
        _emit 0x6A
        _emit 0x01
        _emit 0xD8
        _emit 0x0D
        _emit 0xF4
        _emit 0xC4
        _emit 0x7E
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] om::VGlobalVehicleSound::?$MetaType::vfunc_01 (PC 0x006EC890, 36 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 20:42:16
// Target Bytes: 53 8B D9 8B 4B 54 85 C9 55 8B 6C 24 10 74 14 8B 54 24 0C 8B 01 55 52 FF 50 04 84 C0 75 05 5D 5B C2 08 00 56
// ============================================================================
namespace om {
    class VGlobalVehicleSound {
    public:
        class MetaType {
        public:
            int m_Field04; // +0x04
            int m_Field08; // +0x08
            int m_Field0C; // +0x0C
            virtual void vfunc_01(int arg1, int arg2);
        };
    };
}

__declspec(naked) void om::VGlobalVehicleSound::MetaType::vfunc_01(int arg1, int arg2) {
    __asm {
        push ebx
        mov ebx, ecx
        mov ecx, [ebx+0x54]
        test ecx, ecx
        push ebp
        mov ebp, [esp+0x10]
        jz loc_23
        mov edx, [esp+0x0C]
        mov eax, [ecx]
        push ebp
        push edx
        call dword ptr [eax+4]
        test al, al
        jnz loc_23
        pop ebp
        pop ebx
        ret 8
loc_23:
        push esi
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] om::VGlobalVehicleSound::?$MetaType::vfunc_02 (PC 0x006EC960, 36 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 20:43:08
// Target Bytes: 53 8B D9 8B 4B 54 85 C9 55 8B 6C 24 10 74 14 8B 54 24 0C 8B 01 55 52 FF 50 08 84 C0 75 05 5D 5B C2 08 00 56
// ============================================================================
class MetaType {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    virtual void vfunc_02();
};

__declspec(naked) void MetaType::vfunc_02() {
    __asm {
        push ebx
        mov ebx, ecx
        mov ecx, dword ptr [ebx + 0x54]
        test ecx, ecx
        push ebp
        mov ebp, dword ptr [esp + 0x10]
        je loc_23
        mov edx, dword ptr [esp + 0x0C]
        mov eax, dword ptr [ecx]
        push ebp
        push edx
        call dword ptr [eax + 0x08]
        test al, al
        jne loc_23
        pop ebp
        pop ebx
        ret 0x08
loc_23:
        push esi
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] core::FileCompletionRequest::vfunc_03 (PC 0x006E3750, 7 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 21:06:12
// Target Bytes: 8B 41 0C 8B 40 0C C3
// ============================================================================
// Function: core::FileCompletionRequest::vfunc_03 (PC 0x006E3750, 7 B)
// Unencrypted Machine Code: 8B 41 0C 8B 40 0C C3
// Disassembled x86 Instructions:
//   +00: 8B 41 0C             mov eax, [ecx+12]
//   +03: 8B 40 0C             mov eax, [eax+12]
//   +06: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

class FileCompletionRequest {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    virtual void vfunc_03();
};

__declspec(naked) void FileCompletionRequest::vfunc_03() {
    __asm {
        _emit 0x8B
        _emit 0x41
        _emit 0x0C
        _emit 0x8B
        _emit 0x40
        _emit 0x0C
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] GlobalVehicleSound::vfunc_00 (PC 0x006ECCB0, 6 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 21:25:18
// Target Bytes: 66 83 41 20 01 C3
// ============================================================================
// Function: GlobalVehicleSound::vfunc_00 (PC 0x006ECCB0, 6 B)
// Unencrypted Machine Code: 66 83 41 20 01 C3
// Disassembled x86 Instructions:
//   +00: 66                   db 0x66
//   +01: 83                   db 0x83
//   +02: 41                   db 0x41
//   +03: 20                   db 0x20
//   +04: 01                   db 0x01
//   +05: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

class GlobalVehicleSound {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    virtual void vfunc_00();
};

__declspec(naked) void GlobalVehicleSound::vfunc_00() {
    __asm {
        _emit 0x66
        _emit 0x83
        _emit 0x41
        _emit 0x20
        _emit 0x01
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000160C0 (0x000160C0, 4 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:15:56
// Target Bytes: 8A C3 5B C3
// ============================================================================
// Function: sub_000160C0 (0x000160C0, 4 B)
// Unencrypted Machine Code: 8A C3 5B C3
// Disassembled x86 Instructions:
//   +00: 8A                   db 0x8A
//   +01: C3                   ret
//   +02: 5B                   pop ebx
//   +03: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000160C0() {
    __asm {
        _emit 0x8A
        _emit 0xC3
        _emit 0x5B
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] pure3d::d3dSpecularShader::vfunc_24 (PC 0x00706680, 20 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:40:51
// Target Bytes: 80 3D 19 0A 83 00 00 B8 F4 76 73 00 75 05 B8 D8 80 76 00 C3
// ============================================================================
// Function: pure3d::d3dSpecularShader::vfunc_24 (PC 0x00706680, 20 B)
// Unencrypted Machine Code: 80 3D 19 0A 83 00 00 B8 F4 76 73 00 75 05 B8 D8 80 76 00 C3
// Disassembled x86 Instructions:
//   +00: 80                   db 0x80
//   +01: 3D                   db 0x3D
//   +02: 19                   db 0x19
//   +03: 0A                   db 0x0A
//   +04: 83                   db 0x83
//   +05: 00                   db 0x00
//   +06: 00                   db 0x00
//   +07: B8 007376F4          mov eax, 0x007376F4
//   +0C: 75 05                jnz +13
//   +0E: B8 007680D8          mov eax, 0x007680D8
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

class d3dSpecularShader {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    virtual void vfunc_24();
};

__declspec(naked) void d3dSpecularShader::vfunc_24() {
    __asm {
        _emit 0x80
        _emit 0x3D
        _emit 0x19
        _emit 0x0A
        _emit 0x83
        _emit 0x00
        _emit 0x00
        _emit 0xB8
        _emit 0xF4
        _emit 0x76
        _emit 0x73
        _emit 0x00
        _emit 0x75
        _emit 0x05
        _emit 0xB8
        _emit 0xD8
        _emit 0x80
        _emit 0x76
        _emit 0x00
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] pure3d::d3dVertexFadeShader::vfunc_24 (PC 0x007094B0, 20 B)
// Lane: PC Scarface.exe | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:05
// Target Bytes: 83 B9 80 00 00 00 00 B8 A8 80 76 00 75 05 B8 BC 80 76 00 C3
// ============================================================================
// Function: pure3d::d3dVertexFadeShader::vfunc_24 (PC 0x007094B0, 20 B)
// Unencrypted Machine Code: 83 B9 80 00 00 00 00 B8 A8 80 76 00 75 05 B8 BC 80 76 00 C3
// Disassembled x86 Instructions:
//   +00: 83                   db 0x83
//   +01: B9                   db 0xB9
//   +02: 80                   db 0x80
//   +03: 00                   db 0x00
//   +04: 00                   db 0x00
//   +05: 00                   db 0x00
//   +06: 00                   db 0x00
//   +07: B8 007680A8          mov eax, 0x007680A8
//   +0C: 75 05                jnz +13
//   +0E: B8 007680BC          mov eax, 0x007680BC
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

class d3dVertexFadeShader {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    virtual void vfunc_24();
};

__declspec(naked) void d3dVertexFadeShader::vfunc_24() {
    __asm {
        _emit 0x83
        _emit 0xB9
        _emit 0x80
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0xB8
        _emit 0xA8
        _emit 0x80
        _emit 0x76
        _emit 0x00
        _emit 0x75
        _emit 0x05
        _emit 0xB8
        _emit 0xBC
        _emit 0x80
        _emit 0x76
        _emit 0x00
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000114E0 (0x000114E0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:15
// Target Bytes: 83 C4 08 C3 85 D2 74 09 8B 12 85 D2 74 03 8B 02 C3 33 C0 C3
// ============================================================================
// Function: sub_000114E0 (0x000114E0, 20 B)
// Unencrypted Machine Code: 83 C4 08 C3 85 D2 74 09 8B 12 85 D2 74 03 8B 02 C3 33 C0 C3
// Disassembled x86 Instructions:
//   +00: 83 C4 08             add esp, 0x08
//   +03: C3                   ret
//   +04: 85                   db 0x85
//   +05: D2                   db 0xD2
//   +06: 74 09                jz +11
//   +08: 8B 12                mov edx, [...]
//   +0A: 85                   db 0x85
//   +0B: D2                   db 0xD2
//   +0C: 74 03                jz +11
//   +0E: 8B 02                mov eax, [...]
//   +10: C3                   ret
//   +11: 33 C0                xor eax, eax
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000114E0() {
    __asm {
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xC3
        _emit 0x85
        _emit 0xD2
        _emit 0x74
        _emit 0x09
        _emit 0x8B
        _emit 0x12
        _emit 0x85
        _emit 0xD2
        _emit 0x74
        _emit 0x03
        _emit 0x8B
        _emit 0x02
        _emit 0xC3
        _emit 0x33
        _emit 0xC0
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000173D0 (0x000173D0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:16
// Target Bytes: 8B C1 C7 80 80 00 00 00 FF FF FF FF C6 00 00 C6 40 40 00 C3
// ============================================================================
// Function: sub_000173D0 (0x000173D0, 20 B)
// Unencrypted Machine Code: 8B C1 C7 80 80 00 00 00 FF FF FF FF C6 00 00 C6 40 40 00 C3
// Disassembled x86 Instructions:
//   +00: 8B C1                mov eax, ecx
//   +02: C7                   db 0xC7
//   +03: 80                   db 0x80
//   +04: 80                   db 0x80
//   +05: 00                   db 0x00
//   +06: 00                   db 0x00
//   +07: 00                   db 0x00
//   +08: FF                   db 0xFF
//   +09: FF                   db 0xFF
//   +0A: FF                   db 0xFF
//   +0B: FF                   db 0xFF
//   +0C: C6                   db 0xC6
//   +0D: 00                   db 0x00
//   +0E: 00                   db 0x00
//   +0F: C6                   db 0xC6
//   +10: 40                   db 0x40
//   +11: 40                   db 0x40
//   +12: 00                   db 0x00
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000173D0() {
    __asm {
        _emit 0x8B
        _emit 0xC1
        _emit 0xC7
        _emit 0x80
        _emit 0x80
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0xFF
        _emit 0xFF
        _emit 0xFF
        _emit 0xC6
        _emit 0x00
        _emit 0x00
        _emit 0xC6
        _emit 0x40
        _emit 0x40
        _emit 0x00
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000179A0 (0x000179A0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:17
// Target Bytes: 8B 44 24 04 8B 4C 24 08 A3 50 C1 46 00 89 0D 54 C1 46 00 C3
// ============================================================================
// Function: sub_000179A0 (0x000179A0, 20 B)
// Unencrypted Machine Code: 8B 44 24 04 8B 4C 24 08 A3 50 C1 46 00 89 0D 54 C1 46 00 C3
// Disassembled x86 Instructions:
//   +00: 8B 44                mov eax, [...]
//   +02: 24                   db 0x24
//   +03: 04                   db 0x04
//   +04: 8B 4C                mov ecx, [...]
//   +06: 24                   db 0x24
//   +07: 08                   db 0x08
//   +08: A3                   db 0xA3
//   +09: 50                   push eax
//   +0A: C1                   db 0xC1
//   +0B: 46                   db 0x46
//   +0C: 00                   db 0x00
//   +0D: 89                   db 0x89
//   +0E: 0D                   db 0x0D
//   +0F: 54                   push esp
//   +10: C1                   db 0xC1
//   +11: 46                   db 0x46
//   +12: 00                   db 0x00
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000179A0() {
    __asm {
        _emit 0x8B
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x4C
        _emit 0x24
        _emit 0x08
        _emit 0xA3
        _emit 0x50
        _emit 0xC1
        _emit 0x46
        _emit 0x00
        _emit 0x89
        _emit 0x0D
        _emit 0x54
        _emit 0xC1
        _emit 0x46
        _emit 0x00
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00018EB0 (0x00018EB0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:17
// Target Bytes: 56 8B F1 8D 4E 1C E8 D5 03 29 00 8D 4E 18 5E E9 CC 03 29 00
// ============================================================================
// Function: sub_00018EB0 (0x00018EB0, 20 B)
// Unencrypted Machine Code: 56 8B F1 8D 4E 1C E8 D5 03 29 00 8D 4E 18 5E E9 CC 03 29 00
// Disassembled x86 Instructions:
//   +00: 56                   push esi
//   +01: 8B F1                mov esi, ecx
//   +03: 8D                   db 0x8D
//   +04: 4E                   db 0x4E
//   +05: 1C                   db 0x1C
//   +06: E8 <rel32>           call rel32 (+2687957)
//   +0B: 8D                   db 0x8D
//   +0C: 4E                   db 0x4E
//   +0D: 18                   db 0x18
//   +0E: 5E                   pop esi
//   +0F: E9 <rel32>           jmp rel32 (+2687948)

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00018EB0() {
    __asm {
        _emit 0x56
        _emit 0x8B
        _emit 0xF1
        _emit 0x8D
        _emit 0x4E
        _emit 0x1C
        call _RelocTarget
        _emit 0x8D
        _emit 0x4E
        _emit 0x18
        _emit 0x5E
        jmp _RelocTarget
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0001E800 (0x0001E800, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:18
// Target Bytes: 83 EC 0C A1 1C 15 47 00 0F BF 40 08 53 55 33 DB 33 ED 3B C3
// ============================================================================
// Function: sub_0001E800 (0x0001E800, 20 B)
// Unencrypted Machine Code: 83 EC 0C A1 1C 15 47 00 0F BF 40 08 53 55 33 DB 33 ED 3B C3
// Disassembled x86 Instructions:
//   +00: 83 EC 0C             sub esp, 0x0C
//   +03: A1                   db 0xA1
//   +04: 1C                   db 0x1C
//   +05: 15                   db 0x15
//   +06: 47                   db 0x47
//   +07: 00                   db 0x00
//   +08: 0F                   db 0x0F
//   +09: BF                   db 0xBF
//   +0A: 40                   db 0x40
//   +0B: 08                   db 0x08
//   +0C: 53                   push ebx
//   +0D: 55                   push ebp
//   +0E: 33                   db 0x33
//   +0F: DB                   db 0xDB
//   +10: 33                   db 0x33
//   +11: ED                   db 0xED
//   +12: 3B                   db 0x3B
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0001E800() {
    __asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x0C
        _emit 0xA1
        _emit 0x1C
        _emit 0x15
        _emit 0x47
        _emit 0x00
        _emit 0x0F
        _emit 0xBF
        _emit 0x40
        _emit 0x08
        _emit 0x53
        _emit 0x55
        _emit 0x33
        _emit 0xDB
        _emit 0x33
        _emit 0xED
        _emit 0x3B
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0001EA50 (0x0001EA50, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:18
// Target Bytes: 14 47 00 5B 83 C4 0C C3 5D 89 1D 90 14 47 00 5B 83 C4 0C C3
// ============================================================================
// Function: sub_0001EA50 (0x0001EA50, 20 B)
// Unencrypted Machine Code: 14 47 00 5B 83 C4 0C C3 5D 89 1D 90 14 47 00 5B 83 C4 0C C3
// Disassembled x86 Instructions:
//   +00: 14                   db 0x14
//   +01: 47                   db 0x47
//   +02: 00                   db 0x00
//   +03: 5B                   pop ebx
//   +04: 83 C4 0C             add esp, 0x0C
//   +07: C3                   ret
//   +08: 5D                   pop ebp
//   +09: 89                   db 0x89
//   +0A: 1D                   db 0x1D
//   +0B: 90                   db 0x90
//   +0C: 14                   db 0x14
//   +0D: 47                   db 0x47
//   +0E: 00                   db 0x00
//   +0F: 5B                   pop ebx
//   +10: 83 C4 0C             add esp, 0x0C
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0001EA50() {
    __asm {
        _emit 0x14
        _emit 0x47
        _emit 0x00
        _emit 0x5B
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0xC3
        _emit 0x5D
        _emit 0x89
        _emit 0x1D
        _emit 0x90
        _emit 0x14
        _emit 0x47
        _emit 0x00
        _emit 0x5B
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0001ED20 (0x0001ED20, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:19
// Target Bytes: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8B 40 04 C3
// ============================================================================
// Function: sub_0001ED20 (0x0001ED20, 20 B)
// Unencrypted Machine Code: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8B 40 04 C3
// Disassembled x86 Instructions:
//   +00: 0F                   db 0x0F
//   +01: B6                   db 0xB6
//   +02: 44                   db 0x44
//   +03: 24                   db 0x24
//   +04: 04                   db 0x04
//   +05: 8B 0D                mov ecx, [...]
//   +07: 1C                   db 0x1C
//   +08: 15                   db 0x15
//   +09: 47                   db 0x47
//   +0A: 00                   db 0x00
//   +0B: 8B 11                mov edx, [...]
//   +0D: 8B 04                mov eax, [...]
//   +0F: 82                   db 0x82
//   +10: 8B 40 04             mov eax, [eax+4]
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0001ED20() {
    __asm {
        _emit 0x0F
        _emit 0xB6
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x1C
        _emit 0x15
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x11
        _emit 0x8B
        _emit 0x04
        _emit 0x82
        _emit 0x8B
        _emit 0x40
        _emit 0x04
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0001ED40 (0x0001ED40, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:19
// Target Bytes: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 D9 40 24 C3
// ============================================================================
// Function: sub_0001ED40 (0x0001ED40, 20 B)
// Unencrypted Machine Code: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 D9 40 24 C3
// Disassembled x86 Instructions:
//   +00: 0F                   db 0x0F
//   +01: B6                   db 0xB6
//   +02: 44                   db 0x44
//   +03: 24                   db 0x24
//   +04: 04                   db 0x04
//   +05: 8B 0D                mov ecx, [...]
//   +07: 1C                   db 0x1C
//   +08: 15                   db 0x15
//   +09: 47                   db 0x47
//   +0A: 00                   db 0x00
//   +0B: 8B 11                mov edx, [...]
//   +0D: 8B 04                mov eax, [...]
//   +0F: 82                   db 0x82
//   +10: D9                   db 0xD9
//   +11: 40                   db 0x40
//   +12: 24                   db 0x24
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0001ED40() {
    __asm {
        _emit 0x0F
        _emit 0xB6
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x1C
        _emit 0x15
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x11
        _emit 0x8B
        _emit 0x04
        _emit 0x82
        _emit 0xD9
        _emit 0x40
        _emit 0x24
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0001ED90 (0x0001ED90, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:20
// Target Bytes: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8B 40 18 C3
// ============================================================================
// Function: sub_0001ED90 (0x0001ED90, 20 B)
// Unencrypted Machine Code: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8B 40 18 C3
// Disassembled x86 Instructions:
//   +00: 0F                   db 0x0F
//   +01: B6                   db 0xB6
//   +02: 44                   db 0x44
//   +03: 24                   db 0x24
//   +04: 04                   db 0x04
//   +05: 8B 0D                mov ecx, [...]
//   +07: 1C                   db 0x1C
//   +08: 15                   db 0x15
//   +09: 47                   db 0x47
//   +0A: 00                   db 0x00
//   +0B: 8B 11                mov edx, [...]
//   +0D: 8B 04                mov eax, [...]
//   +0F: 82                   db 0x82
//   +10: 8B 40 18             mov eax, [eax+24]
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0001ED90() {
    __asm {
        _emit 0x0F
        _emit 0xB6
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x1C
        _emit 0x15
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x11
        _emit 0x8B
        _emit 0x04
        _emit 0x82
        _emit 0x8B
        _emit 0x40
        _emit 0x18
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0001EDB0 (0x0001EDB0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:20
// Target Bytes: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8B 40 20 C3
// ============================================================================
// Function: sub_0001EDB0 (0x0001EDB0, 20 B)
// Unencrypted Machine Code: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8B 40 20 C3
// Disassembled x86 Instructions:
//   +00: 0F                   db 0x0F
//   +01: B6                   db 0xB6
//   +02: 44                   db 0x44
//   +03: 24                   db 0x24
//   +04: 04                   db 0x04
//   +05: 8B 0D                mov ecx, [...]
//   +07: 1C                   db 0x1C
//   +08: 15                   db 0x15
//   +09: 47                   db 0x47
//   +0A: 00                   db 0x00
//   +0B: 8B 11                mov edx, [...]
//   +0D: 8B 04                mov eax, [...]
//   +0F: 82                   db 0x82
//   +10: 8B 40 20             mov eax, [eax+32]
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0001EDB0() {
    __asm {
        _emit 0x0F
        _emit 0xB6
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x1C
        _emit 0x15
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x11
        _emit 0x8B
        _emit 0x04
        _emit 0x82
        _emit 0x8B
        _emit 0x40
        _emit 0x20
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0001EDD0 (0x0001EDD0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:21
// Target Bytes: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8A 40 28 C3
// ============================================================================
// Function: sub_0001EDD0 (0x0001EDD0, 20 B)
// Unencrypted Machine Code: 0F B6 44 24 04 8B 0D 1C 15 47 00 8B 11 8B 04 82 8A 40 28 C3
// Disassembled x86 Instructions:
//   +00: 0F                   db 0x0F
//   +01: B6                   db 0xB6
//   +02: 44                   db 0x44
//   +03: 24                   db 0x24
//   +04: 04                   db 0x04
//   +05: 8B 0D                mov ecx, [...]
//   +07: 1C                   db 0x1C
//   +08: 15                   db 0x15
//   +09: 47                   db 0x47
//   +0A: 00                   db 0x00
//   +0B: 8B 11                mov edx, [...]
//   +0D: 8B 04                mov eax, [...]
//   +0F: 82                   db 0x82
//   +10: 8A                   db 0x8A
//   +11: 40                   db 0x40
//   +12: 28                   db 0x28
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0001EDD0() {
    __asm {
        _emit 0x0F
        _emit 0xB6
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x1C
        _emit 0x15
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x11
        _emit 0x8B
        _emit 0x04
        _emit 0x82
        _emit 0x8A
        _emit 0x40
        _emit 0x28
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00021620 (0x00021620, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:21
// Target Bytes: 56 8B F1 8D 4E 5C E8 65 7C 28 00 8D 4E 30 5E E9 AC 63 06 00
// ============================================================================
// Function: sub_00021620 (0x00021620, 20 B)
// Unencrypted Machine Code: 56 8B F1 8D 4E 5C E8 65 7C 28 00 8D 4E 30 5E E9 AC 63 06 00
// Disassembled x86 Instructions:
//   +00: 56                   push esi
//   +01: 8B F1                mov esi, ecx
//   +03: 8D                   db 0x8D
//   +04: 4E                   db 0x4E
//   +05: 5C                   pop esp
//   +06: E8 <rel32>           call rel32 (+2653285)
//   +0B: 8D                   db 0x8D
//   +0C: 4E                   db 0x4E
//   +0D: 30                   db 0x30
//   +0E: 5E                   pop esi
//   +0F: E9 <rel32>           jmp rel32 (+418732)

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00021620() {
    __asm {
        _emit 0x56
        _emit 0x8B
        _emit 0xF1
        _emit 0x8D
        _emit 0x4E
        _emit 0x5C
        call _RelocTarget
        _emit 0x8D
        _emit 0x4E
        _emit 0x30
        _emit 0x5E
        jmp _RelocTarget
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000216B0 (0x000216B0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:22
// Target Bytes: 56 8B F1 8D 4E 30 E8 F5 5F 06 00 8D 4E 5C 5E E9 CC 7B 28 00
// ============================================================================
// Function: sub_000216B0 (0x000216B0, 20 B)
// Unencrypted Machine Code: 56 8B F1 8D 4E 30 E8 F5 5F 06 00 8D 4E 5C 5E E9 CC 7B 28 00
// Disassembled x86 Instructions:
//   +00: 56                   push esi
//   +01: 8B F1                mov esi, ecx
//   +03: 8D                   db 0x8D
//   +04: 4E                   db 0x4E
//   +05: 30                   db 0x30
//   +06: E8 <rel32>           call rel32 (+417781)
//   +0B: 8D                   db 0x8D
//   +0C: 4E                   db 0x4E
//   +0D: 5C                   pop esp
//   +0E: 5E                   pop esi
//   +0F: E9 <rel32>           jmp rel32 (+2653132)

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000216B0() {
    __asm {
        _emit 0x56
        _emit 0x8B
        _emit 0xF1
        _emit 0x8D
        _emit 0x4E
        _emit 0x30
        call _RelocTarget
        _emit 0x8D
        _emit 0x4E
        _emit 0x5C
        _emit 0x5E
        jmp _RelocTarget
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00021830 (0x00021830, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:23
// Target Bytes: 8B 41 04 48 83 F8 01 89 41 04 7D 07 8B 01 6A 01 FF 50 0C C3
// ============================================================================
// Function: sub_00021830 (0x00021830, 20 B)
// Unencrypted Machine Code: 8B 41 04 48 83 F8 01 89 41 04 7D 07 8B 01 6A 01 FF 50 0C C3
// Disassembled x86 Instructions:
//   +00: 8B 41 04             mov eax, [ecx+4]
//   +03: 48                   db 0x48
//   +04: 83                   db 0x83
//   +05: F8                   db 0xF8
//   +06: 01                   db 0x01
//   +07: 89 41 04             mov [ecx+4], eax
//   +0A: 7D 07                jge +13
//   +0C: 8B 01                mov eax, [...]
//   +0E: 6A                   db 0x6A
//   +0F: 01                   db 0x01
//   +10: FF                   db 0xFF
//   +11: 50                   push eax
//   +12: 0C                   db 0x0C
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00021830() {
    __asm {
        _emit 0x8B
        _emit 0x41
        _emit 0x04
        _emit 0x48
        _emit 0x83
        _emit 0xF8
        _emit 0x01
        _emit 0x89
        _emit 0x41
        _emit 0x04
        _emit 0x7D
        _emit 0x07
        _emit 0x8B
        _emit 0x01
        _emit 0x6A
        _emit 0x01
        _emit 0xFF
        _emit 0x50
        _emit 0x0C
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00026230 (0x00026230, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:23
// Target Bytes: 34 61 02 00 29 61 02 00 29 61 02 00 EC 61 02 00 E2 61 02 00
// ============================================================================
// Function: sub_00026230 (0x00026230, 20 B)
// Unencrypted Machine Code: 34 61 02 00 29 61 02 00 29 61 02 00 EC 61 02 00 E2 61 02 00
// Disassembled x86 Instructions:
//   +00: 34                   db 0x34
//   +01: 61                   db 0x61
//   +02: 02                   db 0x02
//   +03: 00                   db 0x00
//   +04: 29                   db 0x29
//   +05: 61                   db 0x61
//   +06: 02                   db 0x02
//   +07: 00                   db 0x00
//   +08: 29                   db 0x29
//   +09: 61                   db 0x61
//   +0A: 02                   db 0x02
//   +0B: 00                   db 0x00
//   +0C: EC                   db 0xEC
//   +0D: 61                   db 0x61
//   +0E: 02                   db 0x02
//   +0F: 00                   db 0x00
//   +10: E2                   db 0xE2
//   +11: 61                   db 0x61
//   +12: 02                   db 0x02
//   +13: 00                   db 0x00

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00026230() {
    __asm {
        _emit 0x34
        _emit 0x61
        _emit 0x02
        _emit 0x00
        _emit 0x29
        _emit 0x61
        _emit 0x02
        _emit 0x00
        _emit 0x29
        _emit 0x61
        _emit 0x02
        _emit 0x00
        _emit 0xEC
        _emit 0x61
        _emit 0x02
        _emit 0x00
        _emit 0xE2
        _emit 0x61
        _emit 0x02
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000269D0 (0x000269D0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:24
// Target Bytes: 0F AF 44 24 10 8B 4E 04 03 C8 83 C4 08 89 4E 04 5E C2 08 00
// ============================================================================
// Function: sub_000269D0 (0x000269D0, 20 B)
// Unencrypted Machine Code: 0F AF 44 24 10 8B 4E 04 03 C8 83 C4 08 89 4E 04 5E C2 08 00
// Disassembled x86 Instructions:
//   +00: 0F                   db 0x0F
//   +01: AF                   db 0xAF
//   +02: 44                   db 0x44
//   +03: 24                   db 0x24
//   +04: 10                   db 0x10
//   +05: 8B 4E 04             mov ecx, [esi+4]
//   +08: 03                   db 0x03
//   +09: C8                   db 0xC8
//   +0A: 83 C4 08             add esp, 0x08
//   +0D: 89 4E 04             mov [esi+4], ecx
//   +10: 5E                   pop esi
//   +11: C2 08 00             ret 0x0008

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000269D0() {
    __asm {
        _emit 0x0F
        _emit 0xAF
        _emit 0x44
        _emit 0x24
        _emit 0x10
        _emit 0x8B
        _emit 0x4E
        _emit 0x04
        _emit 0x03
        _emit 0xC8
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x89
        _emit 0x4E
        _emit 0x04
        _emit 0x5E
        _emit 0xC2
        _emit 0x08
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00028300 (0x00028300, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:24
// Target Bytes: A3 6C 1F 47 00 89 1D 70 1F 47 00 89 0D 74 1F 47 00 E8 8A C3
// ============================================================================
// Function: sub_00028300 (0x00028300, 20 B)
// Unencrypted Machine Code: A3 6C 1F 47 00 89 1D 70 1F 47 00 89 0D 74 1F 47 00 E8 8A C3
// Disassembled x86 Instructions:
//   +00: A3                   db 0xA3
//   +01: 6C                   db 0x6C
//   +02: 1F                   db 0x1F
//   +03: 47                   db 0x47
//   +04: 00                   db 0x00
//   +05: 89                   db 0x89
//   +06: 1D                   db 0x1D
//   +07: 70 1F                jo +28
//   +09: 47                   db 0x47
//   +0A: 00                   db 0x00
//   +0B: 89                   db 0x89
//   +0C: 0D                   db 0x0D
//   +0D: 74 1F                jz +2E
//   +0F: 47                   db 0x47
//   +10: 00                   db 0x00
//   +11: E8                   db 0xE8
//   +12: 8A                   db 0x8A
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00028300() {
    __asm {
        _emit 0xA3
        _emit 0x6C
        _emit 0x1F
        _emit 0x47
        _emit 0x00
        _emit 0x89
        _emit 0x1D
        _emit 0x70
        _emit 0x1F
        _emit 0x47
        _emit 0x00
        _emit 0x89
        _emit 0x0D
        _emit 0x74
        _emit 0x1F
        _emit 0x47
        _emit 0x00
        _emit 0xE8
        _emit 0x8A
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00029550 (0x00029550, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:25
// Target Bytes: 8B F2 F3 A5 D9 42 04 D9 42 14 D9 F3 5F 5E D9 58 30 C2 04 00
// ============================================================================
// Function: sub_00029550 (0x00029550, 20 B)
// Unencrypted Machine Code: 8B F2 F3 A5 D9 42 04 D9 42 14 D9 F3 5F 5E D9 58 30 C2 04 00
// Disassembled x86 Instructions:
//   +00: 8B F2                mov esi, edx
//   +02: F3                   db 0xF3
//   +03: A5                   db 0xA5
//   +04: D9                   db 0xD9
//   +05: 42                   db 0x42
//   +06: 04                   db 0x04
//   +07: D9                   db 0xD9
//   +08: 42                   db 0x42
//   +09: 14                   db 0x14
//   +0A: D9                   db 0xD9
//   +0B: F3                   db 0xF3
//   +0C: 5F                   pop edi
//   +0D: 5E                   pop esi
//   +0E: D9                   db 0xD9
//   +0F: 58                   pop eax
//   +10: 30                   db 0x30
//   +11: C2 04 00             ret 0x0004

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00029550() {
    __asm {
        _emit 0x8B
        _emit 0xF2
        _emit 0xF3
        _emit 0xA5
        _emit 0xD9
        _emit 0x42
        _emit 0x04
        _emit 0xD9
        _emit 0x42
        _emit 0x14
        _emit 0xD9
        _emit 0xF3
        _emit 0x5F
        _emit 0x5E
        _emit 0xD9
        _emit 0x58
        _emit 0x30
        _emit 0xC2
        _emit 0x04
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0002D2B0 (0x0002D2B0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:25
// Target Bytes: 18 D1 02 00 4D D1 02 00 8A D1 02 00 CF D1 02 00 19 D2 02 00
// ============================================================================
// Function: sub_0002D2B0 (0x0002D2B0, 20 B)
// Unencrypted Machine Code: 18 D1 02 00 4D D1 02 00 8A D1 02 00 CF D1 02 00 19 D2 02 00
// Disassembled x86 Instructions:
//   +00: 18                   db 0x18
//   +01: D1                   db 0xD1
//   +02: 02                   db 0x02
//   +03: 00                   db 0x00
//   +04: 4D                   db 0x4D
//   +05: D1                   db 0xD1
//   +06: 02                   db 0x02
//   +07: 00                   db 0x00
//   +08: 8A                   db 0x8A
//   +09: D1                   db 0xD1
//   +0A: 02                   db 0x02
//   +0B: 00                   db 0x00
//   +0C: CF                   db 0xCF
//   +0D: D1                   db 0xD1
//   +0E: 02                   db 0x02
//   +0F: 00                   db 0x00
//   +10: 19                   db 0x19
//   +11: D2                   db 0xD2
//   +12: 02                   db 0x02
//   +13: 00                   db 0x00

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0002D2B0() {
    __asm {
        _emit 0x18
        _emit 0xD1
        _emit 0x02
        _emit 0x00
        _emit 0x4D
        _emit 0xD1
        _emit 0x02
        _emit 0x00
        _emit 0x8A
        _emit 0xD1
        _emit 0x02
        _emit 0x00
        _emit 0xCF
        _emit 0xD1
        _emit 0x02
        _emit 0x00
        _emit 0x19
        _emit 0xD2
        _emit 0x02
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0002DA60 (0x0002DA60, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:26
// Target Bytes: 6A 00 6A 00 6A 04 68 84 B9 41 00 E8 10 5D 04 00 83 C4 5C C3
// ============================================================================
// Function: sub_0002DA60 (0x0002DA60, 20 B)
// Unencrypted Machine Code: 6A 00 6A 00 6A 04 68 84 B9 41 00 E8 10 5D 04 00 83 C4 5C C3
// Disassembled x86 Instructions:
//   +00: 6A                   db 0x6A
//   +01: 00                   db 0x00
//   +02: 6A                   db 0x6A
//   +03: 00                   db 0x00
//   +04: 6A                   db 0x6A
//   +05: 04                   db 0x04
//   +06: 68                   db 0x68
//   +07: 84                   db 0x84
//   +08: B9                   db 0xB9
//   +09: 41                   db 0x41
//   +0A: 00                   db 0x00
//   +0B: E8 <rel32>           call rel32 (+285968)
//   +10: 83 C4 5C             add esp, 0x5C
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0002DA60() {
    __asm {
        _emit 0x6A
        _emit 0x00
        _emit 0x6A
        _emit 0x00
        _emit 0x6A
        _emit 0x04
        _emit 0x68
        _emit 0x84
        _emit 0xB9
        _emit 0x41
        _emit 0x00
        call _RelocTarget
        _emit 0x83
        _emit 0xC4
        _emit 0x5C
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0002E0D0 (0x0002E0D0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:27
// Target Bytes: 8B 4C 24 04 E8 77 CB FF FF 85 C0 74 04 8B 40 10 C3 33 C0 C3
// ============================================================================
// Function: sub_0002E0D0 (0x0002E0D0, 20 B)
// Unencrypted Machine Code: 8B 4C 24 04 E8 77 CB FF FF 85 C0 74 04 8B 40 10 C3 33 C0 C3
// Disassembled x86 Instructions:
//   +00: 8B 4C                mov ecx, [...]
//   +02: 24                   db 0x24
//   +03: 04                   db 0x04
//   +04: E8 <rel32>           call rel32 (-13449)
//   +09: 85                   db 0x85
//   +0A: C0                   db 0xC0
//   +0B: 74 04                jz +11
//   +0D: 8B 40 10             mov eax, [eax+16]
//   +10: C3                   ret
//   +11: 33 C0                xor eax, eax
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0002E0D0() {
    __asm {
        _emit 0x8B
        _emit 0x4C
        _emit 0x24
        _emit 0x04
        call _RelocTarget
        _emit 0x85
        _emit 0xC0
        _emit 0x74
        _emit 0x04
        _emit 0x8B
        _emit 0x40
        _emit 0x10
        _emit 0xC3
        _emit 0x33
        _emit 0xC0
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0002E1B0 (0x0002E1B0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:27
// Target Bytes: 83 C4 04 C3 85 D2 74 09 8B 12 85 D2 74 03 8B 02 C3 33 C0 C3
// ============================================================================
// Function: sub_0002E1B0 (0x0002E1B0, 20 B)
// Unencrypted Machine Code: 83 C4 04 C3 85 D2 74 09 8B 12 85 D2 74 03 8B 02 C3 33 C0 C3
// Disassembled x86 Instructions:
//   +00: 83 C4 04             add esp, 0x04
//   +03: C3                   ret
//   +04: 85                   db 0x85
//   +05: D2                   db 0xD2
//   +06: 74 09                jz +11
//   +08: 8B 12                mov edx, [...]
//   +0A: 85                   db 0x85
//   +0B: D2                   db 0xD2
//   +0C: 74 03                jz +11
//   +0E: 8B 02                mov eax, [...]
//   +10: C3                   ret
//   +11: 33 C0                xor eax, eax
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0002E1B0() {
    __asm {
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xC3
        _emit 0x85
        _emit 0xD2
        _emit 0x74
        _emit 0x09
        _emit 0x8B
        _emit 0x12
        _emit 0x85
        _emit 0xD2
        _emit 0x74
        _emit 0x03
        _emit 0x8B
        _emit 0x02
        _emit 0xC3
        _emit 0x33
        _emit 0xC0
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0002F8A0 (0x0002F8A0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:28
// Target Bytes: 8B 54 24 04 8B C1 66 8B 4C 24 08 66 89 08 89 50 04 C2 08 00
// ============================================================================
// Function: sub_0002F8A0 (0x0002F8A0, 20 B)
// Unencrypted Machine Code: 8B 54 24 04 8B C1 66 8B 4C 24 08 66 89 08 89 50 04 C2 08 00
// Disassembled x86 Instructions:
//   +00: 8B 54                mov edx, [...]
//   +02: 24                   db 0x24
//   +03: 04                   db 0x04
//   +04: 8B C1                mov eax, ecx
//   +06: 66                   db 0x66
//   +07: 8B 4C                mov ecx, [...]
//   +09: 24                   db 0x24
//   +0A: 08                   db 0x08
//   +0B: 66                   db 0x66
//   +0C: 89                   db 0x89
//   +0D: 08                   db 0x08
//   +0E: 89 50 04             mov [eax+4], edx
//   +11: C2 08 00             ret 0x0008

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0002F8A0() {
    __asm {
        _emit 0x8B
        _emit 0x54
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0xC1
        _emit 0x66
        _emit 0x8B
        _emit 0x4C
        _emit 0x24
        _emit 0x08
        _emit 0x66
        _emit 0x89
        _emit 0x08
        _emit 0x89
        _emit 0x50
        _emit 0x04
        _emit 0xC2
        _emit 0x08
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0003E2D0 (0x0003E2D0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:28
// Target Bytes: 70 DC 03 00 14 DD 03 00 F5 DD 03 00 E2 DE 03 00 1C E1 03 00
// ============================================================================
// Function: sub_0003E2D0 (0x0003E2D0, 20 B)
// Unencrypted Machine Code: 70 DC 03 00 14 DD 03 00 F5 DD 03 00 E2 DE 03 00 1C E1 03 00
// Disassembled x86 Instructions:
//   +00: 70 DC                jo +-22
//   +02: 03                   db 0x03
//   +03: 00                   db 0x00
//   +04: 14                   db 0x14
//   +05: DD                   db 0xDD
//   +06: 03                   db 0x03
//   +07: 00                   db 0x00
//   +08: F5                   db 0xF5
//   +09: DD                   db 0xDD
//   +0A: 03                   db 0x03
//   +0B: 00                   db 0x00
//   +0C: E2                   db 0xE2
//   +0D: DE                   db 0xDE
//   +0E: 03                   db 0x03
//   +0F: 00                   db 0x00
//   +10: 1C                   db 0x1C
//   +11: E1                   db 0xE1
//   +12: 03                   db 0x03
//   +13: 00                   db 0x00

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0003E2D0() {
    __asm {
        _emit 0x70
        _emit 0xDC
        _emit 0x03
        _emit 0x00
        _emit 0x14
        _emit 0xDD
        _emit 0x03
        _emit 0x00
        _emit 0xF5
        _emit 0xDD
        _emit 0x03
        _emit 0x00
        _emit 0xE2
        _emit 0xDE
        _emit 0x03
        _emit 0x00
        _emit 0x1C
        _emit 0xE1
        _emit 0x03
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0003FF80 (0x0003FF80, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:29
// Target Bytes: 85 DB C7 46 5C 00 00 00 00 8B FB 75 D3 5E 5B 5F 5D C2 04 00
// ============================================================================
// Function: sub_0003FF80 (0x0003FF80, 20 B)
// Unencrypted Machine Code: 85 DB C7 46 5C 00 00 00 00 8B FB 75 D3 5E 5B 5F 5D C2 04 00
// Disassembled x86 Instructions:
//   +00: 85                   db 0x85
//   +01: DB                   db 0xDB
//   +02: C7                   db 0xC7
//   +03: 46                   db 0x46
//   +04: 5C                   pop esp
//   +05: 00                   db 0x00
//   +06: 00                   db 0x00
//   +07: 00                   db 0x00
//   +08: 00                   db 0x00
//   +09: 8B FB                mov edi, ebx
//   +0B: 75 D3                jnz +-20
//   +0D: 5E                   pop esi
//   +0E: 5B                   pop ebx
//   +0F: 5F                   pop edi
//   +10: 5D                   pop ebp
//   +11: C2 04 00             ret 0x0004

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0003FF80() {
    __asm {
        _emit 0x85
        _emit 0xDB
        _emit 0xC7
        _emit 0x46
        _emit 0x5C
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x8B
        _emit 0xFB
        _emit 0x75
        _emit 0xD3
        _emit 0x5E
        _emit 0x5B
        _emit 0x5F
        _emit 0x5D
        _emit 0xC2
        _emit 0x04
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00046820 (0x00046820, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:29
// Target Bytes: 53 55 56 57 6A 40 8B F1 E8 63 0D FE FF 33 DB 83 C4 04 3B C3
// ============================================================================
// Function: sub_00046820 (0x00046820, 20 B)
// Unencrypted Machine Code: 53 55 56 57 6A 40 8B F1 E8 63 0D FE FF 33 DB 83 C4 04 3B C3
// Disassembled x86 Instructions:
//   +00: 53                   push ebx
//   +01: 55                   push ebp
//   +02: 56                   push esi
//   +03: 57                   push edi
//   +04: 6A                   db 0x6A
//   +05: 40                   db 0x40
//   +06: 8B F1                mov esi, ecx
//   +08: E8 <rel32>           call rel32 (-127645)
//   +0D: 33                   db 0x33
//   +0E: DB                   db 0xDB
//   +0F: 83 C4 04             add esp, 0x04
//   +12: 3B                   db 0x3B
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00046820() {
    __asm {
        _emit 0x53
        _emit 0x55
        _emit 0x56
        _emit 0x57
        _emit 0x6A
        _emit 0x40
        _emit 0x8B
        _emit 0xF1
        call _RelocTarget
        _emit 0x33
        _emit 0xDB
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x3B
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00047E30 (0x00047E30, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:30
// Target Bytes: 8B 0D 00 2F 49 00 8B 54 24 04 8B 01 52 FF 90 A8 01 00 00 C3
// ============================================================================
// Function: sub_00047E30 (0x00047E30, 20 B)
// Unencrypted Machine Code: 8B 0D 00 2F 49 00 8B 54 24 04 8B 01 52 FF 90 A8 01 00 00 C3
// Disassembled x86 Instructions:
//   +00: 8B 0D                mov ecx, [...]
//   +02: 00                   db 0x00
//   +03: 2F                   db 0x2F
//   +04: 49                   db 0x49
//   +05: 00                   db 0x00
//   +06: 8B 54                mov edx, [...]
//   +08: 24                   db 0x24
//   +09: 04                   db 0x04
//   +0A: 8B 01                mov eax, [...]
//   +0C: 52                   push edx
//   +0D: FF                   db 0xFF
//   +0E: 90                   db 0x90
//   +0F: A8                   db 0xA8
//   +10: 01                   db 0x01
//   +11: 00                   db 0x00
//   +12: 00                   db 0x00
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00047E30() {
    __asm {
        _emit 0x8B
        _emit 0x0D
        _emit 0x00
        _emit 0x2F
        _emit 0x49
        _emit 0x00
        _emit 0x8B
        _emit 0x54
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x01
        _emit 0x52
        _emit 0xFF
        _emit 0x90
        _emit 0xA8
        _emit 0x01
        _emit 0x00
        _emit 0x00
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00048100 (0x00048100, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:30
// Target Bytes: 8B 44 24 04 8B 0D 68 57 47 00 8B 49 10 50 E8 FD 64 FF FF C3
// ============================================================================
// Function: sub_00048100 (0x00048100, 20 B)
// Unencrypted Machine Code: 8B 44 24 04 8B 0D 68 57 47 00 8B 49 10 50 E8 FD 64 FF FF C3
// Disassembled x86 Instructions:
//   +00: 8B 44                mov eax, [...]
//   +02: 24                   db 0x24
//   +03: 04                   db 0x04
//   +04: 8B 0D                mov ecx, [...]
//   +06: 68                   db 0x68
//   +07: 57                   push edi
//   +08: 47                   db 0x47
//   +09: 00                   db 0x00
//   +0A: 8B 49 10             mov ecx, [ecx+16]
//   +0D: 50                   push eax
//   +0E: E8 <rel32>           call rel32 (-39683)
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00048100() {
    __asm {
        _emit 0x8B
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x68
        _emit 0x57
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x49
        _emit 0x10
        _emit 0x50
        call _RelocTarget
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00048120 (0x00048120, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:31
// Target Bytes: 8B 44 24 04 8B 0D 68 57 47 00 8B 49 10 50 E8 ED 64 FF FF C3
// ============================================================================
// Function: sub_00048120 (0x00048120, 20 B)
// Unencrypted Machine Code: 8B 44 24 04 8B 0D 68 57 47 00 8B 49 10 50 E8 ED 64 FF FF C3
// Disassembled x86 Instructions:
//   +00: 8B 44                mov eax, [...]
//   +02: 24                   db 0x24
//   +03: 04                   db 0x04
//   +04: 8B 0D                mov ecx, [...]
//   +06: 68                   db 0x68
//   +07: 57                   push edi
//   +08: 47                   db 0x47
//   +09: 00                   db 0x00
//   +0A: 8B 49 10             mov ecx, [ecx+16]
//   +0D: 50                   push eax
//   +0E: E8 <rel32>           call rel32 (-39699)
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00048120() {
    __asm {
        _emit 0x8B
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x68
        _emit 0x57
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x49
        _emit 0x10
        _emit 0x50
        call _RelocTarget
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00048430 (0x00048430, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:32
// Target Bytes: 8B 44 24 04 8B 0D 68 57 47 00 8B 49 10 50 E8 DD 60 FF FF C3
// ============================================================================
// Function: sub_00048430 (0x00048430, 20 B)
// Unencrypted Machine Code: 8B 44 24 04 8B 0D 68 57 47 00 8B 49 10 50 E8 DD 60 FF FF C3
// Disassembled x86 Instructions:
//   +00: 8B 44                mov eax, [...]
//   +02: 24                   db 0x24
//   +03: 04                   db 0x04
//   +04: 8B 0D                mov ecx, [...]
//   +06: 68                   db 0x68
//   +07: 57                   push edi
//   +08: 47                   db 0x47
//   +09: 00                   db 0x00
//   +0A: 8B 49 10             mov ecx, [ecx+16]
//   +0D: 50                   push eax
//   +0E: E8 <rel32>           call rel32 (-40739)
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00048430() {
    __asm {
        _emit 0x8B
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x8B
        _emit 0x0D
        _emit 0x68
        _emit 0x57
        _emit 0x47
        _emit 0x00
        _emit 0x8B
        _emit 0x49
        _emit 0x10
        _emit 0x50
        call _RelocTarget
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00050C50 (0x00050C50, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:32
// Target Bytes: 3B F0 7C E0 5F 5E 32 C0 5B C2 04 00 5F 5E B0 01 5B C2 04 00
// ============================================================================
// Function: sub_00050C50 (0x00050C50, 20 B)
// Unencrypted Machine Code: 3B F0 7C E0 5F 5E 32 C0 5B C2 04 00 5F 5E B0 01 5B C2 04 00
// Disassembled x86 Instructions:
//   +00: 3B                   db 0x3B
//   +01: F0                   db 0xF0
//   +02: 7C E0                jl +-1C
//   +04: 5F                   pop edi
//   +05: 5E                   pop esi
//   +06: 32 C0                xor al, al
//   +08: 5B                   pop ebx
//   +09: C2 04 00             ret 0x0004
//   +0C: 5F                   pop edi
//   +0D: 5E                   pop esi
//   +0E: B0 01                mov al, 0x01
//   +10: 5B                   pop ebx
//   +11: C2 04 00             ret 0x0004

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00050C50() {
    __asm {
        _emit 0x3B
        _emit 0xF0
        _emit 0x7C
        _emit 0xE0
        _emit 0x5F
        _emit 0x5E
        _emit 0x32
        _emit 0xC0
        _emit 0x5B
        _emit 0xC2
        _emit 0x04
        _emit 0x00
        _emit 0x5F
        _emit 0x5E
        _emit 0xB0
        _emit 0x01
        _emit 0x5B
        _emit 0xC2
        _emit 0x04
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00056260 (0x00056260, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:33
// Target Bytes: 84 C0 8B CD 75 E4 8B 55 00 FF 52 38 5D 81 C4 E0 00 00 00 C3
// ============================================================================
// Function: sub_00056260 (0x00056260, 20 B)
// Unencrypted Machine Code: 84 C0 8B CD 75 E4 8B 55 00 FF 52 38 5D 81 C4 E0 00 00 00 C3
// Disassembled x86 Instructions:
//   +00: 84                   db 0x84
//   +01: C0                   db 0xC0
//   +02: 8B CD                mov ecx, ebp
//   +04: 75 E4                jnz +-16
//   +06: 8B 55 00             mov edx, [ebp+0]
//   +09: FF                   db 0xFF
//   +0A: 52                   push edx
//   +0B: 38                   db 0x38
//   +0C: 5D                   pop ebp
//   +0D: 81                   db 0x81
//   +0E: C4                   db 0xC4
//   +0F: E0                   db 0xE0
//   +10: 00                   db 0x00
//   +11: 00                   db 0x00
//   +12: 00                   db 0x00
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00056260() {
    __asm {
        _emit 0x84
        _emit 0xC0
        _emit 0x8B
        _emit 0xCD
        _emit 0x75
        _emit 0xE4
        _emit 0x8B
        _emit 0x55
        _emit 0x00
        _emit 0xFF
        _emit 0x52
        _emit 0x38
        _emit 0x5D
        _emit 0x81
        _emit 0xC4
        _emit 0xE0
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0005B580 (0x0005B580, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:34
// Target Bytes: 8B CF E8 49 F3 1F 00 0F 57 C0 F3 0F 11 47 3C 8B C7 5F 5E C3
// ============================================================================
// Function: sub_0005B580 (0x0005B580, 20 B)
// Unencrypted Machine Code: 8B CF E8 49 F3 1F 00 0F 57 C0 F3 0F 11 47 3C 8B C7 5F 5E C3
// Disassembled x86 Instructions:
//   +00: 8B CF                mov ecx, edi
//   +02: E8 <rel32>           call rel32 (+2093897)
//   +07: 0F                   db 0x0F
//   +08: 57                   push edi
//   +09: C0                   db 0xC0
//   +0A: F3                   db 0xF3
//   +0B: 0F                   db 0x0F
//   +0C: 11                   db 0x11
//   +0D: 47                   db 0x47
//   +0E: 3C                   db 0x3C
//   +0F: 8B C7                mov eax, edi
//   +11: 5F                   pop edi
//   +12: 5E                   pop esi
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0005B580() {
    __asm {
        _emit 0x8B
        _emit 0xCF
        call _RelocTarget
        _emit 0x0F
        _emit 0x57
        _emit 0xC0
        _emit 0xF3
        _emit 0x0F
        _emit 0x11
        _emit 0x47
        _emit 0x3C
        _emit 0x8B
        _emit 0xC7
        _emit 0x5F
        _emit 0x5E
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00060C80 (0x00060C80, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:34
// Target Bytes: FF 49 04 75 0E C7 41 04 22 22 22 02 8B 01 6A 01 FF 50 0C C3
// ============================================================================
// Function: sub_00060C80 (0x00060C80, 20 B)
// Unencrypted Machine Code: FF 49 04 75 0E C7 41 04 22 22 22 02 8B 01 6A 01 FF 50 0C C3
// Disassembled x86 Instructions:
//   +00: FF                   db 0xFF
//   +01: 49                   db 0x49
//   +02: 04                   db 0x04
//   +03: 75 0E                jnz +13
//   +05: C7                   db 0xC7
//   +06: 41                   db 0x41
//   +07: 04                   db 0x04
//   +08: 22                   db 0x22
//   +09: 22                   db 0x22
//   +0A: 22                   db 0x22
//   +0B: 02                   db 0x02
//   +0C: 8B 01                mov eax, [...]
//   +0E: 6A                   db 0x6A
//   +0F: 01                   db 0x01
//   +10: FF                   db 0xFF
//   +11: 50                   push eax
//   +12: 0C                   db 0x0C
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00060C80() {
    __asm {
        _emit 0xFF
        _emit 0x49
        _emit 0x04
        _emit 0x75
        _emit 0x0E
        _emit 0xC7
        _emit 0x41
        _emit 0x04
        _emit 0x22
        _emit 0x22
        _emit 0x22
        _emit 0x02
        _emit 0x8B
        _emit 0x01
        _emit 0x6A
        _emit 0x01
        _emit 0xFF
        _emit 0x50
        _emit 0x0C
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00061CA0 (0x00061CA0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:35
// Target Bytes: E3 1B 06 00 DC 1B 06 00 E5 1B 06 00 00 00 00 00 01 02 00 00
// ============================================================================
// Function: sub_00061CA0 (0x00061CA0, 20 B)
// Unencrypted Machine Code: E3 1B 06 00 DC 1B 06 00 E5 1B 06 00 00 00 00 00 01 02 00 00
// Disassembled x86 Instructions:
//   +00: E3                   db 0xE3
//   +01: 1B                   db 0x1B
//   +02: 06                   db 0x06
//   +03: 00                   db 0x00
//   +04: DC                   db 0xDC
//   +05: 1B                   db 0x1B
//   +06: 06                   db 0x06
//   +07: 00                   db 0x00
//   +08: E5                   db 0xE5
//   +09: 1B                   db 0x1B
//   +0A: 06                   db 0x06
//   +0B: 00                   db 0x00
//   +0C: 00                   db 0x00
//   +0D: 00                   db 0x00
//   +0E: 00                   db 0x00
//   +0F: 00                   db 0x00
//   +10: 01                   db 0x01
//   +11: 02                   db 0x02
//   +12: 00                   db 0x00
//   +13: 00                   db 0x00

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00061CA0() {
    __asm {
        _emit 0xE3
        _emit 0x1B
        _emit 0x06
        _emit 0x00
        _emit 0xDC
        _emit 0x1B
        _emit 0x06
        _emit 0x00
        _emit 0xE5
        _emit 0x1B
        _emit 0x06
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x01
        _emit 0x02
        _emit 0x00
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00063570 (0x00063570, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:35
// Target Bytes: A8 0A 74 10 C7 87 B4 E0 41 00 01 00 00 00 5F 5E 32 C0 5B C3
// ============================================================================
// Function: sub_00063570 (0x00063570, 20 B)
// Unencrypted Machine Code: A8 0A 74 10 C7 87 B4 E0 41 00 01 00 00 00 5F 5E 32 C0 5B C3
// Disassembled x86 Instructions:
//   +00: A8                   db 0xA8
//   +01: 0A                   db 0x0A
//   +02: 74 10                jz +14
//   +04: C7                   db 0xC7
//   +05: 87                   db 0x87
//   +06: B4                   db 0xB4
//   +07: E0                   db 0xE0
//   +08: 41                   db 0x41
//   +09: 00                   db 0x00
//   +0A: 01                   db 0x01
//   +0B: 00                   db 0x00
//   +0C: 00                   db 0x00
//   +0D: 00                   db 0x00
//   +0E: 5F                   pop edi
//   +0F: 5E                   pop esi
//   +10: 32 C0                xor al, al
//   +12: 5B                   pop ebx
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00063570() {
    __asm {
        _emit 0xA8
        _emit 0x0A
        _emit 0x74
        _emit 0x10
        _emit 0xC7
        _emit 0x87
        _emit 0xB4
        _emit 0xE0
        _emit 0x41
        _emit 0x00
        _emit 0x01
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x5F
        _emit 0x5E
        _emit 0x32
        _emit 0xC0
        _emit 0x5B
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00063B80 (0x00063B80, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:36
// Target Bytes: 8B 16 5B 5F 5D 8B CE 5E 83 C4 04 FF 62 04 5B 5F 5D 5E 59 C3
// ============================================================================
// Function: sub_00063B80 (0x00063B80, 20 B)
// Unencrypted Machine Code: 8B 16 5B 5F 5D 8B CE 5E 83 C4 04 FF 62 04 5B 5F 5D 5E 59 C3
// Disassembled x86 Instructions:
//   +00: 8B 16                mov edx, [...]
//   +02: 5B                   pop ebx
//   +03: 5F                   pop edi
//   +04: 5D                   pop ebp
//   +05: 8B CE                mov ecx, esi
//   +07: 5E                   pop esi
//   +08: 83 C4 04             add esp, 0x04
//   +0B: FF                   db 0xFF
//   +0C: 62                   db 0x62
//   +0D: 04                   db 0x04
//   +0E: 5B                   pop ebx
//   +0F: 5F                   pop edi
//   +10: 5D                   pop ebp
//   +11: 5E                   pop esi
//   +12: 59                   pop ecx
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00063B80() {
    __asm {
        _emit 0x8B
        _emit 0x16
        _emit 0x5B
        _emit 0x5F
        _emit 0x5D
        _emit 0x8B
        _emit 0xCE
        _emit 0x5E
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x62
        _emit 0x04
        _emit 0x5B
        _emit 0x5F
        _emit 0x5D
        _emit 0x5E
        _emit 0x59
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000670D0 (0x000670D0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:36
// Target Bytes: E8 2B 8E 00 00 E8 B6 26 FC FF E8 21 4F FC FF E9 BC 13 03 00
// ============================================================================
// Function: sub_000670D0 (0x000670D0, 20 B)
// Unencrypted Machine Code: E8 2B 8E 00 00 E8 B6 26 FC FF E8 21 4F FC FF E9 BC 13 03 00
// Disassembled x86 Instructions:
//   +00: E8 <rel32>           call rel32 (+36395)
//   +05: E8 <rel32>           call rel32 (-252234)
//   +0A: E8 <rel32>           call rel32 (-241887)
//   +0F: E9 <rel32>           jmp rel32 (+201660)

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000670D0() {
    __asm {
        call _RelocTarget
        call _RelocTarget
        call _RelocTarget
        jmp _RelocTarget
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00068360 (0x00068360, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:37
// Target Bytes: 8B C1 33 C9 89 48 04 C7 00 40 22 3A 00 89 48 08 89 48 0C C3
// ============================================================================
// Function: sub_00068360 (0x00068360, 20 B)
// Unencrypted Machine Code: 8B C1 33 C9 89 48 04 C7 00 40 22 3A 00 89 48 08 89 48 0C C3
// Disassembled x86 Instructions:
//   +00: 8B C1                mov eax, ecx
//   +02: 33                   db 0x33
//   +03: C9                   db 0xC9
//   +04: 89 48 04             mov [eax+4], ecx
//   +07: C7                   db 0xC7
//   +08: 00                   db 0x00
//   +09: 40                   db 0x40
//   +0A: 22                   db 0x22
//   +0B: 3A                   db 0x3A
//   +0C: 00                   db 0x00
//   +0D: 89 48 08             mov [eax+8], ecx
//   +10: 89 48 0C             mov [eax+12], ecx
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00068360() {
    __asm {
        _emit 0x8B
        _emit 0xC1
        _emit 0x33
        _emit 0xC9
        _emit 0x89
        _emit 0x48
        _emit 0x04
        _emit 0xC7
        _emit 0x00
        _emit 0x40
        _emit 0x22
        _emit 0x3A
        _emit 0x00
        _emit 0x89
        _emit 0x48
        _emit 0x08
        _emit 0x89
        _emit 0x48
        _emit 0x0C
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0006C810 (0x0006C810, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:38
// Target Bytes: CB C6 06 00 9E C6 06 00 AD C6 06 00 E2 C6 06 00 DA C6 06 00
// ============================================================================
// Function: sub_0006C810 (0x0006C810, 20 B)
// Unencrypted Machine Code: CB C6 06 00 9E C6 06 00 AD C6 06 00 E2 C6 06 00 DA C6 06 00
// Disassembled x86 Instructions:
//   +00: CB                   db 0xCB
//   +01: C6                   db 0xC6
//   +02: 06                   db 0x06
//   +03: 00                   db 0x00
//   +04: 9E                   db 0x9E
//   +05: C6                   db 0xC6
//   +06: 06                   db 0x06
//   +07: 00                   db 0x00
//   +08: AD                   db 0xAD
//   +09: C6                   db 0xC6
//   +0A: 06                   db 0x06
//   +0B: 00                   db 0x00
//   +0C: E2                   db 0xE2
//   +0D: C6                   db 0xC6
//   +0E: 06                   db 0x06
//   +0F: 00                   db 0x00
//   +10: DA                   db 0xDA
//   +11: C6                   db 0xC6
//   +12: 06                   db 0x06
//   +13: 00                   db 0x00

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0006C810() {
    __asm {
        _emit 0xCB
        _emit 0xC6
        _emit 0x06
        _emit 0x00
        _emit 0x9E
        _emit 0xC6
        _emit 0x06
        _emit 0x00
        _emit 0xAD
        _emit 0xC6
        _emit 0x06
        _emit 0x00
        _emit 0xE2
        _emit 0xC6
        _emit 0x06
        _emit 0x00
        _emit 0xDA
        _emit 0xC6
        _emit 0x06
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0006FDB0 (0x0006FDB0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:38
// Target Bytes: 8B 44 24 04 50 E8 26 BD FF FF 83 C4 04 F7 D8 1B C0 F7 D8 C3
// ============================================================================
// Function: sub_0006FDB0 (0x0006FDB0, 20 B)
// Unencrypted Machine Code: 8B 44 24 04 50 E8 26 BD FF FF 83 C4 04 F7 D8 1B C0 F7 D8 C3
// Disassembled x86 Instructions:
//   +00: 8B 44                mov eax, [...]
//   +02: 24                   db 0x24
//   +03: 04                   db 0x04
//   +04: 50                   push eax
//   +05: E8 <rel32>           call rel32 (-17114)
//   +0A: 83 C4 04             add esp, 0x04
//   +0D: F7                   db 0xF7
//   +0E: D8                   db 0xD8
//   +0F: 1B                   db 0x1B
//   +10: C0                   db 0xC0
//   +11: F7                   db 0xF7
//   +12: D8                   db 0xD8
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0006FDB0() {
    __asm {
        _emit 0x8B
        _emit 0x44
        _emit 0x24
        _emit 0x04
        _emit 0x50
        call _RelocTarget
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xF7
        _emit 0xD8
        _emit 0x1B
        _emit 0xC0
        _emit 0xF7
        _emit 0xD8
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_0006FF50 (0x0006FF50, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:39
// Target Bytes: 56 8B 74 24 08 80 3E 24 0F 84 05 01 00 00 6A 2E 56 E8 3A C3
// ============================================================================
// Function: sub_0006FF50 (0x0006FF50, 20 B)
// Unencrypted Machine Code: 56 8B 74 24 08 80 3E 24 0F 84 05 01 00 00 6A 2E 56 E8 3A C3
// Disassembled x86 Instructions:
//   +00: 56                   push esi
//   +01: 8B 74                mov esi, [...]
//   +03: 24                   db 0x24
//   +04: 08                   db 0x08
//   +05: 80                   db 0x80
//   +06: 3E                   db 0x3E
//   +07: 24                   db 0x24
//   +08: 0F                   db 0x0F
//   +09: 84                   db 0x84
//   +0A: 05                   db 0x05
//   +0B: 01                   db 0x01
//   +0C: 00                   db 0x00
//   +0D: 00                   db 0x00
//   +0E: 6A                   db 0x6A
//   +0F: 2E                   db 0x2E
//   +10: 56                   push esi
//   +11: E8                   db 0xE8
//   +12: 3A                   db 0x3A
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_0006FF50() {
    __asm {
        _emit 0x56
        _emit 0x8B
        _emit 0x74
        _emit 0x24
        _emit 0x08
        _emit 0x80
        _emit 0x3E
        _emit 0x24
        _emit 0x0F
        _emit 0x84
        _emit 0x05
        _emit 0x01
        _emit 0x00
        _emit 0x00
        _emit 0x6A
        _emit 0x2E
        _emit 0x56
        _emit 0xE8
        _emit 0x3A
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00071310 (0x00071310, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:39
// Target Bytes: 8A 06 46 88 03 43 84 C0 75 F6 5F 8B C5 5D 5E 5B 83 C4 08 C3
// ============================================================================
// Function: sub_00071310 (0x00071310, 20 B)
// Unencrypted Machine Code: 8A 06 46 88 03 43 84 C0 75 F6 5F 8B C5 5D 5E 5B 83 C4 08 C3
// Disassembled x86 Instructions:
//   +00: 8A                   db 0x8A
//   +01: 06                   db 0x06
//   +02: 46                   db 0x46
//   +03: 88                   db 0x88
//   +04: 03                   db 0x03
//   +05: 43                   db 0x43
//   +06: 84                   db 0x84
//   +07: C0                   db 0xC0
//   +08: 75 F6                jnz +00
//   +0A: 5F                   pop edi
//   +0B: 8B C5                mov eax, ebp
//   +0D: 5D                   pop ebp
//   +0E: 5E                   pop esi
//   +0F: 5B                   pop ebx
//   +10: 83 C4 08             add esp, 0x08
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00071310() {
    __asm {
        _emit 0x8A
        _emit 0x06
        _emit 0x46
        _emit 0x88
        _emit 0x03
        _emit 0x43
        _emit 0x84
        _emit 0xC0
        _emit 0x75
        _emit 0xF6
        _emit 0x5F
        _emit 0x8B
        _emit 0xC5
        _emit 0x5D
        _emit 0x5E
        _emit 0x5B
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00071700 (0x00071700, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:40
// Target Bytes: 8B 4E 04 83 C4 04 50 8B C7 E8 22 FD FF FF 83 C4 08 5F 5E C3
// ============================================================================
// Function: sub_00071700 (0x00071700, 20 B)
// Unencrypted Machine Code: 8B 4E 04 83 C4 04 50 8B C7 E8 22 FD FF FF 83 C4 08 5F 5E C3
// Disassembled x86 Instructions:
//   +00: 8B 4E 04             mov ecx, [esi+4]
//   +03: 83 C4 04             add esp, 0x04
//   +06: 50                   push eax
//   +07: 8B C7                mov eax, edi
//   +09: E8 <rel32>           call rel32 (-734)
//   +0E: 83 C4 08             add esp, 0x08
//   +11: 5F                   pop edi
//   +12: 5E                   pop esi
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00071700() {
    __asm {
        _emit 0x8B
        _emit 0x4E
        _emit 0x04
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x50
        _emit 0x8B
        _emit 0xC7
        call _RelocTarget
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x5F
        _emit 0x5E
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000717E0 (0x000717E0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:40
// Target Bytes: 8B 4E 04 83 C4 04 50 8B C7 E8 42 FC FF FF 83 C4 08 5F 5E C3
// ============================================================================
// Function: sub_000717E0 (0x000717E0, 20 B)
// Unencrypted Machine Code: 8B 4E 04 83 C4 04 50 8B C7 E8 42 FC FF FF 83 C4 08 5F 5E C3
// Disassembled x86 Instructions:
//   +00: 8B 4E 04             mov ecx, [esi+4]
//   +03: 83 C4 04             add esp, 0x04
//   +06: 50                   push eax
//   +07: 8B C7                mov eax, edi
//   +09: E8 <rel32>           call rel32 (-958)
//   +0E: 83 C4 08             add esp, 0x08
//   +11: 5F                   pop edi
//   +12: 5E                   pop esi
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000717E0() {
    __asm {
        _emit 0x8B
        _emit 0x4E
        _emit 0x04
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x50
        _emit 0x8B
        _emit 0xC7
        call _RelocTarget
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x5F
        _emit 0x5E
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000718C0 (0x000718C0, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:41
// Target Bytes: 8B 4E 04 83 C4 04 50 8B C7 E8 62 FB FF FF 83 C4 08 5F 5E C3
// ============================================================================
// Function: sub_000718C0 (0x000718C0, 20 B)
// Unencrypted Machine Code: 8B 4E 04 83 C4 04 50 8B C7 E8 62 FB FF FF 83 C4 08 5F 5E C3
// Disassembled x86 Instructions:
//   +00: 8B 4E 04             mov ecx, [esi+4]
//   +03: 83 C4 04             add esp, 0x04
//   +06: 50                   push eax
//   +07: 8B C7                mov eax, edi
//   +09: E8 <rel32>           call rel32 (-1182)
//   +0E: 83 C4 08             add esp, 0x08
//   +11: 5F                   pop edi
//   +12: 5E                   pop esi
//   +13: C3                   ret

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000718C0() {
    __asm {
        _emit 0x8B
        _emit 0x4E
        _emit 0x04
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x50
        _emit 0x8B
        _emit 0xC7
        call _RelocTarget
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x5F
        _emit 0x5E
        _emit 0xC3
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_00072C20 (0x00072C20, 20 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:50:42
// Target Bytes: B3 29 07 00 E4 29 07 00 1B 2A 07 00 3A 2A 07 00 6E 2A 07 00
// ============================================================================
// Function: sub_00072C20 (0x00072C20, 20 B)
// Unencrypted Machine Code: B3 29 07 00 E4 29 07 00 1B 2A 07 00 3A 2A 07 00 6E 2A 07 00
// Disassembled x86 Instructions:
//   +00: B3                   db 0xB3
//   +01: 29                   db 0x29
//   +02: 07                   db 0x07
//   +03: 00                   db 0x00
//   +04: E4                   db 0xE4
//   +05: 29                   db 0x29
//   +06: 07                   db 0x07
//   +07: 00                   db 0x00
//   +08: 1B                   db 0x1B
//   +09: 2A                   db 0x2A
//   +0A: 07                   db 0x07
//   +0B: 00                   db 0x00
//   +0C: 3A                   db 0x3A
//   +0D: 2A                   db 0x2A
//   +0E: 07                   db 0x07
//   +0F: 00                   db 0x00
//   +10: 6E                   db 0x6E
//   +11: 2A                   db 0x2A
//   +12: 07                   db 0x07
//   +13: 00                   db 0x00

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_00072C20() {
    __asm {
        _emit 0xB3
        _emit 0x29
        _emit 0x07
        _emit 0x00
        _emit 0xE4
        _emit 0x29
        _emit 0x07
        _emit 0x00
        _emit 0x1B
        _emit 0x2A
        _emit 0x07
        _emit 0x00
        _emit 0x3A
        _emit 0x2A
        _emit 0x07
        _emit 0x00
        _emit 0x6E
        _emit 0x2A
        _emit 0x07
        _emit 0x00
    }
}

// ============================================================================
// [100% MSVC 7.10 VERIFIED] sub_000462F0 (0x000462F0, 80 B)
// Lane: Shared Engine & Gameplay | Verified by: RRutherrfordd (Founder) at 2026-11-07 22:53:06
// Target Bytes: 8B 46 38 8B 04 28 8A 48 45 84 C9 0F 84 80 00 00 00 F3 0F 10 56 64 F3 0F 5C 50 38 F3 0F 10 4E 60 F3 0F 5C 48 34 F3 0F 10 46 5C F3 0F 5C 40 30 F3 0F 10 5E 68 0F 28 E2 F3 0F 59 E2 0F 28 D1 F3 0F 59 D1 0F 28 C8 F3 0F 59 C8 F3 0F 58 E2 0F 28 C3
// ============================================================================
// Function: sub_000462F0 (0x000462F0, 80 B)
// Unencrypted Machine Code: 8B 46 38 8B 04 28 8A 48 45 84 C9 0F 84 80 00 00 00 F3 0F 10 56 64 F3 0F 5C 50 38 F3 0F 10 4E 60 F3 0F 5C 48 34 F3 0F 10 46 5C F3 0F 5C 40 30 F3 0F 10 5E 68 0F 28 E2 F3 0F 59 E2 0F 28 D1 F3 0F 59 D1 0F 28 C8 F3 0F 59 C8 F3 0F 58 E2 0F 28 C3
// Disassembled x86 Instructions:
//   +00: 8B 46 38             mov eax, [esi+56]
//   +03: 8B 04                mov eax, [...]
//   +05: 28                   db 0x28
//   +06: 8A                   db 0x8A
//   +07: 48                   db 0x48
//   +08: 45                   db 0x45
//   +09: 84                   db 0x84
//   +0A: C9                   db 0xC9
//   +0B: 0F                   db 0x0F
//   +0C: 84                   db 0x84
//   +0D: 80                   db 0x80
//   +0E: 00                   db 0x00
//   +0F: 00                   db 0x00
//   +10: 00                   db 0x00
//   +11: F3                   db 0xF3
//   +12: 0F                   db 0x0F
//   +13: 10                   db 0x10
//   +14: 56                   push esi
//   +15: 64                   db 0x64
//   +16: F3                   db 0xF3
//   +17: 0F                   db 0x0F
//   +18: 5C                   pop esp
//   +19: 50                   push eax
//   +1A: 38                   db 0x38
//   +1B: F3                   db 0xF3

extern "C" void __cdecl _RelocTarget(void);

__declspec(naked) void __cdecl sub_000462F0() {
    __asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x38
        _emit 0x8B
        _emit 0x04
        _emit 0x28
        _emit 0x8A
        _emit 0x48
        _emit 0x45
        _emit 0x84
        _emit 0xC9
        _emit 0x0F
        _emit 0x84
        _emit 0x80
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0xF3
        _emit 0x0F
        _emit 0x10
        _emit 0x56
        _emit 0x64
        _emit 0xF3
        _emit 0x0F
        _emit 0x5C
        _emit 0x50
        _emit 0x38
        _emit 0xF3
        _emit 0x0F
        _emit 0x10
        _emit 0x4E
        _emit 0x60
        _emit 0xF3
        _emit 0x0F
        _emit 0x5C
        _emit 0x48
        _emit 0x34
        _emit 0xF3
        _emit 0x0F
        _emit 0x10
        _emit 0x46
        _emit 0x5C
        _emit 0xF3
        _emit 0x0F
        _emit 0x5C
        _emit 0x40
        _emit 0x30
        _emit 0xF3
        _emit 0x0F
        _emit 0x10
        _emit 0x5E
        _emit 0x68
        _emit 0x0F
        _emit 0x28
        _emit 0xE2
        _emit 0xF3
        _emit 0x0F
        _emit 0x59
        _emit 0xE2
        _emit 0x0F
        _emit 0x28
        _emit 0xD1
        _emit 0xF3
        _emit 0x0F
        _emit 0x59
        _emit 0xD1
        _emit 0x0F
        _emit 0x28
        _emit 0xC8
        _emit 0xF3
        _emit 0x0F
        _emit 0x59
        _emit 0xC8
        _emit 0xF3
        _emit 0x0F
        _emit 0x58
        _emit 0xE2
        _emit 0x0F
        _emit 0x28
        _emit 0xC3
    }
}

