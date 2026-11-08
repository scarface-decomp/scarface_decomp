# Re-verification report

Generated 2026-11-08T07:38:33Z by `scripts/reverify_all.py` with **Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86**.

A function counts as VERIFIED only with exact length and bytes, checked relocations, no hard-coded
2006 addresses, and no inline assembly. Addresses are deduplicated across files.

| Status | Functions (unique addresses) |
|---|---|
| VERIFIED | 1,036 |
| MATCH_HARDCODED_ADDR | 0 |
| MISMATCH | 58 |
| POLICY | 61 |
| COMPILE_ERROR | 0 |
| UNMAPPED | 0 |
| NO_CODE | 995 |
| NO_TARGET | 10 |

VERIFIED by binary: pc: 155, xb: 881

## By source file

| File | VERIFIED | MATCH_HARDCODED_ADDR | MISMATCH | POLICY | COMPILE_ERROR | UNMAPPED | NO_CODE | NO_TARGET |
|---|---|---|---|---|---|---|---|---|
| AIAction.cpp | 1 | 0 | 2 | 0 | 0 | 0 | 0 | 1 |
| EmpireHUD.cpp | 3 | 0 | 6 | 0 | 0 | 0 | 0 | 9 |
| EmpireSubHUDs.cpp | 0 | 0 | 3 | 0 | 0 | 0 | 0 | 0 |
| FastBatch2_10Functions.cpp | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| PC_Core_DirectInput_String_Memory.cpp | 28 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| PC_Core_File_And_Drive.cpp | 21 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| PC_Core_Win32Drive_Cement_Audio.cpp | 25 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| StarterBatch1_25Functions.cpp | 16 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| imported/Crowdsourced_PC_Patch_Verified.cpp | 2 | 0 | 0 | 63 | 0 | 0 | 0 | 0 |
| imported/stage0_full_xbe_sweep.cpp | 861 | 1 | 10 | 0 | 0 | 0 | 938 | 0 |
| imported/stage0_pc_scarface_exe_sweep.cpp | 80 | 0 | 38 | 0 | 0 | 0 | 68 | 0 |

## Not checked: no address recorded

These files define functions without recording which original function each one is, so they cannot be verified or counted:

- `AIAction.cpp`: about 2 function definitions
- `CharacterObject.cpp`: about 72 function definitions
- `EmpireHUD.cpp`: about 14 function definitions
- `EmpireSubHUDs.cpp`: about 88 function definitions
- `FastBatch2_10Functions.cpp`: about 1 function definitions
- `StarterBatch1_25Functions.cpp`: about 15 function definitions
- `imported/AutoSynthesized_MSVC71_Verified.cpp`: about 592 function definitions

## Most common reasons

| Status | Reason | Count |
|---|---|---|
| MISMATCH | N/N bytes | 45 |
| POLICY | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. | 40 |
| POLICY | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size N | 21 |
| NO_TARGET | PC address is outside the readable PC code (N-N); verify this function against the Xbox build instead | 10 |
| MISMATCH | Compiled function is N bytes; the original is N bytes. | 8 |
| MISMATCH | +N: '__except_list' is used for two different original addresses; +N: relocation outside the original function | 3 |
| MISMATCH | +N: relocation outside the original function; Compiled function is N bytes; the original is N bytes. | 1 |
| MISMATCH | +N: '??N@YAXPAX@Z' is used for two different original addresses; +N: '?ConEvaluate@RadicalEngine@@YAPBDPBDHNHH | 1 |

## Every checked address

| Address | Symbol | Source | Status | Bytes | Flags | Detail |
|---|---|---|---|---|---|---|
| pc:0x00531A20 | `AIActionRepeatFinite::vfunc_03` | FastBatch2_10Functions.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005A4810 | `EmpireHUD::IsModalHUD` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005B6900 | `EmpireHUD::OnCloseModal` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005C2AE0 | `EmpireHUD::UpdateFrame` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005C36D0 | `EmpireHUD::SetActiveState` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005C3740 | `EmpireHUD::OnPageInit` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005C37F0 | `ConcreteClassRep<EmpireHUD>::CreateFromPool` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005C3800 | `EmpireHUD::~EmpireHUD` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005E1BB0 | `ConcreteAIAction::vfunc_03` | AIAction.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x005E1BC0 | `EmpireHUD::OnResetHUD` | EmpireHUD.cpp | NO_TARGET | 0/0 |  | PC address is outside the readable PC code (0x006DDC00-0x0072EADC); verify this function against the Xbox build instead |
| pc:0x006DDC60 | `ControllerInputPointDirectInput::vfunc_01` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 23/23 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DDC80 | `core::ControllerDirectInput::vfunc_05` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006DDF50 | `core::ControllerDirectInput::vfunc_08` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006DDF60 | `ControllerDirectInput::vfunc_12` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 38/38 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DDF90 | `core::ControllerDirectInput::vfunc_13` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006DDFA0 | `ControllerDirectInput::vfunc_17` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 38/38 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DE000 | `ControllerDirectInput::vfunc_07` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 21/21 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006DE1D0 | `ControllerDirectInput::vfunc_03` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked |
| pc:0x006DE590 | `ControllerSystemDirectInput::vfunc_12` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 19/19 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DE5A0 | `sub_006DE5A0` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006DE620 | `ControllerSystemDirectInput::vfunc_09` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 44/44 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DE650 | `ControllerSystemDirectInput::vfunc_05` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 38/38 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DE690 | `ControllerSystemDirectInput::vfunc_03` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked |
| pc:0x006DEDF0 | `sub_006DEDF0` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DF490 | `sub_006DF490` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006DF4A0 | `LoadSet::vfunc_00` | imported/Crowdsourced_PC_Patch_Verified.cpp | VERIFIED | 5/5 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006DF4C0 | `Platform::vfunc_04` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 24/24 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| pc:0x006DF710 | `core::MemorySpaceAsyncRequest_Copy::vfunc_01` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/5 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| pc:0x006DF720 | `UpperBodyAnimStateCondition::vfunc_13` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006DF730 | `MemoryAllocatorMalloc::vfunc_04` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006DF750 | `MemoryAllocatorMalloc::vfunc_05` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 15/15 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006DF760 | `MemoryAllocatorMalloc::vfunc_07` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 21/21 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006DF7C0 | `MemoryAllocatorMalloc::vfunc_08` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 22/22 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006DF7E0 | `pure3d::pddiDisplay::vfunc_09` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006DF7F0 | `core::MemoryAllocatorMalloc::vfunc_12` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006DF960 | `sub_006DF960` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006E0010 | `GameMemorySegmentCollection::vfunc_00` | imported/Crowdsourced_PC_Patch_Verified.cpp | VERIFIED | 5/5 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E0090 | `String::vfunc_04` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E01E0 | `String::vfunc_06` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 34/34 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E0250 | `String::vfunc_08` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 17/17 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E0430 | `String::vfunc_14` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E0490 | `String::vfunc_11` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| pc:0x006E04B0 | `String::vfunc_19` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 22/22 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E04D0 | `String::vfunc_20` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 22/22 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E04F0 | `String::vfunc_22` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 20/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E0510 | `String::vfunc_21` | PC_Core_DirectInput_String_Memory.cpp | MISMATCH | 24/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 41 bytes; the original is 36 bytes. |
| pc:0x006E0540 | `String::vfunc_03` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked |
| pc:0x006E09E0 | `MemoryDlAllocator::vfunc_06` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 28/28 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E0A60 | `MemoryDlAllocator::vfunc_03` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked |
| pc:0x006E1CF0 | `core::MemoryDlAllocator::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E1D40 | `MemorySmallDlAllocator::vfunc_03` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked |
| pc:0x006E36A0 | `CompletionEventRequest::vfunc_01` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 18/18 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E36C0 | `core::CompletionEventRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3700 | `FileCompletionRequest::vfunc_01` | PC_Core_DirectInput_String_Memory.cpp | VERIFIED | 18/18 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E3750 | `core::FileCompletionRequest::vfunc_03` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| pc:0x006E3760 | `core::DriveCompletionRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3C20 | `fight::VUpperBodyAnimStateCondition::?$ParamString::vfunc_01` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3DD0 | `fight::VDirectionalGetHitCondition::?$ParamEnumConstList::vfunc_01` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3E60 | `core::FileGetPositionRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3EB0 | `DealerSpawnObject::vfunc_45` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3F00 | `fight::VExitConditionTrack::?$ParamBranch::vfunc_01` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3F60 | `core::DriveOpenRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E3FC0 | `core::DriveMediaRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4010 | `GlanceAtOvertakingPed::vfunc_10` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4070 | `core::DriveCreateDirectoryRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E40D0 | `core::DriveDestroyDirectoryRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4150 | `GangSpawnObject::vfunc_45` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E41B0 | `core::DriveFindNextRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4200 | `core::DriveFindCloseRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4260 | `pure3d::d3dContext::vfunc_22` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E4270 | `core::DriveFileDestroyRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E42C0 | `core::DriveCancelRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E42D0 | `core::DriveLockRequest::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4D70 | `File::vfunc_00` | PC_Core_File_And_Drive.cpp | VERIFIED | 12/12 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| pc:0x006E4D80 | `File::vfunc_01` | PC_Core_File_And_Drive.cpp | VERIFIED | 12/12 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| pc:0x006E4F60 | `File::vfunc_10` | PC_Core_File_And_Drive.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4F90 | `File::vfunc_11` | PC_Core_File_And_Drive.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4FC0 | `File::vfunc_12` | PC_Core_File_And_Drive.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E4FE0 | `File::vfunc_13` | PC_Core_File_And_Drive.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5000 | `File::vfunc_14` | PC_Core_File_And_Drive.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5020 | `File::vfunc_15` | PC_Core_File_And_Drive.cpp | VERIFIED | 16/16 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5030 | `File::vfunc_16` | PC_Core_File_And_Drive.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E50E0 | `File::vfunc_21` | PC_Core_File_And_Drive.cpp | VERIFIED | 35/35 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5140 | `File::vfunc_23` | PC_Core_File_And_Drive.cpp | VERIFIED | 29/29 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5160 | `File::vfunc_25` | PC_Core_File_And_Drive.cpp | VERIFIED | 24/24 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5180 | `core::File::vfunc_26` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E51A0 | `core::File::vfunc_30` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E51C0 | `File::vfunc_31` | PC_Core_File_And_Drive.cpp | VERIFIED | 13/13 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E51D0 | `core::File::vfunc_32` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E51E0 | `core::File::vfunc_33` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E54B0 | `File::AddRefLocked` | PC_Core_File_And_Drive.cpp | VERIFIED | 27/27 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5550 | `InstanceDrive::vfunc_00` | PC_Core_File_And_Drive.cpp | VERIFIED | 12/12 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| pc:0x006E5560 | `InstanceDrive::vfunc_01` | PC_Core_File_And_Drive.cpp | VERIFIED | 12/12 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| pc:0x006E58B0 | `InstanceDrive::vfunc_12` | PC_Core_File_And_Drive.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E58D0 | `InstanceDrive::vfunc_13` | PC_Core_File_And_Drive.cpp | VERIFIED | 16/16 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E58E0 | `InstanceDrive::vfunc_14` | PC_Core_File_And_Drive.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5900 | `InstanceDrive::vfunc_15` | PC_Core_File_And_Drive.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5940 | `InstanceDrive::vfunc_17` | PC_Core_File_And_Drive.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5960 | `InstanceDriveExt::vfunc_18` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 26/26 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5A70 | `InstanceDriveExt::vfunc_22` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 35/35 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E5E50 | `InstanceDriveExt::vfunc_46` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 12/12 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E6070 | `Drive::vfunc_00` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 23/23 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E6110 | `sub_006E6110` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E6350 | `sub_006E6350` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E6360 | `sub_006E6360` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E6420 | `sub_006E6420` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E6440 | `core::Drive::vfunc_11` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E6450 | `core::Drive::vfunc_15` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E6710 | `CementLibrary::vfunc_00` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 11/11 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E6720 | `CementLibrary::vfunc_01` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 12/12 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E6730 | `CementLibrary::vfunc_05` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 39/39 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| pc:0x006E6760 | `CementLibrary::vfunc_07` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 10/10 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E6770 | `CementLibrary::vfunc_06` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 23/23 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E6B50 | `CementLibrary::AddRefLocked10` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 23/23 | /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E7480 | `Win32Drive::vfunc_00` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E7490 | `Win32Drive::vfunc_01` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E74A0 | `Win32Drive::vfunc_02` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E74D0 | `Win32Drive::vfunc_22` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 29/29 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E78B0 | `Win32Drive::vfunc_03` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked |
| pc:0x006E7EA0 | `AnimationRetargetingAction::vfunc_14` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E7EB0 | `DriveThread::vfunc_00` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 11/11 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E7EC0 | `DriveThread::vfunc_01` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 11/11 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E8610 | `DriveThread::vfunc_03` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked |
| pc:0x006E9820 | `GameMemorySegmentCollection::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006E9B40 | `content::P3DFileHandler::vfunc_04` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/809 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 36 B, actual function is 809 B |
| pc:0x006E9E70 | `NISStreamDataLoader::vfunc_04` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 27/27 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006E9E90 | `Stats::~Stats` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 31/31 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006E9F50 | `sub_006E9F50` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006EB360 | `sub_006EB360` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006EBD10 | `sub_006EBD10` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006EBDF0 | `OmHalStream::vfunc_10` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 11/11 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006EBFA0 | `OmHalStream::vfunc_08` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 36/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006EBFD0 | `OmHalStream::vfunc_09` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 17/17 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006EC020 | `OmHalStream::vfunc_03` | PC_Core_Win32Drive_Cement_Audio.cpp | VERIFIED | 13/13 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| pc:0x006EC5F0 | `audio::OmHalStream::vfunc_12` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/40 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| pc:0x006EC890 | `om::VGlobalVehicleSound::?$MetaType::vfunc_01` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/199 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 36 B, actual function is 199 B |
| pc:0x006EC960 | `om::VGlobalVehicleSound::?$MetaType::vfunc_02` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/199 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 36 B, actual function is 199 B |
| pc:0x006ECCB0 | `GlobalVehicleSound::vfunc_00` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| pc:0x006ED590 | `audio::Sequence::vfunc_12` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006EE040 | `sub_006EE040` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006EE800 | `audio::MixerMix::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006EE9B0 | `sub_006EE9B0` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006EEBF0 | `om::audio::VMix::?$EntityType::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006EEC00 | `om::audio::VMix::?$EntityType::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006EECB0 | `om::audio::VClip::?$EntityType::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006EECC0 | `om::audio::VClip::?$EntityType::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006EED20 | `audio::Clip::vfunc_12` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006EEDE0 | `om::audio::VSequence::?$EntityType::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006EEDF0 | `om::audio::VSequence::?$EntityType::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006EF290 | `sub_006EF290` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006F04A0 | `audio::LayerTemplate::vfunc_12` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F0560 | `om::audio::VLayerTemplate::?$EntityType::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006F0570 | `om::audio::VLayerTemplate::?$EntityType::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F1660 | `sub_006F1660` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F4D80 | `audio::OggVorbisStream::vfunc_01` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F4D90 | `audio::OggVorbisStream::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F5C90 | `audio::SeqEventContainer::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F6060 | `audio::Mix::vfunc_12` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F67B0 | `om::audio::VListenerEffectWin32::?$EntityType::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x006F67C0 | `om::audio::VListenerEffectWin32::?$EntityType::vfunc_02` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F67D0 | `om::audio::VMix::?$EntityType::vfunc_00` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F6830 | `audio::ListenerEffectWin32::vfunc_12` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F6960 | `audio::SeqEventNestTrack::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F6EC0 | `audio::SeqEventChannelSendVolumes::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F6ED0 | `audio::SeqEventChannelSendVolumes::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F71F0 | `audio::SeqEventChannelSends::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F7200 | `audio::SeqEventChannelSends::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F74F0 | `audio::SeqEventCondition::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F7680 | `audio::SeqEventConditionElse::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F7690 | `audio::SeqEventConditionElse::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F7930 | `audio::SeqEventWait::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F7D80 | `audio::SeqEventWaitBeat::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F7F30 | `audio::SeqEventExpression::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F8240 | `audio::SeqEventStopTrack::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F8300 | `audio::audio::VSeqEventNestTrack::?$SeqEventType::vfunc_00` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F8650 | `audio::SeqEventPlayTrack::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F8930 | `audio::SeqEventChannelVolumes::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F8940 | `audio::SeqEventChannelVolumes::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F9060 | `audio::SeqEventVarVolumeRand::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F9070 | `audio::SeqEventVarVolumeRand::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F9280 | `audio::SeqEventVarVolume::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F9290 | `audio::SeqEventVarVolume::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F94B0 | `audio::SeqEventVarTempo::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F94C0 | `audio::SeqEventVarTempo::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F96C0 | `audio::SeqEventVarPosDist::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F96D0 | `audio::SeqEventVarPosDist::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F98B0 | `audio::SeqEventVarPitchRand::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F98C0 | `audio::SeqEventVarPitchRand::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F9AB0 | `audio::SeqEventVarPitch::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F9AC0 | `audio::SeqEventVarPitch::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006F9E20 | `audio::SeqEventStream::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006F9E30 | `audio::SeqEventStream::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006FA740 | `audio::SeqEventSilence::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006FA750 | `audio::SeqEventSilence::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006FAAA0 | `audio::SeqEventLogicRepeat::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006FAAD0 | `audio::SeqEventLogicRepeat::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006FADC0 | `audio::SeqEventLogicOr::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006FADD0 | `audio::SeqEventLogicOr::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x006FB240 | `audio::SeqEventCrossFade::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006FB970 | `audio::SeqEventClip::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | MISMATCH | 5/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 5/6 bytes |
| pc:0x006FB980 | `audio::SeqEventClip::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00700200 | `FETextObject::vfunc_46` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00701630 | `movie::PlayerBink::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x007016D0 | `GameMemorySegmentCollection::vfunc_01` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/8 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| pc:0x00701B90 | `movie::RenderStrategyBink::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00703300 | `pure3d::d3dDevice::vfunc_06` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00703590 | `pure3d::d3dDevice::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00703DB0 | `pure3d::d3dContext::vfunc_13` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00703DC0 | `pure3d::d3dPrimBufferStream::vfunc_15` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00703FD0 | `pure3d::d3dPrimBuffer::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x007048D0 | `pure3d::d3dErrorShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00704A40 | `pure3d::d3dReflShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00704A50 | `pure3d::d3dReflShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00704A60 | `pure3d::d3dReflShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00704A70 | `pure3d::d3dReflShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00704A80 | `pure3d::d3dReflShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00705050 | `pure3d::d3dPointSpriteShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00705060 | `pure3d::d3dPointSpriteShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00705070 | `pure3d::d3dPointSpriteShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00705080 | `pure3d::d3dPointSpriteShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007050D0 | `sub_007050D0` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x007050E0 | `sub_007050E0` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x007053D0 | `pure3d::d3dLayeredShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007053E0 | `pure3d::d3dLayeredShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007053F0 | `pure3d::d3dLayeredShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00705400 | `pure3d::d3dLayeredShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00705410 | `pure3d::d3dLayeredShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00705430 | `sub_00705430` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00706680 | `pure3d::d3dSpecularShader::vfunc_24` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| pc:0x007066A0 | `pure3d::d3dSpecularShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00706B80 | `pure3d::d3dSpecularShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00706B90 | `pure3d::d3dSpecularShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00706BA0 | `pure3d::d3dSpecularShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00706BB0 | `pure3d::d3dSpecularShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00706BC0 | `pure3d::d3dSpecularShader::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00706D62 | `pure3d::BMPHandler::vfunc_17` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/297 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 36 B, actual function is 297 B |
| pc:0x00707310 | `pure3d::d3dCharacterShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707320 | `pure3d::d3dCharacterShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707330 | `pure3d::d3dCharacterShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707340 | `pure3d::d3dCharacterShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707350 | `pure3d::d3dCharacterShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007073A0 | `sub_007073A0` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707D80 | `sub_00707D80` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707EA0 | `pure3d::d3dVehicleShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707EF0 | `pure3d::d3dVehicleShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707F00 | `pure3d::d3dVehicleShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707F10 | `pure3d::d3dVehicleShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00707F20 | `pure3d::d3dVehicleShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00708100 | `pure3d::d3dVehicleShader::vfunc_31` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00708110 | `pure3d::d3dVehicleShader::vfunc_30` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00708120 | `pure3d::d3dVehicleShader::vfunc_28` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x007081A0 | `sub_007081A0` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x007088B0 | `pure3d::d3dVehicleShader::vfunc_03` | imported/stage0_pc_scarface_exe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| pc:0x00708F50 | `pure3d::d3dShadowShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00708F60 | `pure3d::d3dShadowShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00708F70 | `pure3d::d3dShadowShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00708F80 | `pure3d::d3dShadowShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00708F90 | `pure3d::d3dShadowShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007090A0 | `pure3d::d3dShadowDecalShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007090B0 | `pure3d::d3dShadowDecalShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007090C0 | `pure3d::d3dShadowDecalShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007090D0 | `pure3d::d3dShadowDecalShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007090E0 | `pure3d::d3dShadowDecalShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00709370 | `pure3d::d3dDecalShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00709470 | `pure3d::d3dVertexFadeShader::vfunc_04` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x007094B0 | `pure3d::d3dVertexFadeShader::vfunc_24` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| pc:0x007099F0 | `pure3d::d3dVertexFadeShader::vfunc_16` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00709A00 | `pure3d::d3dVertexFadeShader::vfunc_17` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00709A10 | `pure3d::d3dVertexFadeShader::vfunc_18` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x00709A20 | `pure3d::d3dVertexFadeShader::vfunc_19` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x0072C940 | `sub_0072C940` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x0072CC00 | `sub_0072CC00` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x0072CC10 | `sub_0072CC10` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| pc:0x0072CD30 | `sub_0072CD30` | imported/stage0_pc_scarface_exe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| proto:0x00037AA0 | `AIActionRepeatFinite::vfunc_01` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/211 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 19 B, actual function is 211 B |
| xb:0x00011000 | `sub_00011000` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00011170 | `sub_00011170` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000111A0 | `sub_000111A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000114E0 | `sub_000114E0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/4 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 4 B |
| xb:0x000117D0 | `sub_000117D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00011F20 | `Collidable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00011F90 | `FlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000123B0 | `CollisionBehaviourTypeGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00012A40 | `sub_00012A40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00013840 | `CollisionBehaviourTypeGroup::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00016060 | `CollisionManager::CollisionManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000160C0 | `sub_000160C0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/4 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000173C0 | `CollisionSurfaceType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000173D0 | `sub_000173D0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00017450 | `CollisionSurfaceType::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000179A0 | `sub_000179A0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000179C0 | `LOSManager::LOSManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00018EB0 | `sub_00018EB0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0001CE70 | `sub_0001CE70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0001E140 | `ActionMap::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0001E410 | `ActionMap::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0001E5D0 | `sub_0001E5D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0001E630 | `sub_0001E630` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0001E800 | `sub_0001E800` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/612 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 612 B |
| xb:0x0001EA50 | `sub_0001EA50` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0001ED20 | `sub_0001ED20` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0001ED40 | `sub_0001ED40` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0001ED90 | `sub_0001ED90` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0001EDB0 | `sub_0001EDB0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0001EDD0 | `sub_0001EDD0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0001EE90 | `sub_0001EE90` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0001EEA0 | `sub_0001EEA0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0001EF60 | `sub_0001EF60` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0001EF70 | `sub_0001EF70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00020B30 | `sub_00020B30` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00021620 | `sub_00021620` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000216B0 | `sub_000216B0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00021830 | `sub_00021830` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00021880 | `sub_00021880` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00022610 | `sub_00022610` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00022630 | `fight::TrackFactory::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000226E0 | `FightTree::fight::VEnterExitScriptTrack::?$FightActionController::vfunc_23` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00022710 | `CollisionBehaviourTypeGroup::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00022720 | `Collidable::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 2/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2/3 bytes |
| xb:0x000227A0 | `FightTree::fight::VEnterExitScriptTrack::?$FightActionController::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000227C0 | `FightTree::fight::VSequenceTrack::?$FightActionController::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00022980 | `FightTree::fight::VEnterExitScriptTrack::?$FightActionController::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00022A00 | `fight::VTimedCharacterFightTrack::?$ParamString::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00022A10 | `FEObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00022BA0 | `FEObject::vfunc_38` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00022D40 | `FETextObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00022E50 | `FEBoxObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023170 | `FEP3DObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000231B0 | `sub_000231B0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000231E0 | `FESpriteObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000231F0 | `FEObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00023370 | `FERoundedRectangleObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023B20 | `FEGroupObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023BA0 | `FELayerObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023BB0 | `FEPageObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023BC0 | `FEScreenObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023C00 | `FEProjectObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023C10 | `FEProjectObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00023C80 | `sub_00023C80` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00023D40 | `sub_00023D40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00023F20 | `sub_00023F20` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000240F0 | `FEGroupObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00024B30 | `sub_00024B30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00024E40 | `sub_00024E40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00026230 | `sub_00026230` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/21 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 21 B |
| xb:0x00026710 | `Graph::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000269D0 | `sub_000269D0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000272F0 | `AddressSpawnObject::vfunc_47` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 4/4 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00027300 | `AITask_Chicken::vfunc_40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000274B0 | `MemoryManager::Allocator::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027500 | `MemoryManager::Allocator::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027510 | `MemoryManager::Allocator::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027520 | `MemoryManager::Allocator::vfunc_11` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027530 | `MemoryManager::Allocator::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027540 | `MemoryManager::Allocator::vfunc_14` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027550 | `MemoryManager::Allocator::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027570 | `MemoryManager::Allocator::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00027580 | `MemoryManager::Allocator::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000276F0 | `sub_000276F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00028300 | `sub_00028300` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/994 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 994 B |
| xb:0x00028FD0 | `GameGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00029190 | `VGameGroup::?$ScriptObjectEntity::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000294A0 | `GameObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00029520 | `GameObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00029550 | `sub_00029550` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00029840 | `GameSet::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00029CC0 | `GameSet::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00029F40 | `FEGroupObject::vfunc_26` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x00029F80 | `GameSetObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002A160 | `sub_0002A160` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A170 | `sub_0002A170` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A320 | `GameSimObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002A370 | `GameSimObject::vfunc_59` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A380 | `GameSimObject::vfunc_61` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A390 | `GameSimObjectBatchView::vfunc_63` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002A5A0 | `GameSimObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A5C0 | `PositionObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002A5D0 | `PositionObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A670 | `PositionSetObject::vfunc_26` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x0002A720 | `PositionSetObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002A7C0 | `RCObject::vfunc_39` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A7D0 | `RCObject::vfunc_40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A7E0 | `RCObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002A860 | `RCObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002A9B0 | `ScriptDeclarationGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002A9D0 | `sub_0002A9D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002AA40 | `SetDeclaration::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002AA70 | `ScriptDeclaration::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002AAC0 | `ScriptDeclarationGroup::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002AB30 | `SetDeclaration::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002AB90 | `ScriptDeclaration::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002ADA0 | `ConsoleObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002AFD0 | `ScriptObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002B9F0 | `sub_0002B9F0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002CAD0 | `sub_0002CAD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002CAE0 | `VStreamedTemplate::?$ScriptObjectEntity::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002D2B0 | `sub_0002D2B0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/22 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 22 B |
| xb:0x0002D390 | `sub_0002D390` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002D5B0 | `sub_0002D5B0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002D7B0 | `sub_0002D7B0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002DA60 | `sub_0002DA60` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0002E070 | `sub_0002E070` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002E0D0 | `sub_0002E0D0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0002E1B0 | `sub_0002E1B0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/4 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 4 B |
| xb:0x0002E5C0 | `Template::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002E650 | `StreamedTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002E690 | `core::ControllerInputPointXBox::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002E6A0 | `StreamedTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0002E930 | `sub_0002E930` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002F890 | `sub_0002F890` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0002F8A0 | `sub_0002F8A0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00030940 | `NavMesh::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000336C0 | `Path::vfunc_04` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00034710 | `Path::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000348D0 | `RoadPath::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000351C0 | `sub_000351C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000354C0 | `sub_000354C0` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 1/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 6 bytes; the original is 3 bytes. |
| xb:0x000356A0 | `sub_000356A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00036CD0 | `sub_00036CD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00038DD0 | `PathManager::PathManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0003AEE0 | `sub_0003AEE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0003D130 | `RoadGraph::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0003D580 | `sub_0003D580` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0003D9A0 | `sub_0003D9A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0003D9D0 | `sub_0003D9D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0003E2D0 | `sub_0003E2D0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/21 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 21 B |
| xb:0x0003EB70 | `pure3d::TargaHandler::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0003EBD0 | `sub_0003EBD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0003FF80 | `sub_0003FF80` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000462F0 | `sub_000462F0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/190 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 80 B, actual function is 190 B |
| xb:0x00046820 | `sub_00046820` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/348 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 348 B |
| xb:0x000476A0 | `sub_000476A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00047DD0 | `renderer::RenderableHandle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00047E30 | `sub_00047E30` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00047E70 | `sub_00047E70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00047E80 | `sub_00047E80` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00047FE0 | `sub_00047FE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00048010 | `sub_00048010` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00048050 | `sub_00048050` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000480F0 | `sub_000480F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00048100 | `sub_00048100` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00048120 | `sub_00048120` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00048430 | `sub_00048430` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00048490 | `sub_00048490` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00049870 | `sub_00049870` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00049D30 | `renderer::DecalsHandle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00049DE0 | `renderer::TraceFireHandle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004A280 | `renderer::RenderFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004A760 | `pure3d::TargaHandler::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0004A770 | `GameSimObject::vfunc_55` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004A780 | `pure3d::TargaHandler::vfunc_14` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004C360 | `sub_0004C360` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004C3B0 | `sub_0004C3B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004C3C0 | `sub_0004C3C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004C770 | `pure3d::BMPHandler::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0004D9C0 | `renderer::Scene::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004EB50 | `sub_0004EB50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0004F3F0 | `sub_0004F3F0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00050020 | `sub_00050020` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00050BB0 | `sub_00050BB0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00050C50 | `sub_00050C50` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/12 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 12 B |
| xb:0x000511B0 | `renderer::CharacterRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000517E0 | `renderer::DecalPrimitive::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000517F0 | `renderer::DecalContainer::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000518D0 | `FightTree::fight::VEnterExitScriptTrack::?$FightActionController::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000518E0 | `renderer::DecalContainer::vfunc_21` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000523B0 | `renderer::DecalContainer::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00052520 | `renderer::DecalPrimitive::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00053470 | `renderer::InstancePrimitive::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00053480 | `renderer::InstanceContainer::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00053A50 | `renderer::InstanceContainer::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00053E30 | `renderer::InstancePrimitive::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00054CD0 | `renderer::LightingRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00054ED0 | `renderer::MaskRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00054F90 | `renderer::InstanceRenderable::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00055040 | `renderer::NISRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000551F0 | `renderer::OceanPrimitive::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00055230 | `renderer::InstanceContainer::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00055240 | `renderer::OceanContainer::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00055350 | `renderer::OceanContainer::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00055380 | `renderer::OceanPrimitive::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00055C90 | `renderer::PlugInRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00055DE0 | `renderer::PropRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00056200 | `renderer::WorldGeoRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00056260 | `sub_00056260` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00056610 | `sub_00056610` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000566D0 | `renderer::ZonePkgRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000573D0 | `sub_000573D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00057D20 | `renderer::RainRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00059350 | `renderer::Renderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005A920 | `renderer::SkidmarkContainer::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0005AB70 | `renderer::SkidmarkPrimitive::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005AC70 | `renderer::SkidmarkContainer::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005B580 | `sub_0005B580` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0005D1B0 | `renderer::TraceFireRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005D7B0 | `renderer::VehiclePrimitive::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005D7C0 | `renderer::VehicleContainer::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0005D860 | `sub_0005D860` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0005DB80 | `renderer::VehicleContainer::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005DBB0 | `renderer::VehicleContainer::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005DBC0 | `renderer::VehicleContainer::vfunc_20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005E1D0 | `renderer::VehiclePrimitive::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005E430 | `renderer::VehicleRenderable::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0005F970 | `renderer::WakePrimitive::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0005F980 | `renderer::WakeContainer::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0005FD90 | `renderer::WakeContainer::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00060860 | `sub_00060860` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00060870 | `sub_00060870` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00060B40 | `sub_00060B40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00060B50 | `sub_00060B50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00060C70 | `sub_00060C70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00060C80 | `sub_00060C80` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000610A0 | `DriveManager::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00061630 | `sub_00061630` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000618E0 | `sub_000618E0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000618F0 | `sub_000618F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00061970 | `pure3d::SimpleFrameController::vfunc_27` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00061CA0 | `sub_00061CA0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/30 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 30 B |
| xb:0x000631A0 | `sub_000631A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000631F0 | `sub_000631F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00063220 | `sub_00063220` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00063230 | `sub_00063230` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00063240 | `sub_00063240` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00063250 | `sub_00063250` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00063570 | `sub_00063570` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/36 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 36 B |
| xb:0x00063B80 | `sub_00063B80` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 14 B |
| xb:0x00063DA0 | `sub_00063DA0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000643C0 | `sub_000643C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000643D0 | `ResourceManager::ResourceManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00064FA0 | `SoundEntityLoader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00064FB0 | `om::VGlobalVehicleSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00064FE0 | `om::VCarSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00065010 | `om::VBoatSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00065040 | `om::VPlaneSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00065070 | `om::VCollisionSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000650A0 | `om::VFeHudSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000650D0 | `om::VStatePropSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00065100 | `om::VFirearmSound::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00065130 | `om::VSoundBank::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00065160 | `om::VSoundDialogueText::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000653B0 | `om::VGlobalVehicleSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000653C0 | `om::VGlobalVehicleSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000653D0 | `om::VGlobalVehicleSound::?$EntityType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00065430 | `GlobalVehicleSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000654F0 | `om::VCarSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065500 | `om::VCarSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065580 | `CarSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065670 | `om::VBoatSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065680 | `om::VBoatSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000656E0 | `BoatSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000657B0 | `om::VPlaneSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000657C0 | `om::VPlaneSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065820 | `PlaneSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000658F0 | `om::VCollisionSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065900 | `om::VCollisionSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065980 | `om::VFeHudSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065990 | `om::VFeHudSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000659F0 | `FeHudSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065AC0 | `om::VStatePropSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065AD0 | `om::VStatePropSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065B50 | `StatePropSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065C40 | `om::VFirearmSound::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065C50 | `om::VFirearmSound::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065CD0 | `FirearmSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065DC0 | `om::VSoundBank::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065DD0 | `om::VSoundBank::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065E50 | `om::VSoundDialogueText::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00065E60 | `om::VSoundDialogueText::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066860 | `SoundDialogueText::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066960 | `SoundBank::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066AC0 | `CollisionSound::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066CC0 | `sub_00066CC0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066CD0 | `sub_00066CD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066CE0 | `sub_00066CE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066CF0 | `sub_00066CF0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D00 | `sub_00066D00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D10 | `sub_00066D10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D20 | `sub_00066D20` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D30 | `sub_00066D30` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D40 | `sub_00066D40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D50 | `sub_00066D50` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D60 | `sub_00066D60` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D70 | `sub_00066D70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D80 | `sub_00066D80` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066D90 | `sub_00066D90` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066DA0 | `sub_00066DA0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066DB0 | `sub_00066DB0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066DC0 | `sub_00066DC0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066DD0 | `sub_00066DD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066DE0 | `sub_00066DE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066DF0 | `sub_00066DF0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E00 | `sub_00066E00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E10 | `sub_00066E10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E20 | `sub_00066E20` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E30 | `sub_00066E30` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E40 | `sub_00066E40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E50 | `sub_00066E50` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E60 | `sub_00066E60` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E70 | `sub_00066E70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E80 | `sub_00066E80` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066E90 | `sub_00066E90` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066EA0 | `sub_00066EA0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066EB0 | `sub_00066EB0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066EC0 | `sub_00066EC0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066ED0 | `sub_00066ED0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00066EE0 | `sub_00066EE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000670D0 | `sub_000670D0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00067BA0 | `sub_00067BA0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00068360 | `sub_00068360` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00068AF0 | `sub_00068AF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00068D50 | `sub_00068D50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00068D60 | `sub_00068D60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00068D70 | `sub_00068D70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00068D90 | `sub_00068D90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0006BD80 | `FunctionDeclStmtNode::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0006C4F0 | `ConditionalExprNode::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0006C810 | `sub_0006C810` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 1 B |
| xb:0x0006D2D0 | `AssignExprNode::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0006F990 | `EmpireHUD::IsModalHUD` | EmpireHUD.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0006F9A0 | `core::DriveFindNextRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0006FDB0 | `sub_0006FDB0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x0006FF50 | `sub_0006FF50` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/305 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 305 B |
| xb:0x000711F0 | `sub_000711F0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00071310 | `sub_00071310` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x00071700 | `sub_00071700` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000717E0 | `sub_000717E0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000718C0 | `sub_000718C0` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/20 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status. |
| xb:0x000720A0 | `sub_000720A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000721C0 | `sub_000721C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00072260 | `sub_00072260` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000724B0 | `sub_000724B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00072C20 | `sub_00072C20` | imported/Crowdsourced_PC_Patch_Verified.cpp | POLICY | 0/22 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.; recorded size 20 B, actual function is 22 B |
| xb:0x000732F0 | `sub_000732F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000746A0 | `sub_000746A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00075710 | `FightContext::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000758D0 | `sub_000758D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000758E0 | `sub_000758E0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00075970 | `sub_00075970` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000765F0 | `sub_000765F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00076E00 | `sub_00076E00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077230 | `sub_00077230` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077240 | `sub_00077240` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077250 | `sub_00077250` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077260 | `sub_00077260` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000772D0 | `sub_000772D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000776D0 | `sub_000776D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000776F0 | `sub_000776F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077700 | `sub_00077700` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077710 | `sub_00077710` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077720 | `sub_00077720` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077730 | `sub_00077730` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00077740 | `sub_00077740` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000777A0 | `sub_000777A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000789E0 | `sub_000789E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00078DF0 | `sub_00078DF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00079FC0 | `sub_00079FC0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0007ABC0 | `sub_0007ABC0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0007ADC0 | `AITask_TauntResponse::vfunc_55` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0007DD40 | `sub_0007DD40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000827B0 | `sub_000827B0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000830E0 | `SoundLoadSequence::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00083950 | `sub_00083950` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00083F50 | `sub_00083F50` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00084070 | `sub_00084070` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000870D0 | `sub_000870D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00087E60 | `sub_00087E60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00087E70 | `sub_00087E70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00088060 | `sub_00088060` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00088100 | `sub_00088100` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00088170 | `sub_00088170` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00088190 | `sub_00088190` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000881E0 | `sub_000881E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008A220 | `sub_0008A220` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008DEA0 | `StatePropManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008F890 | `PropAttachToObjectBehaviour::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008FAF0 | `PropAttachToObjectBehaviour::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008FB50 | `sub_0008FB50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008FBD0 | `pure3d::d3dLayeredShader::vfunc_13` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008FBE0 | `sub_0008FBE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008FC20 | `sub_0008FC20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0008FC30 | `sub_0008FC30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000903C0 | `sub_000903C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00090410 | `sub_00090410` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00090420 | `sub_00090420` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00090430 | `sub_00090430` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00090440 | `sub_00090440` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00090450 | `sub_00090450` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000905D0 | `sub_000905D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00090660 | `sub_00090660` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000906A0 | `StreamManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00091B40 | `sub_00091B40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00094C70 | `sub_00094C70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00094C80 | `sub_00094C80` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00094CB0 | `VarietyFileBank::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00094CF0 | `VarietyFile::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00095330 | `VarietyFileBank::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00095360 | `VarietyFile::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00096460 | `VarietySlotManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00096480 | `VarietyDeclarationGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000964B0 | `VarietyObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00096510 | `VarietySlot::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000965D0 | `VarietyDeclarationGroup::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00096600 | `VarietyObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00096630 | `VarietySlot::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00097030 | `sub_00097030` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00097040 | `sub_00097040` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00097050 | `sub_00097050` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00097970 | `TriggerManager::TriggerManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00098460 | `sub_00098460` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00098840 | `sub_00098840` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00098BE0 | `sub_00098BE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00099810 | `sub_00099810` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0009A770 | `sub_0009A770` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0009B110 | `sub_0009B110` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0009B2D0 | `AirplanePlaneCollisionReceiver::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0009C0C0 | `AirplaneLocomotion::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0009E670 | `sub_0009E670` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0009E680 | `sub_0009E680` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000A4A50 | `sub_000A4A50` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000A4DA0 | `HelicopterLocomotion::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000A4DF0 | `HelicopterLocomotion::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000A5890 | `sub_000A5890` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000A6B90 | `sub_000A6B90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000A6EF0 | `sub_000A6EF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AACB0 | `sub_000AACB0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AACC0 | `sub_000AACC0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB000 | `sub_000AB000` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000AB080 | `sub_000AB080` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB120 | `sub_000AB120` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB130 | `sub_000AB130` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB1B0 | `sub_000AB1B0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000AB360 | `sub_000AB360` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB450 | `sub_000AB450` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB4E0 | `sub_000AB4E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB4F0 | `sub_000AB4F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB5A0 | `sub_000AB5A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB830 | `sub_000AB830` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000AB880 | `sub_000AB880` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB890 | `sub_000AB890` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AB8A0 | `sub_000AB8A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000ABA30 | `sub_000ABA30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000ABA40 | `sub_000ABA40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000AE150 | `sub_000AE150` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B11F0 | `sub_000B11F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B1CA0 | `sub_000B1CA0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B2070 | `sub_000B2070` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B2100 | `sub_000B2100` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B6040 | `VehiclePropAttachmentBehaviour::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B69A0 | `VehicleSirenBehaviour::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B7850 | `VehicleZoneControlBehaviour::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B7EB0 | `Collidable::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000B81A0 | `sub_000B81A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B84C0 | `sub_000B84C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B8760 | `sub_000B8760` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000B9630 | `sub_000B9630` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000BCAD0 | `sub_000BCAD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000C2BF0 | `sub_000C2BF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000C4730 | `ScriptContextProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000C47A0 | `WeaponPickupContextProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000C5240 | `ExecScriptFunctionAction::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000C6180 | `sub_000C6180` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000C6300 | `sub_000C6300` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000C6730 | `SaveGameManagerFlowClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000C6EA0 | `sub_000C6EA0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000C6FF0 | `SaveGameController::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000C7000 | `sub_000C7000` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000C7B10 | `SaveGameObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000C8630 | `SaveGameObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CA1E0 | `sub_000CA1E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CA790 | `sub_000CA790` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CA7A0 | `sub_000CA7A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CAA00 | `sub_000CAA00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000CBC30 | `sub_000CBC30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CCE60 | `NISStreamDataLoader::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CD830 | `NISManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CD8F0 | `NISPackage::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CDF30 | `NISPackage::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CE360 | `Collidable::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CE7A0 | `NISPartition::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CE970 | `Condition::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CF250 | `sub_000CF250` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CF290 | `sub_000CF290` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CF7E0 | `sub_000CF7E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CF7F0 | `sub_000CF7F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000CFC10 | `sub_000CFC10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000D00A0 | `sub_000D00A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000D6C60 | `audio::HalRadicalAdpcmDecodeStream::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D6C90 | `sub_000D6C90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D7820 | `sub_000D7820` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D7FE0 | `sub_000D7FE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000D8270 | `sub_000D8270` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000D8280 | `sub_000D8280` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000D84D0 | `sub_000D84D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D84E0 | `sub_000D84E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D84F0 | `sub_000D84F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D86E0 | `sub_000D86E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D86F0 | `sub_000D86F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000D8A00 | `sub_000D8A00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DCD10 | `sub_000DCD10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DD3D0 | `sub_000DD3D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000DD480 | `sub_000DD480` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000DD640 | `fight::VDirectionalGetHitCondition::?$ParamEnumConstList::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000DD680 | `AreFeetOnGround::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DD700 | `DirectionalGetHitCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DD770 | `MeleeAttackDirectionCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DD860 | `MeleeGetHitDirectionCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DD8C0 | `MeleeGetHitTypeCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DD930 | `SpeedCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DD960 | `DistanceToTargetCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDA00 | `WeaponGroupCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDC20 | `IsInjuredCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDC80 | `IsWeaponRaised::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDCE0 | `IsRageMode::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDD10 | `IsCrouchingCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDD70 | `IsCrouchRunCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDDD0 | `ButtonEventCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DDEC0 | `fight::VTimedFightTrack::?$ParamFloatConstRange::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000DE370 | `sub_000DE370` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000DE4B0 | `fight::ConditionFactory::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E11C0 | `sub_000E11C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E1250 | `SubAction::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E2490 | `AnimationAction::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E2BD0 | `AnimationRetargetingAction::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E3560 | `sub_000E3560` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E4280 | `sub_000E4280` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E7360 | `Animation360Track::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E7500 | `AnimationTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E7590 | `sub_000E7590` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E75A0 | `sub_000E75A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E75C0 | `sub_000E75C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E78D0 | `AnimationRetargetingTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E78E0 | `sub_000E78E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E7900 | `sub_000E7900` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E7940 | `sub_000E7940` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E79F0 | `AnimationRetargetingTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E7A50 | `fight::VAnimationRetargetingTrack::?$ParamVector::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E7DB0 | `AnimationRewinderTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E7F50 | `BlendTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E7FC0 | `BlendTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E80E0 | `CameraShakeTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E8150 | `CameraShakeTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E85B0 | `DismemberTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E8880 | `sub_000E8880` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E88D0 | `sub_000E88D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E8920 | `sub_000E8920` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E8970 | `sub_000E8970` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E89C0 | `DramaticCameraTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E9210 | `ExitConditionTrack::vfunc_23` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E9230 | `ExitConditionTrack::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E9240 | `ExitConditionTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E9300 | `fight::VExitConditionTrack::?$ParamBranch::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E9310 | `fight::VExitConditionTrack::?$ParamConditionGroup::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E9570 | `LayeredAnimationTrack::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E95E0 | `sub_000E95E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E9880 | `pure3d::ImageFont::vfunc_14` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E9A10 | `LocomotionTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E9A90 | `sub_000E9A90` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E9AD0 | `sub_000E9AD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000E9C30 | `ExecScriptFunctionTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E9E20 | `sub_000E9E20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000E9F40 | `SoundFadeTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EA300 | `TargetAnimationTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EA330 | `sub_000EA330` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EA4A0 | `sub_000EA4A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EA4B0 | `sub_000EA4B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EB680 | `sub_000EB680` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000EC220 | `DataBroker::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EEBB0 | `sub_000EEBB0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EEBC0 | `sub_000EEBC0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EEBD0 | `sub_000EEBD0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EEBE0 | `sub_000EEBE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EEC50 | `sub_000EEC50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EEC60 | `sub_000EEC60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EEC70 | `sub_000EEC70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EECB0 | `sub_000EECB0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000EF250 | `WeaponStreamingClient::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EF310 | `sub_000EF310` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EFC10 | `AIActionTreeCreatingTask::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000EFC20 | `AIActionTreeCreatingTask::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EFCF0 | `GlanceAtOvertakingPed::vfunc_07` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x000EFD20 | `GlanceAtOvertakingPed::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000EFD90 | `CheckOutToeToHead::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000EFDA0 | `CheckOutToeToHead::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000EFDB0 | `CheckOutToeToHead::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000EFDE0 | `GlanceAbsentMindedly::vfunc_00` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x000EFE30 | `GlanceAtOvertakingPed::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000F0A70 | `GlanceAtVehicle::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000F0E20 | `sub_000F0E20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000F0FC0 | `sub_000F0FC0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000F15B0 | `sub_000F15B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000F15C0 | `sub_000F15C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000F1690 | `sub_000F1690` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000F16A0 | `sub_000F16A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000F1710 | `sub_000F1710` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000F17A0 | `sub_000F17A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x000F4EE0 | `sub_000F4EE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x000FF0C0 | `sub_000FF0C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00100210 | `AIBehavior::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00101170 | `AIBehavior::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001017F0 | `sub_001017F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001033C0 | `sub_001033C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001041D0 | `AIStimulusTable::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00104710 | `AIStimulusTable::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00104E10 | `BoatAIBehaviour::vfunc_32` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00105020 | `AITask::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00105880 | `AITask_BegForLife::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00105910 | `AITask_BegForLife::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00105D30 | `AITask_ChallengeTony::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00106580 | `AITask_Chicken::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001067A0 | `sub_001067A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00106DA0 | `AITask_CodeAbstract::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00107600 | `AITask_FleeFromPosition::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001076B0 | `AITask_FleeWhenOutGunned::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00107770 | `AITask_FleeFromExplodingCar::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001077C0 | `AITask_FleeWhenOutGunned::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00107930 | `AITask_IdleAction::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00108BA0 | `AITask_IdleAction::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001095A0 | `AITask_PedFlee::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001095B0 | `AITask_PedFlee[+76]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001096A0 | `AITask_PedTraffic::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001096B0 | `AITask_Chicken::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001096D0 | `sub_001096D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00109900 | `AITask_ReactToStaggeredStim::vfunc_37` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00109CA0 | `AITask_ReactToStaggeredStim::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00109DE0 | `AITask_ReactToStaggeredStimInStationaryVehicle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00109E00 | `AITask_SharkInteractWithSwimmer::vfunc_44` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00109E70 | `AITask_SharkInteractWithSwimmer::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00109E90 | `AITask_SharkInteractWithBoat::vfunc_44` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010A5C0 | `AITask_SharkInteractWithBoat::vfunc_48` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010A740 | `AITask_SharkInteractWithSwimmer::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010A7C0 | `AITask_SharkInteractWithBoat::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010A7F0 | `AITask_SharkWander::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010AA90 | `sub_0010AA90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010AB00 | `sub_0010AB00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010BDC0 | `AITask_Dummy::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010BDD0 | `AITask_Dummy::vfunc_40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010BE30 | `AITask_DummyInVehicle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010BEE0 | `AITask_Engage::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010BF10 | `AITask_DestroyObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010BF90 | `AITask_Patrol::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010C070 | `AITask_DummyInVehicle::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010C180 | `sub_0010C180` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010D290 | `AITask_BasicInVehicle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010D2E0 | `AITask_InVehicle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010D360 | `AITask_SlowDownCarForCorpses::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010D3C0 | `sub_0010D3C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010E1A0 | `AITask_VehicleGetIn::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010E830 | `AITask_WaitWhenTonyIsNear::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010EB70 | `sub_0010EB70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010EC00 | `AttractPointTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010EC60 | `sub_0010EC60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010EC70 | `sub_0010EC70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010EC80 | `sub_0010EC80` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010EDE0 | `sub_0010EDE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010EE00 | `sub_0010EE00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0010EF70 | `ActivityTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010F010 | `AttractPointTemplateGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010F1A0 | `AttractPoint::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0010F300 | `sub_0010F300` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00110A00 | `AttractPoint::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00111CC0 | `CopManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00112E50 | `CoverObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001152E0 | `FlowClient::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00115330 | `HenchmanManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00115AA0 | `sub_00115AA0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00115C10 | `sub_00115C10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00115FA0 | `PathGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001161D0 | `sub_001161D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00119470 | `sub_00119470` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00119920 | `sub_00119920` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0011C920 | `AITask_IdleChatResponse::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0011C930 | `AITask_IdleChatResponse::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0011C990 | `AITask_IdleChatInitiate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0011C9A0 | `AITask_IdleChatInitiate::vfunc_57` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0011C9F0 | `AITask_ProvokeAnotherPed::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0011CA00 | `AITask_ProvokeAnotherPed::vfunc_57` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0011D1C0 | `TargetSet::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0011DF00 | `AIStimulusDetectorBasicType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0011E070 | `sub_0011E070` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0011E190 | `sub_0011E190` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00120020 | `AIActionRepeatIndefinite::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001200A0 | `AIActionThenIfComplete::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00120910 | `AIActionCustomLogicalEffect::vfunc_03` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00120E10 | `sub_00120E10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00120F00 | `AIActionCancelPhysicalState::vfunc_06` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x00121270 | `AIActionWaitForCondition::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00121900 | `AIConditionCustom::Evaluate` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00121980 | `AIConditionUnary::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00121990 | `AIConditionNot::Evaluate` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00122610 | `AIConditionNot::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00122680 | `AIConditionAnd::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00123360 | `AITask_AvoidIncomingCar::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00123420 | `AITask_NearlyHitByCar::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00123470 | `sub_00123470` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00123710 | `AITask_BumpReflex::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00123760 | `AITask_CopChallenge[+88]::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00123FB0 | `AITask_CopChallenge::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00123FC0 | `AITask_CopChallenge[+88]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00124580 | `sub_00124580` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00125050 | `AITask_RunToAssistCorpse::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00125060 | `DriversSmartCollection::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00125110 | `AITask_GawkAtCorpse::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00125120 | `AITask_GawkAtCorpse[+84]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00125480 | `AITask_DealerWarnTony::vfunc_47` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001258C0 | `AITask_DealerAttractTony::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00125920 | `AITask_DealerWarnTony::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00125930 | `AITask_DealerWarnTony[+92]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00125D40 | `AITask_FollowActor::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126030 | `AITask_ForcedIntimidation::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126070 | `sub_00126070` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001260D0 | `AITask_IdleChatInitiate::vfunc_60` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001260E0 | `AITask_IdleChatInitiate::vfunc_61` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126130 | `sub_00126130` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126140 | `AITask_ProvokeAnotherPed::vfunc_60` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126150 | `AITask_ProvokeAnotherPed::vfunc_61` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001261A0 | `sub_001261A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001262A0 | `AITask_ProvokeAnotherPed::vfunc_62` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001262B0 | `AITask_ProvokeAnotherPed::vfunc_58` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001262C0 | `AITask_IdleChatResponse::vfunc_49` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| xb:0x00126450 | `sub_00126450` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126520 | `sub_00126520` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126670 | `AITask_IdleChatInitiate::vfunc_62` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00126EB0 | `AITask_IdleChatInitiate::vfunc_56` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001270E0 | `AITask_MonitorCustomLoopState::vfunc_47` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001273C0 | `AITask_MonitorCustomLoopState::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00127400 | `sub_00127400` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001276A0 | `AITask_ReactToDangerReaction::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001276B0 | `AIActionTreeCreatingTask[+84]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00127750 | `sub_00127750` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00128360 | `AITask_WatchDangerSource::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001283E0 | `AITask_Cower::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00128490 | `AITask_PossibleMildInterest::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001284A0 | `CollisionBehaviourTypeGroup::vfunc_27` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00128510 | `AITask_ReactToVisibleGun::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00128520 | `AITask_ReactToVisibleGun[+84]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001287E0 | `AITask_RecognizeTony::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00128A50 | `sub_00128A50` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00128A80 | `AITask_TauntResponse::vfunc_54` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00128B30 | `AITask_ProvokeResponse::vfunc_53` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00129430 | `AITask_TauntResponse::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00129490 | `AITask_BumpApology::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001294F0 | `AITask_ProvokeResponse::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00129A80 | `AITask_CarjackingResponse::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0012A020 | `AITask_TauntTony::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0012A310 | `sub_0012A310` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0012E040 | `sub_0012E040` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00131890 | `sub_00131890` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00131D00 | `AICommandSequencer::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00134470 | `AICommandSequencer::Cmd::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00134480 | `sub_00134480` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00134940 | `sub_00134940` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001388D0 | `sub_001388D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00138B90 | `AICommandWaits::Wait_HearGunShot::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00138CB0 | `AICommandWaits::Wait_SeeCharacterWeapon::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00138CD0 | `BoatAIBehaviour::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00138E70 | `BoatAIBehaviour::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0013BF70 | `BoatAITask::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0013C020 | `BoatAITask_CallForBoat::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0013C030 | `BoatAITask::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0013CB00 | `sub_0013CB00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0013CB10 | `sub_0013CB10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0013CB90 | `BoatAITask_Enemy::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0013CE80 | `CarAIBehavior::vfunc_32` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0013D010 | `sub_0013D010` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001416E0 | `sub_001416E0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00141C00 | `CarAIBehavior::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00144D20 | `CarAIBehavior::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001460C0 | `CarAITask::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001460D0 | `CarAITask::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001461B0 | `CarAITask_CallForCar::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00146440 | `sub_00146440` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00146450 | `sub_00146450` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00146D90 | `CarAITask_Enemy::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00146DA0 | `CarAITask_CallForCar::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00146DF0 | `CarAITask_Traffic::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00146E10 | `CarAITask_Traffic::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00146FA0 | `CarAITask_TrafficCop::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00147880 | `HelicopterAIBehavior::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00147890 | `HelicopterAIBehavior::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00149760 | `sub_00149760` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00149810 | `HelicopterAITask::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014A250 | `VehicleAI::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014A270 | `GameSimObject::vfunc_57` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014A380 | `VehicleAI::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014A5E0 | `VehicleAITask::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014A600 | `VehicleAITask::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014A680 | `BoundarySphere::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014A6C0 | `BoundarySphere::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014A760 | `IntersectionObject::vfunc_30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014A7F0 | `IntersectionObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014ADF0 | `IntersectionObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014C300 | `ShallowWater::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014CB70 | `sub_0014CB70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014F2C0 | `BlendCamera::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014F2D0 | `CollisionBehaviourTypeGroup::vfunc_28` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014FF10 | `CameraManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0014FF20 | `sub_0014FF20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014FF80 | `sub_0014FF80` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0014FFE0 | `sub_0014FFE0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00150170 | `CameraManager::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001522E0 | `sub_001522E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00153C30 | `DramaticCamera::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00154530 | `GenericCharacterCamera::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00154540 | `sub_00154540` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00154560 | `sub_00154560` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001545F0 | `GenericCharacterCamera::vfunc_41` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00154680 | `GenericCharacterCamera::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00157F20 | `GenericVehicleCamera::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00158300 | `GenericVehicleCamera::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00158950 | `GenericVehicleCamera::vfunc_40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015A650 | `sub_0015A650` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015A660 | `sub_0015A660` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015A700 | `NISCamera::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015A710 | `NISCamera::vfunc_41` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015AC50 | `NISCamera::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015D510 | `sub_0015D510` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015D5D0 | `sub_0015D5D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015D640 | `sub_0015D640` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015D680 | `sub_0015D680` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015D6A0 | `sub_0015D6A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015D7E0 | `ActionState::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015D990 | `WallCover::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015EB20 | `sub_0015EB20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015F730 | `AnimationLoaderObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015F7A0 | `AnimationLoaderObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015FB00 | `DanceState::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015FB10 | `sub_0015FB10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015FB20 | `sub_0015FB20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015FB50 | `sub_0015FB50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0015FD00 | `Stamina::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0015FD50 | `DanceState::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00160E50 | `CameraState::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00161040 | `CellPhoneState::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001612C0 | `sub_001612C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001624C0 | `sub_001624C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001624D0 | `sub_001624D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001631A0 | `sub_001631A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00163330 | `sub_00163330` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00163340 | `sub_00163340` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00163610 | `sub_00163610` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00163D60 | `sub_00163D60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00163DA0 | `sub_00163DA0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00163DB0 | `sub_00163DB0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001641E0 | `sub_001641E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001641F0 | `sub_001641F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164240 | `sub_00164240` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164250 | `sub_00164250` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001645F0 | `sub_001645F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001646E0 | `CharacterObject::vfunc_48` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001646F0 | `sub_001646F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164760 | `sub_00164760` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00164980 | `sub_00164980` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164990 | `sub_00164990` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001649A0 | `sub_001649A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164A00 | `sub_00164A00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164A30 | `sub_00164A30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164A60 | `sub_00164A60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164B70 | `sub_00164B70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164B80 | `sub_00164B80` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164B90 | `sub_00164B90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164BD0 | `sub_00164BD0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164C20 | `sub_00164C20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164CC0 | `sub_00164CC0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164CD0 | `sub_00164CD0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164CE0 | `sub_00164CE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164CF0 | `sub_00164CF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164D60 | `sub_00164D60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164F30 | `sub_00164F30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00164F40 | `sub_00164F40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00165760 | `sub_00165760` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00167CE0 | `CharacterObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00167D10 | `CharacterObject::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00167D20 | `CharacterObject::vfunc_51` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00167D30 | `CharacterObject::vfunc_50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0016E020 | `CivilianBase::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0016E030 | `CivilianBase::vfunc_67` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0016E060 | `Civilian::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0016E090 | `CivilianInterior::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0016E0C0 | `DeadBody::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0016E120 | `ScriptCharacter::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0016E290 | `GangMember::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0016E2A0 | `sub_0016E2A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0016E2C0 | `sub_0016E2C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0016E300 | `DWStreetDealer::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0016EA90 | `CharacterObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0016F390 | `DWHenchman::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00171310 | `InventoryObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00171360 | `InventoryType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001713B0 | `InventoryBox::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001714C0 | `InventoryType::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00171880 | `InventoryOwner::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00171D40 | `sub_00171D40` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00171DC0 | `sub_00171DC0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00177530 | `RageState::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00177EA0 | `sub_00177EA0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00177F70 | `sub_00177F70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017AC10 | `sub_0017AC10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017B610 | `sub_0017B610` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017E6E0 | `sub_0017E6E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017E6F0 | `sub_0017E6F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017E700 | `sub_0017E700` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017E710 | `sub_0017E710` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017EC20 | `AITask_ReactToDangerReaction[+84]::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017EC80 | `pure3d::TargaHandler::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017ED40 | `NISExpAnimationAction::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0017ED70 | `sub_0017ED70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00181200 | `NISWeaponAttachAction::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00181230 | `NISVehicleAnimationAction::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00181310 | `NISExpAnimationAction::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00182970 | `DamageJointCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001829E0 | `IsMainCharacterCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00182A50 | `IsFemaleCharacterCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00182AB0 | `WeaponCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00182B20 | `DamageWeaponCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00183030 | `GameFightContext::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00185F50 | `NISFadeTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001860D0 | `NISStatePropSpawnTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001863F0 | `NISResourceLoaderTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001865D0 | `NISHoldCameraPositionTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001866A0 | `NISScriptFunctionCallTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00186760 | `NISSequencePlayTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001867F0 | `NISDriveWorldStreamerTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00188150 | `sub_00188150` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001881C0 | `FireObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00188460 | `sub_00188460` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001888E0 | `FireTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00188D90 | `RageModeGraphAnim::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00189340 | `GroundObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00189350 | `GroundObject::vfunc_39` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001898B0 | `BlackjackHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00189AF0 | `BlackjackHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0018B090 | `ExoticsHUD2::vfunc_41` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0018B0A0 | `ExoticsHUD2::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0018BD90 | `ExoticsHUD2::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0018C930 | `FightBettingHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0018D0D0 | `FightBettingHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0018E690 | `GameOverHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0018EE90 | `GenericMeter::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0018EEC0 | `GenericMeter::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0018EF50 | `GenericP3DMeter::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0018F080 | `AnimationAction::vfunc_11` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00190210 | `GenericWeaponHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001903A0 | `GenericWeaponHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001903C0 | `HitsHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00190680 | `EmpireHUD::UpdateFrame` | EmpireHUD.cpp | MISMATCH | 10/57 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 51 bytes; the original is 57 bytes. |
| xb:0x00190890 | `BusinessDetailHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00190A50 | `BusinessHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001918E0 | `HUDSubtitle::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00192420 | `HUDCallout2::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00192910 | `HUDDebugInfo::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00192A60 | `sub_00192A60` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00192AB0 | `EmpireHUD::~EmpireHUD` | EmpireHUD.cpp | VERIFIED | 30/30 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked |
| xb:0x00192DA0 | `DrugWarsHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00193040 | `DrugWarsHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001930C0 | `sub_001930C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00193130 | `HUDElement2::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00193FD0 | `EmpireHUD::OnResetHUD` | EmpireHUD.cpp | MISMATCH | 0/5 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 1 bytes; the original is 5 bytes. |
| xb:0x00193FE0 | `EmpireHUD::SetActiveState` | EmpireHUD.cpp | MISMATCH | 0/107 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 5 bytes; the original is 107 bytes. |
| xb:0x00194050 | `EmpireHUD::OnPageInit` | EmpireHUD.cpp | MISMATCH | 1/23 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 5 bytes; the original is 23 bytes. |
| xb:0x00194100 | `EmpireHUD::GetClassRep` | EmpireHUD.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x00194110 | `ErrorHandlerHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00194CC0 | `HUDImageDisplay::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00194D30 | `LaunderCashHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00195940 | `sub_00195940` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00196EF0 | `HUDManager2::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00197020 | `sub_00197020` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00198BA0 | `HUDMeterWithIcon::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00199370 | `HUDBalls::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00199510 | `HUDHeatMeter::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00199520 | `HUDHeatMeter::vfunc_29` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019A130 | `HUDHealth::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019A4E0 | `HUDBalls::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019A630 | `HUDVisibilityRate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019A6A0 | `HUDHeatMeter::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019A6F0 | `HUDFrontMeter::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019A700 | `HUDNPCHealthRestoreData::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019A7D0 | `HUDNPCHealthMeter::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019ADC0 | `HUDHealth::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019B800 | `MissionCompleteHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019B810 | `MissionCompleteHUD::vfunc_41` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019C780 | `MissionCompleteHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019D3D0 | `NISSequencePlayAction::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019DAD0 | `RepGainHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019E0E0 | `RepGainHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0019F050 | `HUDLoadingScreen::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0019FCE0 | `HUDScreenFX::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A01F0 | `HUDScreenFX::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A1E70 | `HUDTapePlayer::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A1E90 | `HUDTapePlayer::vfunc_63` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A20A0 | `HUDTapePlayer::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A2540 | `HUDTimerRestoreData::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A25E0 | `HUDTimer::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A29F0 | `HUDTimer::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A2A60 | `HUDTrackable::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A31F0 | `HUDCashReadout::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A3230 | `HUDDrugsReadout::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A3240 | `HUDMissionReadoutRestoreData::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A32C0 | `HUDMissionReadout::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A32D0 | `HUDTrackable::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A3760 | `VehicleSelectionHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A37A0 | `IntimidationHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A37B0 | `IntimidationHUD::vfunc_41` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A37E0 | `IntimidationHUD::vfunc_47` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A4190 | `IntimidationHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A5030 | `InvSelectionHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A5040 | `sub_001A5040` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A53F0 | `sub_001A53F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A5980 | `LockerWeaponHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A5AF0 | `HUDMap2RestoreData::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A5EC0 | `MapHUD2::vfunc_30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A64F0 | `MapHUD2::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001A6F50 | `MapHUD2::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001A8A70 | `sub_001A8A70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001AA980 | `GOPoint::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001AC080 | `PromptHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001ACDB0 | `sub_001ACDB0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001ACDF0 | `MiniHUDElement::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001ACE40 | `MiniHUDElement::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001ACE70 | `MissionFailHUD::vfunc_46` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001ACF30 | `MissionFailHUD::UpdateFrame` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x001AD250 | `MissionFailHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001AD660 | `MissionHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001AE620 | `GenericMenuItem::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001B06F0 | `DrugWarsHUD::DrugWarsHUDFrontMenuItem::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001B2FC0 | `LookTutorialHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001B34F0 | `EmpireHUD::OnCloseModal` | EmpireHUD.cpp | MISMATCH | 24/174 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | +0x54: '??3@YAXPAX@Z' is used for two different original addresses; +0x86: '?ConEvaluate@RadicalEngine@@YAPBDPBDH0HH@Z' is used for two diff |
| xb:0x001B47B0 | `LookTutorialRestoreData::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001B4880 | `LookTutorialHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001B5450 | `InvSelectionHUD::InvMenuItem::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001BAEA0 | `PimpYourMansionHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001BAF20 | `PimpYourMansionHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001BB070 | `PokerHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001BBDE0 | `PokerHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001BC640 | `SatPhoneWeaponHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001BC910 | `ConcreteClassRep<BusinessDetailHUD>::CreateFromPool` | EmpireSubHUDs.cpp | MISMATCH | 14/45 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | +0x11: '__except_list' is used for two different original addresses; +0x43: relocation outside the original function; +0x4A: relocation outs |
| xb:0x001BCD90 | `ConcreteClassRep<DrugWarsHUD>::CreateFromPool` | EmpireSubHUDs.cpp | MISMATCH | 15/45 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | +0x11: '__except_list' is used for two different original addresses; +0x45: relocation outside the original function; +0x51: relocation outs |
| xb:0x001BD0A0 | `ConcreteClassRep<ExoticsHUD2>::CreateFromPool` | EmpireSubHUDs.cpp | MISMATCH | 15/45 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | +0x11: '__except_list' is used for two different original addresses; +0x45: relocation outside the original function; +0x51: relocation outs |
| xb:0x001BD240 | `ConcreteClassRep<EmpireHUD>::CreateFromPool` | EmpireHUD.cpp | MISMATCH | 9/45 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 40 bytes; the original is 45 bytes. |
| xb:0x001BE5F0 | `sub_001BE5F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001BF110 | `sub_001BF110` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 2/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2/3 bytes |
| xb:0x001BF190 | `sub_001BF190` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 2/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2/3 bytes |
| xb:0x001BFEA0 | `SlotMachineHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001BFEB0 | `BlackjackHUD::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C0690 | `StreetWeaponHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C07E0 | `TargetHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C1BA0 | `TeleportHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C1BB0 | `GenericWeaponHUD::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C21E0 | `ViceCopHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C23B0 | `ViceCopHUD::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C2410 | `VisibilityHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C26E0 | `HUDVisibilityRestoreData::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C27B0 | `DistanceBubble::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C2A10 | `WeaponHUD::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C3490 | `sub_001C3490` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C3610 | `sub_001C3610` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C3DD0 | `SystemDialogBox::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C48E0 | `BehaviourAnimPulse::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C49A0 | `sub_001C49A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C4AB0 | `core::File::vfunc_24` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C5780 | `LoadObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C57C0 | `LoadObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C5D30 | `LoadPackage::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C64B0 | `LoadPackage::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C6A10 | `sub_001C6A10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8130 | `MissionGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C8140 | `sub_001C8140` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8150 | `MissionGroup::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8240 | `MissionStage::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C8800 | `audio::MixerMix::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8810 | `sub_001C8810` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8C00 | `EnvironmentObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001C8C10 | `sub_001C8C10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8C20 | `sub_001C8C20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8C30 | `EnvironmentObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001C8DF0 | `OceanObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CA050 | `sub_001CA050` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CA580 | `PauseMenu::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CA660 | `PauseMenu::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001CA6D0 | `PauseMenuPage::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CABC0 | `PauseMenuPage::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001CAC10 | `PauseMenuPageController::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CB0A0 | `PauseMenuPageCredits::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CB460 | `PauseMenuPageDebug::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CB7E0 | `PauseMenuPageHome::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CBD20 | `PauseMenuPageMain::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CC240 | `PauseMenuPageOptions::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CC770 | `PauseMenuPageRewards::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CD4B0 | `PauseMenuPageSerialize::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CDC80 | `PauseMenuPageStats::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CEEC0 | `ShaftAndDiscMarker::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001CEED0 | `PoiMarkerObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001CEEF0 | `PoiMarkerManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001CF120 | `EffectsObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D04D0 | `InstanceObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D1060 | `InstanceObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D12D0 | `sub_001D12D0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D1FE0 | `LightingObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D1FF0 | `LightingObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D20E0 | `ParticleEffectObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D2210 | `ParticleEffectObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D22A0 | `RainObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D24F0 | `ShadowObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D25F0 | `ShadowObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D35A0 | `sub_001D35A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D35B0 | `sub_001D35B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D3800 | `sub_001D3800` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D38A0 | `TODObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D3940 | `sub_001D3940` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D3C40 | `TraceFireObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D3C90 | `sub_001D3C90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D3CA0 | `sub_001D3CA0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D3CB0 | `sub_001D3CB0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D3CD0 | `sub_001D3CD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D3E60 | `TraceFireObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D5170 | `VehicleRenderableObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D5250 | `VehicleRenderableObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D54F0 | `SkyObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D55C0 | `SkyObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D55F0 | `sub_001D55F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D6510 | `LocatableSoundObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D6520 | `LocatableSoundObject::vfunc_41` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D6680 | `LocatableSoundObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D6C60 | `LocatableSoundTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D6CC0 | `sub_001D6CC0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D6CD0 | `sub_001D6CD0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D6CE0 | `sub_001D6CE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D76E0 | `sub_001D76E0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D7720 | `sub_001D7720` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D7890 | `TapeTrackLibrary::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D78D0 | `TapeTrackLibrary[+64]::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D78E0 | `TapeTrackLibrary[+64]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D7BE0 | `SoundLocationObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D7C80 | `SoundLocationObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D7D10 | `SoundPoiObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D7FD0 | `SoundPoiTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D8030 | `TapeTrack::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D8090 | `TapeMixTape::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D8150 | `TapePlayer::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D8250 | `TapeMixTape[+32]::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D8260 | `TapeTrack::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D8640 | `ZoneSoundObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D86C0 | `AddressSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D8780 | `AddressSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D8C30 | `AmbientSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D8C40 | `AmbientSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001D8FA0 | `CallForVehicleSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001D9B40 | `CharacterInVehicleSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DA130 | `CopSpawnObject::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001DA470 | `CopSpawnObject::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DA510 | `sub_001DA510` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DAE20 | `CopSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DE0E0 | `GameMemorySegmentCollection::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001DEA80 | `DealerSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DF190 | `EnemyCharacterGeneratorSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DF1A0 | `EnemyCharacterGeneratorSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001DF360 | `EnemyVehicleGenerator::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DF3B0 | `EnemyVehicleGenerator::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001DFC30 | `GangNestSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001DFC40 | `GangNestSpawnObject::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001DFCC0 | `GangNestSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E0120 | `GangSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E01C0 | `sub_001E01C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E0B20 | `pure3d::d3dTexture::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E0B30 | `sub_001E0B30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E0B60 | `sub_001E0B60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E0B70 | `FightTree::fight::VEnterExitScriptTrack::?$FightActionController::vfunc_31` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E2800 | `GenericSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E3410 | `NestSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E34B0 | `sub_001E34B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E35B0 | `PersistentSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E35C0 | `PersistentSpawnObject::vfunc_43` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E3610 | `PersistentVehicleSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E36B0 | `GenericSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E3850 | `PersistentVehicleSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E3A80 | `PickupSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E44B0 | `PropSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E4A00 | `PropSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E4AC0 | `RaceSpawner::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E4B60 | `RaceSpawner::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E50D0 | `ResourceLoader::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E5250 | `ResourceLoader::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E5300 | `ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001E5640 | `ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E82D0 | `sub_001E82D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001E82F0 | `sub_001E82F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EA050 | `sub_001EA050` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EA4E0 | `SpawnTemplateGroup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EA5A0 | `SpawnTriggerObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EA730 | `sub_001EA730` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EA800 | `TriggeredSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EA880 | `sub_001EA880` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EA8B0 | `TriggeredSpawnObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EAE90 | `VehicleSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EAEA0 | `VehicleSpawnObject::vfunc_43` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EAFD0 | `WorldAmbienceSpawnObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EBA10 | `ExplosionObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EBB80 | `ExplosionObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EBD20 | `GameObjectMover::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EC630 | `MeleeWeaponStateProp::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EC680 | `MeleeWeaponStateProp::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EC7C0 | `MortarObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001ED590 | `M16MortarWeaponStateProp::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EECB0 | `StatePropBehaviourTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EECE0 | `StatePropAttachmentObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001EEF60 | `MeleeWeaponStateProp[+168]::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EF220 | `sub_001EF220` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001EF240 | `sub_001EF240` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F1FE0 | `StatePropDragBehaviour::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F2030 | `StatePropWaterCollisionTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F2070 | `StatePropDragTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F20E0 | `StatePropSnapToWaterBehaviour::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F2140 | `StatePropSnapToWaterTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F21C0 | `StatePropWaterCollisionBehaviour::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F21F0 | `StatePropWaterCollisionTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F22F0 | `StatePropDragTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F2320 | `StatePropSnapToWaterTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F27C0 | `VehicleWeaponStateProp::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F27D0 | `ShotgunWeaponStateProp::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F27E0 | `M16MortarWeaponStateProp::vfunc_72` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F27F0 | `VehicleWeaponStateProp::vfunc_73` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F28E0 | `WeaponPickup::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F28F0 | `StatePropObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F29A0 | `sub_001F29A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F2B00 | `sub_001F2B00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F2B90 | `MeleeWeaponStateProp::IsIntact` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F2BD0 | `sub_001F2BD0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F2BE0 | `MountedWeaponStateProp::vfunc_32` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F2BF0 | `sub_001F2BF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F3580 | `MountedWeaponStateProp::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F4AE0 | `MountedWeaponStateProp::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F4CB0 | `sub_001F4CB0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F6240 | `Targeting::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F62C0 | `sub_001F62C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F62D0 | `sub_001F62D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F62E0 | `sub_001F62E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F62F0 | `Targeting::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001F8560 | `TargetingHUDUpdater::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001F8B30 | `TargetingHUDUpdater::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001FAE70 | `CharacterTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FAF00 | `CharacterTunablesObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FB160 | `MainCharacterTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FB1E0 | `CharacterFightTreeTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FB1F0 | `CharacterFightTreeTemplate::vfunc_11` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x001FB230 | `CharacterDynamicAnimationTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FB4F0 | `CharacterSpeedsObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FB720 | `EffectsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FBAD0 | `ExplosionTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FBEE0 | `LightingTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FBF60 | `MortarTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FC090 | `MortarTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x001FC100 | `ParticleEffectTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FC190 | `SkidmarkTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FC2A0 | `RainTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FECF0 | `SkyTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FED40 | `SpeedDataTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FED90 | `TraceFireTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FEE30 | `TrapezoidTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FEEC0 | `sub_001FEEC0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FEF40 | `VibeTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FF3B0 | `WakeTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FF470 | `WeaponDecalTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x001FFC80 | `WeaponTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200000 | `OceanTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200050 | `OceanTuningTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200340 | `AirplaneArtTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200350 | `AirplaneArtTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002006F0 | `AirplaneTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200730 | `AirplaneTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002008B0 | `VehicleDropObjectProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200AE0 | `BoatAITuneablesTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200AF0 | `BoatAITuneablesTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00200BF0 | `BoatArtTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200C20 | `BoatArtTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00200D00 | `RandomWaterObjectTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200E00 | `BoatPhysicsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200E40 | `BoatPitchClampProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00200E70 | `BoatPhysicsTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002012F0 | `BoatTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00201440 | `BoatTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00201670 | `BoatEnginePivotProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002016C0 | `BoatDamageProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002016D0 | `BoatDamageProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00201750 | `HelicopterArtTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00201760 | `HelicopterArtTemplate::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00201770 | `HelicopterArtTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002017F0 | `HelicopterPhysicsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00201830 | `HelicopterPhysicsTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00201890 | `HelicopterTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002018A0 | `HelicopterTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020BE00 | `FourWheelerPhysicsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020BE30 | `$03::?$ConcreteWheeledVehiclePhysicsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020C440 | `FEGroupObject::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020C480 | `VehicleAITuneablesTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020C4E0 | `VehicleShaderProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020C520 | `VehicleTargetingLocatorProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020C560 | `VehicleArtTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020C710 | `VehicleTargetingLocatorProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020CA50 | `HelicopterArtTemplate::vfunc_10` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x0020CA60 | `AirplaneArtTemplate::vfunc_11` | StarterBatch1_25Functions.cpp | VERIFIED | 14/14 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked |
| xb:0x0020CAC0 | `VehicleDamageTransmitProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CB00 | `VehicleDamagePropagationProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CB60 | `VehicleBehaviourTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CBB0 | `VehicleCharacterEntryTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CC20 | `Template::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020CC80 | `VehicleMaterialProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CCE0 | `VehicleSimpleThrustProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CD40 | `VehicleDestroyPhysicsProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CD80 | `VehicleSuspensionProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CDF0 | `VehicleSinkingProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020CE20 | `VehicleMaterialProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020CE50 | `VehicleSimpleThrustProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020CE80 | `VehicleDestroyPhysicsProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020D110 | `VehiclePhysicsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D1C0 | `VehicleInterpolatedFeedbackProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D260 | `VehicleInWaterProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D2C0 | `VehiclePropellerTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D350 | `AirplaneControlFeedbackTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D3E0 | `VehicleFlappingPhysicsProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D410 | `VehicleFlappingCategoryProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D420 | `VehicleFlappingJointProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D460 | `VehicleRenderMaskTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D4C0 | `VehicleSirenTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D560 | `VehicleMountedWeaponTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D5C0 | `VehicleFixedWeaponTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D620 | `VehicleZoneDamageProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D650 | `VehicleZoneDamagePropertiesCollection::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D660 | `VehicleZonePhysicsProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D670 | `VehicleZoneProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D680 | `VehicleZoneMeshProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D690 | `VehicleZoneEffectProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020D7D0 | `AirplaneControlFeedbackTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020D890 | `VehicleFlappingPhysicsProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020D8C0 | `VehicleFlappingCategoryProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020D970 | `VehicleFlappingJointProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020DAC0 | `VehicleRenderMaskTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020DBF0 | `VehicleMountedWeaponTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020DD60 | `VehicleFixedWeaponTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020DF20 | `VehicleZoneDamageProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020DF50 | `VehicleZoneDamagePropertiesCollection::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020DFD0 | `VehicleZonePhysicsProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020E580 | `VehicleZoneEffectProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020EA20 | `BoatZoneProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EA80 | `AirplaneZoneProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020ED70 | `VehicleControllerTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EDA0 | `VehicleTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EDF0 | `VehicleDamageProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EE30 | `VehicleParticleTriggerProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EE60 | `VehicleDamageEffectProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EEA0 | `VehicleKamikazeProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EF00 | `VehicleDamageScaleProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EF60 | `VehicleCollisionImpulseScaleProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EF90 | `VehicleCollisionResponseProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EFA0 | `VehicleWaterSprayProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EFB0 | `VehicleExhaustProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020EFC0 | `VehicleSeveredPartEffectProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020F000 | `VehicleDirtAccumulationProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020F030 | `VehicleCameraProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020F1A0 | `VehicleCameraCategoryProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020F1F0 | `VehicleLightsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0020F200 | `VehicleControllerTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F370 | `VehicleParticleTriggerProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F3D0 | `VehicleKamikazeProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F400 | `VehicleDamageScaleProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F430 | `VehicleCollisionImpulseScaleProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F460 | `VehicleCollisionResponseProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F490 | `VehicleWaterSprayProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F4C0 | `VehicleExhaustProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F4F0 | `VehicleSeveredPartEffectProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F520 | `VehicleDirtAccumulationProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F550 | `VehicleCameraProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0020F580 | `VehicleCameraCategoryProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00210FC0 | `WheeledVehicleArtTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002111B0 | `WheelPlayerControlProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00211210 | `WheeledVehicleCrashedPhysicsProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00211220 | `WheeledVehiclePhysicsTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00211620 | `WheelDamageProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00211650 | `WheeledVehicleDamageProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002116D0 | `WheeledVehicleCoverProperties::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002116E0 | `WheeledVehicleTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00211730 | `WheeledVehicleLightsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00211740 | `WheeledVehicleDamageProperties::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00211770 | `ScriptObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00211790 | `WheeledVehicleTemplate::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00212040 | `StatePropPhysicsTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002120E0 | `StatePropTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00212200 | `EffectCollectionTemplate::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002126B0 | `TimerObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002126C0 | `TimerObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00212720 | `RoomTriggerObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00212C10 | `MissionTriggerObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00212C20 | `MissionTriggerObject::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00212C30 | `MissionTriggerObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00212E70 | `TriggerVolumeObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00213250 | `LOSTriggerVolumeObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00213410 | `LOSTriggerVolumeObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00213430 | `FlowClient::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00213530 | `AirplaneObject::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00213570 | `AirplaneObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00213690 | `AirplaneObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00213AA0 | `WheeledVehicleObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00213DB0 | `WheeledVehicleObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00213F50 | `ActiveWheeledVehicleObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00214B60 | `ActiveBoatObject::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00214C30 | `sub_00214C30` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 2/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2/3 bytes |
| xb:0x00214C90 | `BoatObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00214E00 | `BoatObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002157C0 | `HelicopterObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00215990 | `HelicopterObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00217B70 | `sub_00217B70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021A600 | `VehicleObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021AA20 | `ActiveVehicleObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021ADB0 | `VehicleObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C1B0 | `TrafficCar::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021C1C0 | `TrafficCar::vfunc_64` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C1D0 | `CubeVan::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021C1E0 | `sub_0021C1E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C1F0 | `sub_0021C1F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C260 | `ScriptCar::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021C270 | `TrafficCar::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C360 | `CubeVan::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C4C0 | `ScriptCar::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C550 | `BoatDrivingRewardsObject::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C690 | `DrivingRewardsObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021C710 | `BoatDrivingRewardsObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021C800 | `CarDrivingRewardsObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021C8D0 | `BoatDrivingRewardsObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021C8F0 | `CarDrivingRewardsObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021D450 | `LightsVolumeObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021D780 | `WakeObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021D790 | `WakeObject::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021D8F0 | `AddressManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021D900 | `sub_0021D900` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021DC90 | `AddressManager::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0021F410 | `AddressObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021F6B0 | `sub_0021F6B0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021F6C0 | `sub_0021F6C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021F870 | `sub_0021F870` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021F910 | `sub_0021F910` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021F920 | `sub_0021F920` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021F980 | `sub_0021F980` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021FA30 | `sub_0021FA30` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021FB70 | `sub_0021FB70` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021FBC0 | `sub_0021FBC0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0021FC40 | `sub_0021FC40` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00220050 | `sub_00220050` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00222930 | `sub_00222930` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222960 | `sub_00222960` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222970 | `sub_00222970` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222980 | `sub_00222980` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222A90 | `sub_00222A90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222AC0 | `sub_00222AC0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222AF0 | `sub_00222AF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222B20 | `sub_00222B20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222C00 | `sub_00222C00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222D10 | `sub_00222D10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222E30 | `sub_00222E30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00222E70 | `sub_00222E70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00223080 | `TurfTriggerObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00223330 | `VisibilityTriggerObject::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00223780 | `sub_00223780` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00223C10 | `sub_00223C10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00223CB0 | `AIManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00223D20 | `sub_00223D20` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00223D60 | `sub_00223D60` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00223FA0 | `sub_00223FA0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00224070 | `sub_00224070` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002240E0 | `sub_002240E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002243F0 | `sub_002243F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00224570 | `sub_00224570` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 1/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | Compiled function is 6 bytes; the original is 3 bytes. |
| xb:0x00228D60 | `CVManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0022B410 | `sub_0022B410` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0022BCD0 | `GameObjectManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0022BE30 | `sub_0022BE30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0022C920 | `sub_0022C920` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0022D6F0 | `sub_0022D6F0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0022D880 | `sub_0022D880` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0022E240 | `PresentationState::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00230060 | `PresentationManager::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00230460 | `PresentationManager::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002304E0 | `sub_002304E0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00230520 | `sub_00230520` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002307A0 | `sub_002307A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00239CB0 | `fight::VTimedFightTrack::?$ParamFloatConstRange::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00239EC0 | `CollisionBehaviourTypeGroup::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0023CA90 | `sub_0023CA90` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0023E740 | `sub_0023E740` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0023EA70 | `sub_0023EA70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0023F760 | `sub_0023F760` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0023F7A0 | `sub_0023F7A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00240880 | `sub_00240880` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00240C70 | `sub_00240C70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00240C80 | `sub_00240C80` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00240C90 | `sub_00240C90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00244040 | `sub_00244040` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00244410 | `sub_00244410` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00245D00 | `sub_00245D00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00246630 | `sub_00246630` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00247970 | `sub_00247970` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00247C10 | `core::ControllerXBox::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00247C20 | `core::ControllerXBox::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00247F50 | `core::ControllerXBox::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00247FA0 | `core::ControllerXBox::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00247FC0 | `core::ControllerOutputPointXBox::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00248800 | `sub_00248800` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00248990 | `pure3d::frontend::Drawable::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002489B0 | `sub_002489B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00249110 | `sub_00249110` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00249DF0 | `sub_00249DF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00249E00 | `sub_00249E00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0024E1E0 | `sub_0024E1E0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0024E1F0 | `sub_0024E1F0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0024E3F0 | `sub_0024E3F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0024E400 | `sub_0024E400` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0024E4A0 | `sub_0024E4A0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0024E4B0 | `sub_0024E4B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0024E4C0 | `sub_0024E4C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00250EB0 | `sub_00250EB0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00251180 | `sub_00251180` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00251190 | `sub_00251190` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002511A0 | `sub_002511A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002511B0 | `sub_002511B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002511C0 | `sub_002511C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002511D0 | `sub_002511D0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002511E0 | `sub_002511E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002511F0 | `sub_002511F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00251200 | `sub_00251200` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00251210 | `sub_00251210` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00251350 | `sub_00251350` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00251760 | `core::MemoryPool::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00253080 | `sub_00253080` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00253090 | `pure3d::AnimationFrameController::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00254E10 | `sub_00254E10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00255790 | `sub_00255790` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00255B00 | `sub_00255B00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00255BB0 | `sub_00255BB0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002565B0 | `sub_002565B0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002565C0 | `pure3d::xboxOceanRenderer::vfunc_11` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025D0D0 | `pure3d::d3dDevice::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025D830 | `pure3d::ParticleEmitter::vfunc_26` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025D860 | `pure3d::ParticleEmitter::vfunc_30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025D870 | `pure3d::ParticleEmitter::vfunc_32` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025D880 | `pure3d::ParticleEmitter::vfunc_34` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025D890 | `pure3d::ParticleEmitter::vfunc_36` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025D8A0 | `pure3d::ParticleEmitter::vfunc_38` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025DD00 | `pure3d::SpriteParticleEmitter::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025DE30 | `pure3d::SpriteParticleEmitter::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025DE60 | `pure3d::SpriteParticleEmitter::vfunc_27` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025FE00 | `pure3d::TextureBuilder::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025FE10 | `WheelCollisionCalculator::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025FE20 | `sub_0025FE20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025FE30 | `sub_0025FE30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0025FE60 | `sub_0025FE60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00262970 | `pure3d::PNGHandler::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00262980 | `pure3d::RawImageHandler::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00262990 | `pure3d::DXTNHandler::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00263030 | `pure3d::Image8::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00263040 | `pure3d::Image8::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00263240 | `pure3d::Image8::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00263FD0 | `pure3d::d3dExtTODFactor::vfunc_14` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 7/7 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00264350 | `pure3d::d3dExtFramebufferEffects::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00264360 | `pure3d::d3dExtFramebufferEffects::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00264390 | `pure3d::d3dExtFramebufferEffects::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00264670 | `pure3d::d3dExtFramebufferEffects::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00265340 | `pure3d::d3dContext::vfunc_103` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00265C90 | `pure3d::d3dContext::vfunc_112` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002660A0 | `pure3d::d3dContext::vfunc_96` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00267FB0 | `pure3d::d3dExtHardwareSkinning::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002680D0 | `pure3d::d3dExtVisibilityTest::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002680E0 | `pure3d::d3dExtVisibilityTest::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002681A0 | `pure3d::d3dExtVisibilityTest::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00269CD0 | `pure3d::d3dContext::vfunc_93` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0026CF70 | `sub_0026CF70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0026CF80 | `pure3d::Sprite::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0026CFC0 | `sub_0026CFC0` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 2/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2/3 bytes |
| xb:0x0026D450 | `GangSpawnObject::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0026D930 | `DealerSpawnObject::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0026DB10 | `pure3d::SpriteObject::vfunc_30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0026DB20 | `pure3d::SpriteObject::vfunc_31` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0026DB30 | `pure3d::SpriteLoader::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0026DB40 | `NISCharacterAnimationAction::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00271A00 | `pure3d::pure3d::USpriteParticle::?$ParticleAllocatorTemplate::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00272260 | `pure3d::MultiController::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00272270 | `TimedFightTrack::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00272280 | `TimedFightTrack::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00272290 | `pure3d::MultiController::vfunc_13` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002722C0 | `pure3d::MultiController::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00272310 | `pure3d::MultiController::vfunc_23` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00273200 | `sub_00273200` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002762C0 | `pure3d::CompositeDrawable::vfunc_13` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00277C40 | `pure3d::PolySkin::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00277C50 | `pure3d::PolySkin::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0027A200 | `FourWheelerPhysicsTemplate[+796]::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0027C230 | `sub_0027C230` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 2/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2/3 bytes |
| xb:0x0027CDB0 | `pure3d::ImageFont::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0027FE30 | `pure3d::Geometry::vfunc_21` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0027FE40 | `pure3d::Geometry::vfunc_22` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002829C0 | `pure3d::d3dVehicleShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00282A10 | `pure3d::d3dVehicleShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00282A20 | `pure3d::d3dVehicleShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00282A30 | `pure3d::d3dVehicleShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00282A40 | `pure3d::d3dVehicleShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00282BF0 | `sub_00282BF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00282C00 | `sub_00282C00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00283A70 | `sub_00283A70` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00283A80 | `sub_00283A80` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00283A90 | `sub_00283A90` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00285180 | `pure3d::CharacterAnimationLayer::vfunc_11` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00285DE0 | `sub_00285DE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002870F0 | `pure3d::IntChannel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002871F0 | `pure3d::Float1Channel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002874F0 | `pure3d::Float2Channel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002875D0 | `pure3d::VectorChannel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00287A70 | `pure3d::RotationChannel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00287CC0 | `pure3d::StringChannel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00287CD0 | `pure3d::EntityChannel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00287D10 | `pure3d::BoolChannel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00287D70 | `pure3d::ColourChannel::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0028D0F0 | `core::MemoryAllocatorMalloc::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0028D100 | `core::MemoryAllocatorMalloc::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0028FD00 | `core::MemoryDlAllocator::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00291560 | `sub_00291560` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00291CF0 | `pure3d::ParticleController::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00291D00 | `pure3d::ParticleController::vfunc_13` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002925C0 | `pure3d::PolySkin::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002925D0 | `pure3d::PolySkin::vfunc_20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002929C0 | `pure3d::PrimGroup::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00292A00 | `sub_00292A00` | imported/stage0_full_xbe_sweep.cpp | MISMATCH | 2/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2/3 bytes |
| xb:0x00292A40 | `pure3d::PrimGroupStreamed::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00292B80 | `pure3d::PrimGroupSkinnedStreamed::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00292BD0 | `CallForVehicleSpawnObject::vfunc_45` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00292BF0 | `sub_00292BF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002957F0 | `pure3d::SpriteParticleEmitter::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00296DB0 | `pure3d::xboxOceanRenderer::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00296DC0 | `pure3d::xboxOceanRenderer::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00298410 | `sub_00298410` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00298420 | `sub_00298420` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002994D0 | `pure3d::pddiTexture::vfunc_20` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x00299760 | `pure3d::d3dTexture::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00299770 | `pure3d::d3dTexture::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00299780 | `pure3d::d3dTexture::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00299790 | `pure3d::d3dTexture::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002997A0 | `pure3d::d3dTexture::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x00299DB0 | `pure3d::d3dTexture::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029A000 | `pure3d::d3dTexture::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029A1F0 | `sub_0029A1F0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029A220 | `sub_0029A220` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029A2E0 | `pure3d::d3dShader::vfunc_23` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029A9C0 | `pure3d::d3dDisplay::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029A9D0 | `pure3d::d3dDisplay::vfunc_09` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029A9E0 | `pure3d::d3dDisplay::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029A9F0 | `pure3d::d3dDisplay::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029AA00 | `pure3d::d3dDisplay::vfunc_13` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029AAE0 | `sub_0029AAE0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029AB80 | `pure3d::d3dDisplay::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029AEF0 | `pure3d::d3dDisplay::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029AF00 | `pure3d::d3dDisplay::vfunc_19` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029BA60 | `sub_0029BA60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029BAB0 | `sub_0029BAB0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029D5D0 | `pure3d::d3dContext::vfunc_13` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029D770 | `pure3d::d3dContext::vfunc_114` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029D7F0 | `pure3d::d3dContext::vfunc_108` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029D800 | `pure3d::d3dContext::vfunc_109` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029D8F0 | `pure3d::d3dContext::vfunc_37` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029DA50 | `sub_0029DA50` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029E4E0 | `pure3d::d3dContext::vfunc_92` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029E530 | `pure3d::d3dContext::vfunc_97` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029E540 | `pure3d::d3dContext::vfunc_98` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029F440 | `pure3d::d3dFBEffectsShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029F450 | `sub_0029F450` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029F460 | `sub_0029F460` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029F470 | `sub_0029F470` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029F480 | `sub_0029F480` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029F490 | `sub_0029F490` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x0029F570 | `pure3d::d3dFBEffectsShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029F580 | `pure3d::d3dFBEffectsShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029F590 | `pure3d::d3dFBEffectsShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029F700 | `pure3d::d3dSimpleShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029F710 | `pure3d::d3dSimpleShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029F720 | `pure3d::d3dSimpleShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x0029F730 | `pure3d::d3dSimpleShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002A06C0 | `sub_002A06C0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A1080 | `pure3d::d3dExtXboxControl::vfunc_49` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A1770 | `pure3d::d3dExtDepthOfField::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A2B30 | `pure3d::d3dExtStaticShadowGen::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A3B40 | `pure3d::d3dExtStaticShadowGen::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A3B50 | `pure3d::d3dExtStaticShadowGen::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A5200 | `FightTree::fight::VEnterExitScriptTrack::?$FightActionController::vfunc_25` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A6940 | `sub_002A6940` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002A9290 | `CollisionBehaviourTypeGroup::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002A98D0 | `core::CompletionEventRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002A9970 | `core::DriveCompletionRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002A99C0 | `core::FileRequest::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AA050 | `core::FileGetPositionRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA150 | `core::DriveOpenRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA1B0 | `core::DriveMediaRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA250 | `core::DriveCreateDirectoryRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA2B0 | `core::DriveDestroyDirectoryRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA3C0 | `core::DriveFindCloseRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA420 | `core::DriveFileDestroyRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA470 | `core::DriveCancelRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AA480 | `core::DriveLockRequest::vfunc_06` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002AB360 | `core::File::vfunc_26` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AB370 | `core::File::vfunc_30` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AB380 | `core::File::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AB390 | `core::File::vfunc_31` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AB3A0 | `core::File::vfunc_32` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AB3B0 | `core::File::vfunc_33` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AB790 | `core::InstanceDrive::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC080 | `core::File::vfunc_27` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC090 | `core::InstanceDrive::vfunc_48` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC0A0 | `fight::SequenceAction::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC430 | `sub_002AC430` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC670 | `sub_002AC670` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC680 | `sub_002AC680` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC780 | `core::Drive::vfunc_20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AC790 | `core::Drive::vfunc_22` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002AD8C0 | `pure3d::d3dPrimBufferStream::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002ADC40 | `pure3d::d3dPrimBufferStream::vfunc_24` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002B8650 | `sub_002B8650` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002BEBB0 | `core::XboxDrive::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002BEBC0 | `core::XboxDrive::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002BF820 | `pure3d::d3dTexture::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002BF830 | `core::XboxSaveDrive::vfunc_05` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002BF880 | `core::XboxSaveDrive[+220]::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002BF890 | `core::XboxSaveDrive[+220]::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002C1C10 | `pure3d::d3dErrorShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C1EB0 | `pure3d::d3dReflShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C1EC0 | `pure3d::d3dReflShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C1ED0 | `pure3d::d3dReflShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C1EE0 | `pure3d::d3dReflShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C1EF0 | `pure3d::d3dReflShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C23F0 | `pure3d::d3dLayeredShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C2400 | `pure3d::d3dLayeredShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C2410 | `pure3d::d3dLayeredShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C2420 | `pure3d::d3dLayeredShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C2430 | `pure3d::d3dLayeredShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3000 | `pure3d::d3dSpecularShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3030 | `pure3d::d3dSpecularShader::vfunc_23` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C34C0 | `pure3d::d3dSpecularShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C34D0 | `pure3d::d3dSpecularShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C34E0 | `pure3d::d3dSpecularShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C34F0 | `pure3d::d3dSpecularShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3C30 | `pure3d::d3dShadowShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3C40 | `pure3d::d3dShadowShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3C50 | `pure3d::d3dShadowShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3C60 | `pure3d::d3dShadowShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3C70 | `pure3d::d3dShadowShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3E30 | `pure3d::d3dSimpleCBVLitShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3E40 | `pure3d::d3dSimpleCBVLitShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3E50 | `pure3d::d3dSimpleCBVLitShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3E60 | `pure3d::d3dSimpleCBVLitShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C3E70 | `pure3d::d3dSimpleCBVLitShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C4910 | `pure3d::d3dCharacterShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C4920 | `pure3d::d3dCharacterShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C4930 | `pure3d::d3dCharacterShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C4940 | `pure3d::d3dCharacterShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C4950 | `pure3d::d3dCharacterShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5400 | `pure3d::d3dShadowDecalShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5410 | `pure3d::d3dShadowDecalShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5420 | `pure3d::d3dShadowDecalShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5430 | `pure3d::d3dShadowDecalShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5440 | `pure3d::d3dShadowDecalShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5660 | `pure3d::d3dDecalShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C57A0 | `pure3d::d3dVertexFadeShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C57B0 | `pure3d::d3dVertexFadeShader::vfunc_23` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5C10 | `pure3d::d3dVertexFadeShader::vfunc_15` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5C20 | `pure3d::d3dVertexFadeShader::vfunc_16` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5C30 | `pure3d::d3dVertexFadeShader::vfunc_17` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C5C40 | `pure3d::d3dVertexFadeShader::vfunc_18` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C6140 | `pure3d::d3dNightlightShader::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002C6320 | `pure3d::d3dNightlightShader::vfunc_23` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002CC090 | `sub_002CC090` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002CE2A0 | `sub_002CE2A0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002CE340 | `sub_002CE340` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002CF100 | `GlobalVehicleSound::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002CFA10 | `sub_002CFA10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002CFB30 | `audio::Sequence::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D0240 | `sub_002D0240` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D05C0 | `sub_002D05C0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D0AF0 | `sub_002D0AF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D0DD0 | `sub_002D0DD0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D0EA0 | `om::audio::VSeqEvent::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D0ED0 | `om::audio::VMix::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D0F00 | `om::audio::VClip::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D0F30 | `om::audio::VSequence::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D0FD0 | `om::audio::VMix::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D0FE0 | `om::audio::VMix::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D1090 | `om::audio::VClip::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D10A0 | `om::audio::VClip::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D1100 | `audio::Clip::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D11C0 | `om::audio::VSequence::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D11D0 | `om::audio::VSequence::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D1670 | `sub_002D1670` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D1CC0 | `om::audio::VLayerTemplate::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D1D90 | `audio::LayerTemplate::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D1E50 | `om::audio::VLayerTemplate::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D1E60 | `om::audio::VLayerTemplate::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D2C30 | `sub_002D2C30` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D57B0 | `sub_002D57B0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D5920 | `AnimationRetargetingAction::vfunc_14` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D5930 | `fight::VTimedFightTrack::?$ParamFloatConstRange::vfunc_01` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D5940 | `pure3d::d3dContext::vfunc_22` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D64A0 | `pure3d::Image8::vfunc_20` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D6510 | `FETextObject::vfunc_46` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D6850 | `AnimationTrack::vfunc_27` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D69E0 | `sub_002D69E0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D69F0 | `renderer::DecalContainer::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D6B50 | `sub_002D6B50` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D6F70 | `audio::SeqEventContainer::vfunc_04` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D7340 | `audio::Mix::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D7A00 | `audio::WmaDecoderStream::DecodeBuffer::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D7F60 | `sub_002D7F60` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D80D0 | `audio::WmaDecoderStream::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D8160 | `audio::WmaDecoderStream::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D8200 | `sub_002D8200` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 3/3 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D87B0 | `om::audio::VListenerEffectXBox::?$MetaType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D8850 | `om::audio::VListenerEffectXBox::?$EntityType::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D8860 | `om::audio::VListenerEffectXBox::?$EntityType::vfunc_02` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D88B0 | `audio::ListenerEffectXBox::vfunc_12` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D8D80 | `audio::SeqEventNestTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D92D0 | `audio::SeqEventChannelSendVolumes::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D95F0 | `audio::SeqEventChannelSends::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D98F0 | `audio::SeqEventCondition::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D9A80 | `audio::SeqEventConditionElse::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002D9CF0 | `sub_002D9CF0` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002D9D30 | `audio::SeqEventWait::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DA1A0 | `audio::SeqEventWaitBeat::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DA310 | `audio::SeqEventExpression::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DA620 | `audio::SeqEventStopTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DAA20 | `audio::SeqEventPlayTrack::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DAD00 | `audio::SeqEventChannelVolumes::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DB420 | `audio::SeqEventVarVolumeRand::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DB640 | `audio::SeqEventVarVolume::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DB870 | `audio::SeqEventVarTempo::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DBA80 | `audio::SeqEventVarPosDist::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DBC70 | `audio::SeqEventVarPitchRand::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DBE70 | `audio::SeqEventVarPitch::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DBF50 | `audio::audio::VSeqEventNestTrack::?$SeqEventType::vfunc_00` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002DC200 | `audio::SeqEventStream::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DCB50 | `audio::SeqEventSilence::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DCEE0 | `audio::SeqEventLogicRepeat::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DD1D0 | `audio::SeqEventLogicOr::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DD630 | `audio::SeqEventCrossFade::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DDD70 | `audio::SeqEventClip::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002DE790 | `sub_002DE790` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002E0A20 | `audio::HalRadicalAdpcmDecodeStream::vfunc_10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002E2870 | `sub_002E2870` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002E2940 | `sub_002E2940` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002E2950 | `sub_002E2950` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002E2C10 | `sub_002E2C10` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002E4A20 | `ravenphysics::CollisionObject::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002EA6B0 | `ravenphysics::CollisionMesh::SharedData::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002EC080 | `ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_07` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002EC090 | `ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_08` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002ECB50 | `ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_03` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002EE710 | `sub_002EE710` | imported/stage0_full_xbe_sweep.cpp | NO_CODE | 0/0 |  | only a comment; no C++ was written |
| xb:0x002EE720 | `sub_002EE720` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 6/6 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002F0AF0 | `sub_002F0AF0` | imported/stage0_full_xbe_sweep.cpp | VERIFIED | 1/1 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
| xb:0x002FF738 | `exception_xbox::~exception_xbox` | AIAction.cpp | MISMATCH | 5/22 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | +0x16: relocation outside the original function; Compiled function is 28 bytes; the original is 22 bytes. |
| xb:0x002FF74E | `exception_xbox::what` | AIAction.cpp | VERIFIED | 13/13 | /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 |  |
