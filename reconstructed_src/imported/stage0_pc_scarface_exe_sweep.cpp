/*
 * stage0_pc_scarface_exe_sweep.cpp — Direct Plaintext PC `Scarface.exe` Sweep (186 functions)
 * Plus 3 Verified Non-Trivial `core::` PC Methods (`ControllerSystemDirectInput`, `String`, `MemoryDlAllocator`)
 */

// PC VA 0x006DDC80 (7 B) [pc_this_field_getter_7b] ==> core::ControllerDirectInput::vfunc_05
/* PC VA 0x006DDC80: this->field (+0x144) getter */
// PC VA 0x006DDF50 (7 B) [pc_this_field_getter_7b] ==> core::ControllerDirectInput::vfunc_08
/* PC VA 0x006DDF50: this->field (+0x26C) getter */
// PC VA 0x006DDF90 (7 B) [pc_this_field_getter_7b] ==> core::ControllerDirectInput::vfunc_13
/* PC VA 0x006DDF90: this->field (+0x278) getter */
// PC VA 0x006DE1D0 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> core::ControllerDirectInput::vfunc_03
/* PC VA 0x006DE1D0: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006DE5A0 (3 B) [pc_stdcall_ret_n_3b]
/* PC VA 0x006DE5A0: stdcall ret 0x4 */
// PC VA 0x006DE690 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> core::ControllerSystemDirectInput::vfunc_03
/* PC VA 0x006DE690: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006DEDF0 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_006DEDF0(void) {}
// PC VA 0x006DF490 (6 B) [pc_const_or_global_6b]
unsigned int __cdecl pc_sub_006DF490(void) { return 0x0085AEF4; }
// PC VA 0x006DF720 (5 B) [pc_stdcall_const_ret_5b] ==> UpperBodyAnimStateCondition::vfunc_13 (+639 slots)
/* PC VA 0x006DF720: 5B stdcall const return */
// PC VA 0x006DF7E0 (5 B) [pc_stdcall_const_ret_5b] ==> pure3d::pddiDisplay::vfunc_09 (+1 slots)
/* PC VA 0x006DF7E0: 5B stdcall const return */
// PC VA 0x006DF7F0 (6 B) [pc_const_or_global_6b] ==> core::MemoryAllocatorMalloc::vfunc_12 (+1 slots)
unsigned int __cdecl pc_sub_006DF7F0(void) { return 0x0085AF08; }
// PC VA 0x006DF960 (6 B) [pc_const_or_global_6b]
unsigned int __cdecl pc_sub_006DF960(void) { return 0x0085CD34; }
// PC VA 0x006E0540 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> core::String::vfunc_03
/* PC VA 0x006E0540: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006E0A60 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> core::MemoryDlAllocator::vfunc_03
/* PC VA 0x006E0A60: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006E1CF0 (4 B) [pc_this_field_getter_4b] ==> core::MemoryDlAllocator::vfunc_02 (+1 slots)
/* PC VA 0x006E1CF0: this->field (+0x3C) getter */
// PC VA 0x006E1D40 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> core::MemorySmallDlAllocator::vfunc_03
/* PC VA 0x006E1D40: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006E36C0 (6 B) [pc_const_or_global_6b] ==> core::CompletionEventRequest::vfunc_06
unsigned int __cdecl pc_sub_006E36C0(void) { return 0x00000017; }
// PC VA 0x006E3760 (6 B) [pc_const_or_global_6b] ==> core::DriveCompletionRequest::vfunc_06
unsigned int __cdecl pc_sub_006E3760(void) { return 0x00000016; }
// PC VA 0x006E3C20 (6 B) [pc_const_or_global_6b] ==> fight::VUpperBodyAnimStateCondition::?$ParamString::vfunc_01 (+55 slots)
unsigned int __cdecl pc_sub_006E3C20(void) { return 0x00000003; }
// PC VA 0x006E3DD0 (6 B) [pc_const_or_global_6b] ==> fight::VDirectionalGetHitCondition::?$ParamEnumConstList::vfunc_01 (+23 slots)
unsigned int __cdecl pc_sub_006E3DD0(void) { return 0x00000005; }
// PC VA 0x006E3E60 (6 B) [pc_const_or_global_6b] ==> core::FileGetPositionRequest::vfunc_06
unsigned int __cdecl pc_sub_006E3E60(void) { return 0x00000007; }
// PC VA 0x006E3EB0 (6 B) [pc_const_or_global_6b] ==> DealerSpawnObject::vfunc_45 (+6 slots)
unsigned int __cdecl pc_sub_006E3EB0(void) { return 0x00000008; }
// PC VA 0x006E3F00 (6 B) [pc_const_or_global_6b] ==> fight::VExitConditionTrack::?$ParamBranch::vfunc_01 (+4 slots)
unsigned int __cdecl pc_sub_006E3F00(void) { return 0x00000009; }
// PC VA 0x006E3F60 (6 B) [pc_const_or_global_6b] ==> core::DriveOpenRequest::vfunc_06
unsigned int __cdecl pc_sub_006E3F60(void) { return 0x0000000B; }
// PC VA 0x006E3FC0 (6 B) [pc_const_or_global_6b] ==> core::DriveMediaRequest::vfunc_06
unsigned int __cdecl pc_sub_006E3FC0(void) { return 0x0000000C; }
// PC VA 0x006E4010 (6 B) [pc_const_or_global_6b] ==> GlanceAtOvertakingPed::vfunc_10 (+3 slots)
unsigned int __cdecl pc_sub_006E4010(void) { return 0x0000000D; }
// PC VA 0x006E4070 (6 B) [pc_const_or_global_6b] ==> core::DriveCreateDirectoryRequest::vfunc_06
unsigned int __cdecl pc_sub_006E4070(void) { return 0x0000000E; }
// PC VA 0x006E40D0 (6 B) [pc_const_or_global_6b] ==> core::DriveDestroyDirectoryRequest::vfunc_06
unsigned int __cdecl pc_sub_006E40D0(void) { return 0x0000000F; }
// PC VA 0x006E4150 (6 B) [pc_const_or_global_6b] ==> GangSpawnObject::vfunc_45 (+3 slots)
unsigned int __cdecl pc_sub_006E4150(void) { return 0x00000010; }
// PC VA 0x006E41B0 (6 B) [pc_const_or_global_6b] ==> core::DriveFindNextRequest::vfunc_06
unsigned int __cdecl pc_sub_006E41B0(void) { return 0x00000011; }
// PC VA 0x006E4200 (6 B) [pc_const_or_global_6b] ==> core::DriveFindCloseRequest::vfunc_06
unsigned int __cdecl pc_sub_006E4200(void) { return 0x00000012; }
// PC VA 0x006E4260 (4 B) [pc_this_field_getter_4b] ==> pure3d::d3dContext::vfunc_22 (+6 slots)
/* PC VA 0x006E4260: this->field (+0x0C) getter */
// PC VA 0x006E4270 (6 B) [pc_const_or_global_6b] ==> core::DriveFileDestroyRequest::vfunc_06
unsigned int __cdecl pc_sub_006E4270(void) { return 0x00000013; }
// PC VA 0x006E42C0 (6 B) [pc_const_or_global_6b] ==> core::DriveCancelRequest::vfunc_06
unsigned int __cdecl pc_sub_006E42C0(void) { return 0x00000014; }
// PC VA 0x006E42D0 (6 B) [pc_const_or_global_6b] ==> core::DriveLockRequest::vfunc_06
unsigned int __cdecl pc_sub_006E42D0(void) { return 0x00000015; }
// PC VA 0x006E5180 (4 B) [pc_this_field_getter_4b] ==> core::File::vfunc_26
/* PC VA 0x006E5180: this->field (+0x1E) getter */
// PC VA 0x006E51A0 (7 B) [pc_this_field_getter_7b] ==> core::File::vfunc_30
/* PC VA 0x006E51A0: this->field (+0x160) getter */
// PC VA 0x006E51C0 (13 B) [pc_this_field_setter_13b] ==> core::File::vfunc_31
/* PC VA 0x006E51C0: this->field (+0x120) setter */
// PC VA 0x006E51D0 (7 B) [pc_this_field_getter_7b] ==> core::File::vfunc_32
/* PC VA 0x006E51D0: this->field (+0x15C) getter */
// PC VA 0x006E51E0 (7 B) [pc_this_field_getter_7b] ==> core::File::vfunc_33
/* PC VA 0x006E51E0: this->field (+0x12C) getter */
// PC VA 0x006E6110 (4 B) [pc_this_field_getter_4b]
/* PC VA 0x006E6110: this->field (+0x78) getter */
// PC VA 0x006E6350 (10 B) [pc_this_field_setter_10b]
/* PC VA 0x006E6350: this->field (+0x74) setter */
// PC VA 0x006E6360 (4 B) [pc_this_field_getter_4b]
/* PC VA 0x006E6360: this->field (+0x74) getter */
// PC VA 0x006E6420 (4 B) [pc_this_field_getter_4b]
/* PC VA 0x006E6420: this->field (+0x14) getter */
// PC VA 0x006E6440 (5 B) [pc_stdcall_const_ret_5b] ==> core::Drive::vfunc_11 (+1 slots)
/* PC VA 0x006E6440: 5B stdcall const return */
// PC VA 0x006E6450 (5 B) [pc_stdcall_const_ret_5b] ==> core::Drive::vfunc_15
/* PC VA 0x006E6450: 5B stdcall const return */
// PC VA 0x006E74A0 (7 B) [pc_this_field_getter_7b] ==> core::Win32Drive::vfunc_05
/* PC VA 0x006E74A0: this->field (+0xE0) getter */
// PC VA 0x006E78B0 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> core::Win32Drive::vfunc_03
/* PC VA 0x006E78B0: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006E7EA0 (4 B) [pc_this_field_getter_4b] ==> AnimationRetargetingAction::vfunc_14 (+10 slots)
/* PC VA 0x006E7EA0: this->field (+0x10) getter */
// PC VA 0x006E8610 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> core::DriveThread::vfunc_03
/* PC VA 0x006E8610: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006E9820 (4 B) [pc_this_field_getter_4b] ==> GameMemorySegmentCollection::vfunc_02 (+18 slots)
/* PC VA 0x006E9820: this->field (+0x0C) getter */
// PC VA 0x006E9F50 (6 B) [pc_const_or_global_6b]
unsigned int __cdecl pc_sub_006E9F50(void) { return 0x00000001; }
// PC VA 0x006EB360 (7 B) [pc_this_field_getter_7b]
/* PC VA 0x006EB360: this->field (+0x284) getter */
// PC VA 0x006EBD10 (6 B) [pc_const_or_global_6b]
unsigned int __cdecl pc_sub_006EBD10(void) { return 0x007F6424; }
// PC VA 0x006ED590 (6 B) [pc_const_or_global_6b] ==> audio::Sequence::vfunc_12
unsigned int __cdecl pc_sub_006ED590(void) { return 0x00811D78; }
// PC VA 0x006EE040 (6 B) [pc_const_or_global_6b]
unsigned int __cdecl pc_sub_006EE040(void) { return 0x0085CEB0; }
// PC VA 0x006EE800 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::MixerMix::vfunc_03
/* PC VA 0x006EE800: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006EE9B0 (6 B) [pc_const_or_global_6b]
extern "C" char DAT_0085CEC0; void* __cdecl pc_sub_006EE9B0(void) { return &DAT_0085CEC0; }
// PC VA 0x006EEBF0 (6 B) [pc_const_or_global_6b] ==> om::audio::VMix::?$EntityType::vfunc_03
extern "C" char DAT_007C1624; void* __cdecl pc_sub_006EEBF0(void) { return &DAT_007C1624; }
// PC VA 0x006EEC00 (6 B) [pc_const_or_global_6b] ==> om::audio::VMix::?$EntityType::vfunc_02
unsigned int __cdecl pc_sub_006EEC00(void) { return 0x0085CEDC; }
// PC VA 0x006EECB0 (6 B) [pc_const_or_global_6b] ==> om::audio::VClip::?$EntityType::vfunc_03
extern "C" char DAT_007C6038; void* __cdecl pc_sub_006EECB0(void) { return &DAT_007C6038; }
// PC VA 0x006EECC0 (6 B) [pc_const_or_global_6b] ==> om::audio::VClip::?$EntityType::vfunc_02
unsigned int __cdecl pc_sub_006EECC0(void) { return 0x0085CEE0; }
// PC VA 0x006EED20 (6 B) [pc_const_or_global_6b] ==> audio::Clip::vfunc_12
unsigned int __cdecl pc_sub_006EED20(void) { return 0x0085CED0; }
// PC VA 0x006EEDE0 (6 B) [pc_const_or_global_6b] ==> om::audio::VSequence::?$EntityType::vfunc_03
extern "C" char DAT_007C1604; void* __cdecl pc_sub_006EEDE0(void) { return &DAT_007C1604; }
// PC VA 0x006EEDF0 (6 B) [pc_const_or_global_6b] ==> om::audio::VSequence::?$EntityType::vfunc_02
unsigned int __cdecl pc_sub_006EEDF0(void) { return 0x0085CEE4; }
// PC VA 0x006EF290 (6 B) [pc_const_or_global_6b]
extern "C" char DAT_0085D0F0; void* __cdecl pc_sub_006EF290(void) { return &DAT_0085D0F0; }
// PC VA 0x006F04A0 (6 B) [pc_const_or_global_6b] ==> audio::LayerTemplate::vfunc_12
unsigned int __cdecl pc_sub_006F04A0(void) { return 0x00811D7C; }
// PC VA 0x006F0560 (6 B) [pc_const_or_global_6b] ==> om::audio::VLayerTemplate::?$EntityType::vfunc_03
extern "C" char DAT_007F6A1C; void* __cdecl pc_sub_006F0560(void) { return &DAT_007F6A1C; }
// PC VA 0x006F0570 (6 B) [pc_const_or_global_6b] ==> om::audio::VLayerTemplate::?$EntityType::vfunc_02
unsigned int __cdecl pc_sub_006F0570(void) { return 0x0085D138; }
// PC VA 0x006F1660 (5 B) [pc_stdcall_const_ret_5b]
/* PC VA 0x006F1660: 5B stdcall const return */
// PC VA 0x006F4D80 (7 B) [pc_this_field_getter_7b] ==> audio::OggVorbisStream::vfunc_01
/* PC VA 0x006F4D80: this->field (+0x2EC) getter */
// PC VA 0x006F4D90 (7 B) [pc_this_field_getter_7b] ==> audio::OggVorbisStream::vfunc_02
/* PC VA 0x006F4D90: this->field (+0x2DC) getter */
// PC VA 0x006F5C90 (30 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventContainer::vfunc_04
/* PC VA 0x006F5C90: 30B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F6060 (6 B) [pc_const_or_global_6b] ==> audio::Mix::vfunc_12
unsigned int __cdecl pc_sub_006F6060(void) { return 0x00811DA8; }
// PC VA 0x006F67B0 (6 B) [pc_const_or_global_6b] ==> om::audio::VListenerEffectWin32::?$EntityType::vfunc_03
extern "C" char DAT_007C5AF8; void* __cdecl pc_sub_006F67B0(void) { return &DAT_007C5AF8; }
// PC VA 0x006F67C0 (6 B) [pc_const_or_global_6b] ==> om::audio::VListenerEffectWin32::?$EntityType::vfunc_02
unsigned int __cdecl pc_sub_006F67C0(void) { return 0x0085D4EC; }
// PC VA 0x006F67D0 (30 B) [pc_msvc71_scalar_deleting_dtor] ==> om::audio::VMix::?$EntityType::vfunc_00 (+4 slots)
/* PC VA 0x006F67D0: 30B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F6830 (6 B) [pc_const_or_global_6b] ==> audio::ListenerEffectWin32::vfunc_12
unsigned int __cdecl pc_sub_006F6830(void) { return 0x00811DAC; }
// PC VA 0x006F6960 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventNestTrack::vfunc_03
unsigned int __cdecl pc_sub_006F6960(void) { return 0x0085D4F0; }
// PC VA 0x006F6EC0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventChannelSendVolumes::vfunc_03
unsigned int __cdecl pc_sub_006F6EC0(void) { return 0x0085D4F4; }
// PC VA 0x006F6ED0 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventChannelSendVolumes::vfunc_04
/* PC VA 0x006F6ED0: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F71F0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventChannelSends::vfunc_03
unsigned int __cdecl pc_sub_006F71F0(void) { return 0x0085D4FC; }
// PC VA 0x006F7200 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventChannelSends::vfunc_04
/* PC VA 0x006F7200: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F74F0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventCondition::vfunc_03
unsigned int __cdecl pc_sub_006F74F0(void) { return 0x0085D500; }
// PC VA 0x006F7680 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventConditionElse::vfunc_03
unsigned int __cdecl pc_sub_006F7680(void) { return 0x0085D504; }
// PC VA 0x006F7690 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventConditionElse::vfunc_04
/* PC VA 0x006F7690: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F7930 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventWait::vfunc_03
unsigned int __cdecl pc_sub_006F7930(void) { return 0x0085D508; }
// PC VA 0x006F7D80 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventWaitBeat::vfunc_03
unsigned int __cdecl pc_sub_006F7D80(void) { return 0x0085D510; }
// PC VA 0x006F7F30 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventExpression::vfunc_03
unsigned int __cdecl pc_sub_006F7F30(void) { return 0x0085D518; }
// PC VA 0x006F8240 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventStopTrack::vfunc_03
unsigned int __cdecl pc_sub_006F8240(void) { return 0x0085D51C; }
// PC VA 0x006F8300 (30 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::audio::VSeqEventNestTrack::?$SeqEventType::vfunc_00 (+22 slots)
/* PC VA 0x006F8300: 30B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F8650 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventPlayTrack::vfunc_03
unsigned int __cdecl pc_sub_006F8650(void) { return 0x0085D520; }
// PC VA 0x006F8930 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventChannelVolumes::vfunc_03
unsigned int __cdecl pc_sub_006F8930(void) { return 0x0085D524; }
// PC VA 0x006F8940 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventChannelVolumes::vfunc_04
/* PC VA 0x006F8940: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F9060 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventVarVolumeRand::vfunc_03
unsigned int __cdecl pc_sub_006F9060(void) { return 0x0085D52C; }
// PC VA 0x006F9070 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventVarVolumeRand::vfunc_04
/* PC VA 0x006F9070: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F9280 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventVarVolume::vfunc_03
unsigned int __cdecl pc_sub_006F9280(void) { return 0x0085D530; }
// PC VA 0x006F9290 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventVarVolume::vfunc_04
/* PC VA 0x006F9290: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F94B0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventVarTempo::vfunc_03
unsigned int __cdecl pc_sub_006F94B0(void) { return 0x0085D534; }
// PC VA 0x006F94C0 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventVarTempo::vfunc_04
/* PC VA 0x006F94C0: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F96C0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventVarPosDist::vfunc_03
unsigned int __cdecl pc_sub_006F96C0(void) { return 0x0085D538; }
// PC VA 0x006F96D0 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventVarPosDist::vfunc_04
/* PC VA 0x006F96D0: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F98B0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventVarPitchRand::vfunc_03
unsigned int __cdecl pc_sub_006F98B0(void) { return 0x0085D53C; }
// PC VA 0x006F98C0 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventVarPitchRand::vfunc_04
/* PC VA 0x006F98C0: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F9AB0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventVarPitch::vfunc_03
unsigned int __cdecl pc_sub_006F9AB0(void) { return 0x0085D540; }
// PC VA 0x006F9AC0 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventVarPitch::vfunc_04
/* PC VA 0x006F9AC0: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006F9E20 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventStream::vfunc_03
unsigned int __cdecl pc_sub_006F9E20(void) { return 0x0085D544; }
// PC VA 0x006F9E30 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventStream::vfunc_04
/* PC VA 0x006F9E30: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006FA740 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventSilence::vfunc_03
unsigned int __cdecl pc_sub_006FA740(void) { return 0x0085D548; }
// PC VA 0x006FA750 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventSilence::vfunc_04
/* PC VA 0x006FA750: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006FAAA0 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventLogicRepeat::vfunc_04
/* PC VA 0x006FAAA0: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006FAAD0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventLogicRepeat::vfunc_03
unsigned int __cdecl pc_sub_006FAAD0(void) { return 0x0085D54C; }
// PC VA 0x006FADC0 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventLogicOr::vfunc_03
unsigned int __cdecl pc_sub_006FADC0(void) { return 0x0085D554; }
// PC VA 0x006FADD0 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventLogicOr::vfunc_04
/* PC VA 0x006FADD0: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x006FB240 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventCrossFade::vfunc_03
unsigned int __cdecl pc_sub_006FB240(void) { return 0x0085D558; }
// PC VA 0x006FB970 (6 B) [pc_const_or_global_6b] ==> audio::SeqEventClip::vfunc_03
unsigned int __cdecl pc_sub_006FB970(void) { return 0x0085D55C; }
// PC VA 0x006FB980 (35 B) [pc_msvc71_scalar_deleting_dtor] ==> audio::SeqEventClip::vfunc_04
/* PC VA 0x006FB980: 35B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x00700200 (4 B) [pc_this_field_getter_4b] ==> FETextObject::vfunc_46 (+2 slots)
/* PC VA 0x00700200: this->field (+0x2C) getter */
// PC VA 0x00701630 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> movie::PlayerBink::vfunc_03
/* PC VA 0x00701630: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x00701B90 (36 B) [pc_msvc71_scalar_deleting_dtor] ==> movie::RenderStrategyBink::vfunc_03
/* PC VA 0x00701B90: 36B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x00703300 (10 B) [pc_this_field_setter_10b] ==> pure3d::d3dDevice::vfunc_06
/* PC VA 0x00703300: this->field (+0x0C) setter */
// PC VA 0x00703590 (30 B) [pc_msvc71_scalar_deleting_dtor] ==> pure3d::d3dDevice::vfunc_03
/* PC VA 0x00703590: 30B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x00703DB0 (3 B) [pc_stdcall_ret_n_3b] ==> pure3d::d3dContext::vfunc_13 (+4 slots)
/* PC VA 0x00703DB0: stdcall ret 0x10 */
// PC VA 0x00703DC0 (3 B) [pc_stdcall_ret_n_3b] ==> pure3d::d3dPrimBufferStream::vfunc_15
/* PC VA 0x00703DC0: stdcall ret 0x14 */
// PC VA 0x00703FD0 (30 B) [pc_msvc71_scalar_deleting_dtor] ==> pure3d::d3dPrimBuffer::vfunc_03
/* PC VA 0x00703FD0: 30B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x007048D0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dErrorShader::vfunc_04
extern "C" char DAT_007FB648; void* __cdecl pc_sub_007048D0(void) { return &DAT_007FB648; }
// PC VA 0x00704A40 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dReflShader::vfunc_16
extern "C" char DAT_007FB7F0; void* __cdecl pc_sub_00704A40(void) { return &DAT_007FB7F0; }
// PC VA 0x00704A50 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dReflShader::vfunc_17
extern "C" char DAT_007FB718; void* __cdecl pc_sub_00704A50(void) { return &DAT_007FB718; }
// PC VA 0x00704A60 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dReflShader::vfunc_18
extern "C" char DAT_007FB6D0; void* __cdecl pc_sub_00704A60(void) { return &DAT_007FB6D0; }
// PC VA 0x00704A70 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dReflShader::vfunc_19
extern "C" char DAT_007FB838; void* __cdecl pc_sub_00704A70(void) { return &DAT_007FB838; }
// PC VA 0x00704A80 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dReflShader::vfunc_04
extern "C" char DAT_007FB6AC; void* __cdecl pc_sub_00704A80(void) { return &DAT_007FB6AC; }
// PC VA 0x00705050 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dPointSpriteShader::vfunc_16
extern "C" char DAT_007FB9D8; void* __cdecl pc_sub_00705050(void) { return &DAT_007FB9D8; }
// PC VA 0x00705060 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dPointSpriteShader::vfunc_17
extern "C" char DAT_007FBA08; void* __cdecl pc_sub_00705060(void) { return &DAT_007FBA08; }
// PC VA 0x00705070 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dPointSpriteShader::vfunc_18
extern "C" char DAT_007FB918; void* __cdecl pc_sub_00705070(void) { return &DAT_007FB918; }
// PC VA 0x00705080 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dPointSpriteShader::vfunc_04
extern "C" char DAT_007FB8F4; void* __cdecl pc_sub_00705080(void) { return &DAT_007FB8F4; }
// PC VA 0x007050D0 (13 B) [pc_this_field_setter_13b]
/* PC VA 0x007050D0: this->field (+0x9C) setter */
// PC VA 0x007050E0 (13 B) [pc_this_field_setter_13b]
/* PC VA 0x007050E0: this->field (+0xA0) setter */
// PC VA 0x007053D0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dLayeredShader::vfunc_16
extern "C" char DAT_007FBC28; void* __cdecl pc_sub_007053D0(void) { return &DAT_007FBC28; }
// PC VA 0x007053E0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dLayeredShader::vfunc_17
extern "C" char DAT_007FBC70; void* __cdecl pc_sub_007053E0(void) { return &DAT_007FBC70; }
// PC VA 0x007053F0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dLayeredShader::vfunc_18
extern "C" char DAT_007FBB50; void* __cdecl pc_sub_007053F0(void) { return &DAT_007FBB50; }
// PC VA 0x00705400 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dLayeredShader::vfunc_19
extern "C" char DAT_007FBBB0; void* __cdecl pc_sub_00705400(void) { return &DAT_007FBBB0; }
// PC VA 0x00705410 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dLayeredShader::vfunc_04
extern "C" char DAT_00769BD0; void* __cdecl pc_sub_00705410(void) { return &DAT_00769BD0; }
// PC VA 0x00705430 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_00705430(void) {}
// PC VA 0x007066A0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dSpecularShader::vfunc_04
extern "C" char DAT_007FBFE8; void* __cdecl pc_sub_007066A0(void) { return &DAT_007FBFE8; }
// PC VA 0x00706B80 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dSpecularShader::vfunc_16
extern "C" char DAT_007FBFA0; void* __cdecl pc_sub_00706B80(void) { return &DAT_007FBFA0; }
// PC VA 0x00706B90 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dSpecularShader::vfunc_17
extern "C" char DAT_007FBE98; void* __cdecl pc_sub_00706B90(void) { return &DAT_007FBE98; }
// PC VA 0x00706BA0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dSpecularShader::vfunc_18
extern "C" char DAT_007FBE50; void* __cdecl pc_sub_00706BA0(void) { return &DAT_007FBE50; }
// PC VA 0x00706BB0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dSpecularShader::vfunc_19
extern "C" char DAT_007FBF40; void* __cdecl pc_sub_00706BB0(void) { return &DAT_007FBF40; }
// PC VA 0x00706BC0 (30 B) [pc_msvc71_scalar_deleting_dtor] ==> pure3d::d3dSpecularShader::vfunc_03
/* PC VA 0x00706BC0: 30B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x00707310 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dCharacterShader::vfunc_16
extern "C" char DAT_007FC198; void* __cdecl pc_sub_00707310(void) { return &DAT_007FC198; }
// PC VA 0x00707320 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dCharacterShader::vfunc_17
extern "C" char DAT_007FC0C0; void* __cdecl pc_sub_00707320(void) { return &DAT_007FC0C0; }
// PC VA 0x00707330 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dCharacterShader::vfunc_18
extern "C" char DAT_007FC078; void* __cdecl pc_sub_00707330(void) { return &DAT_007FC078; }
// PC VA 0x00707340 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dCharacterShader::vfunc_19
extern "C" char DAT_0085D760; void* __cdecl pc_sub_00707340(void) { return &DAT_0085D760; }
// PC VA 0x00707350 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dCharacterShader::vfunc_04
extern "C" char DAT_0073E280; void* __cdecl pc_sub_00707350(void) { return &DAT_0073E280; }
// PC VA 0x007073A0 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_007073A0(void) {}
// PC VA 0x00707D80 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_00707D80(void) {}
// PC VA 0x00707EA0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVehicleShader::vfunc_04 (+1 slots)
extern "C" char DAT_007331B0; void* __cdecl pc_sub_00707EA0(void) { return &DAT_007331B0; }
// PC VA 0x00707EF0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVehicleShader::vfunc_16
extern "C" char DAT_007FC550; void* __cdecl pc_sub_00707EF0(void) { return &DAT_007FC550; }
// PC VA 0x00707F00 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVehicleShader::vfunc_17
extern "C" char DAT_007FC4C0; void* __cdecl pc_sub_00707F00(void) { return &DAT_007FC4C0; }
// PC VA 0x00707F10 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVehicleShader::vfunc_18
extern "C" char DAT_007FC418; void* __cdecl pc_sub_00707F10(void) { return &DAT_007FC418; }
// PC VA 0x00707F20 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVehicleShader::vfunc_19
extern "C" char DAT_007FC508; void* __cdecl pc_sub_00707F20(void) { return &DAT_007FC508; }
// PC VA 0x00708100 (13 B) [pc_this_field_setter_13b] ==> pure3d::d3dVehicleShader::vfunc_31
/* PC VA 0x00708100: this->field (+0x94) setter */
// PC VA 0x00708110 (13 B) [pc_this_field_setter_13b] ==> pure3d::d3dVehicleShader::vfunc_30
/* PC VA 0x00708110: this->field (+0x98) setter */
// PC VA 0x00708120 (13 B) [pc_this_field_setter_13b] ==> pure3d::d3dVehicleShader::vfunc_28
/* PC VA 0x00708120: this->field (+0x88) setter */
// PC VA 0x007081A0 (3 B) [pc_stdcall_ret_n_3b]
/* PC VA 0x007081A0: stdcall ret 0x4 */
// PC VA 0x007088B0 (30 B) [pc_msvc71_scalar_deleting_dtor] ==> pure3d::d3dVehicleShader::vfunc_03
/* PC VA 0x007088B0: 30B PC MSVC 7.10 scalar deleting dtor */
// PC VA 0x00708F50 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowShader::vfunc_16
extern "C" char DAT_007FC7E0; void* __cdecl pc_sub_00708F50(void) { return &DAT_007FC7E0; }
// PC VA 0x00708F60 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowShader::vfunc_17
extern "C" char DAT_007FC690; void* __cdecl pc_sub_00708F60(void) { return &DAT_007FC690; }
// PC VA 0x00708F70 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowShader::vfunc_18
extern "C" char DAT_007FC648; void* __cdecl pc_sub_00708F70(void) { return &DAT_007FC648; }
// PC VA 0x00708F80 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowShader::vfunc_19
extern "C" char DAT_007FC768; void* __cdecl pc_sub_00708F80(void) { return &DAT_007FC768; }
// PC VA 0x00708F90 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowShader::vfunc_04
extern "C" char DAT_0072F5B0; void* __cdecl pc_sub_00708F90(void) { return &DAT_0072F5B0; }
// PC VA 0x007090A0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowDecalShader::vfunc_16
extern "C" char DAT_007FC968; void* __cdecl pc_sub_007090A0(void) { return &DAT_007FC968; }
// PC VA 0x007090B0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowDecalShader::vfunc_17
extern "C" char DAT_007FC890; void* __cdecl pc_sub_007090B0(void) { return &DAT_007FC890; }
// PC VA 0x007090C0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowDecalShader::vfunc_18
extern "C" char DAT_007FC848; void* __cdecl pc_sub_007090C0(void) { return &DAT_007FC848; }
// PC VA 0x007090D0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowDecalShader::vfunc_19
extern "C" char DAT_0085D788; void* __cdecl pc_sub_007090D0(void) { return &DAT_0085D788; }
// PC VA 0x007090E0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dShadowDecalShader::vfunc_04
extern "C" char DAT_00769C04; void* __cdecl pc_sub_007090E0(void) { return &DAT_00769C04; }
// PC VA 0x00709370 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dDecalShader::vfunc_04
extern "C" char DAT_00769C24; void* __cdecl pc_sub_00709370(void) { return &DAT_00769C24; }
// PC VA 0x00709470 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVertexFadeShader::vfunc_04
extern "C" char DAT_007FC9FC; void* __cdecl pc_sub_00709470(void) { return &DAT_007FC9FC; }
// PC VA 0x007099F0 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVertexFadeShader::vfunc_16
extern "C" char DAT_007FCAF8; void* __cdecl pc_sub_007099F0(void) { return &DAT_007FCAF8; }
// PC VA 0x00709A00 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVertexFadeShader::vfunc_17
extern "C" char DAT_007FCA50; void* __cdecl pc_sub_00709A00(void) { return &DAT_007FCA50; }
// PC VA 0x00709A10 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVertexFadeShader::vfunc_18
extern "C" char DAT_007FCB70; void* __cdecl pc_sub_00709A10(void) { return &DAT_007FCB70; }
// PC VA 0x00709A20 (6 B) [pc_const_or_global_6b] ==> pure3d::d3dVertexFadeShader::vfunc_19
extern "C" char DAT_007FCB28; void* __cdecl pc_sub_00709A20(void) { return &DAT_007FCB28; }
// PC VA 0x0072C940 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_0072C940(void) {}
// PC VA 0x0072CC00 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_0072CC00(void) {}
// PC VA 0x0072CC10 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_0072CC10(void) {}
// PC VA 0x0072CD30 (1 B) [pc_void_ret_stub_1b]
void __cdecl pc_sub_0072CD30(void) {}
