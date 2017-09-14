// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: emergency_event.proto

#ifndef PROTOBUF_emergency_5fevent_2eproto__INCLUDED
#define PROTOBUF_emergency_5fevent_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace NetProto {
namespace Pw {
class BirdLeave;
class BirdLeaveDefaultTypeInternal;
extern BirdLeaveDefaultTypeInternal _BirdLeave_default_instance_;
class BirdVisit;
class BirdVisitDefaultTypeInternal;
extern BirdVisitDefaultTypeInternal _BirdVisit_default_instance_;
class BirdVoice;
class BirdVoiceDefaultTypeInternal;
extern BirdVoiceDefaultTypeInternal _BirdVoice_default_instance_;
class DoorBellRing;
class DoorBellRingDefaultTypeInternal;
extern DoorBellRingDefaultTypeInternal _DoorBellRing_default_instance_;
class EmergencyEvent;
class EmergencyEventDefaultTypeInternal;
extern EmergencyEventDefaultTypeInternal _EmergencyEvent_default_instance_;
class EventData;
class EventDataDefaultTypeInternal;
extern EventDataDefaultTypeInternal _EventData_default_instance_;
}  // namespace Pw
}  // namespace NetProto

namespace NetProto {
namespace Pw {

namespace protobuf_emergency_5fevent_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_emergency_5fevent_2eproto

enum EventType {
  Unknown = 0,
  DOOR_BELL_RING = 1,
  BIRD_VOICE = 2,
  BIRD_VISIT = 3,
  BIRD_LEAVE = 4,
  EventType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EventType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EventType_IsValid(int value);
const EventType EventType_MIN = Unknown;
const EventType EventType_MAX = BIRD_LEAVE;
const int EventType_ARRAYSIZE = EventType_MAX + 1;

const ::google::protobuf::EnumDescriptor* EventType_descriptor();
inline const ::std::string& EventType_Name(EventType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EventType_descriptor(), value);
}
inline bool EventType_Parse(
    const ::std::string& name, EventType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EventType>(
    EventType_descriptor(), name, value);
}
// ===================================================================

class DoorBellRing : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.Pw.DoorBellRing) */ {
 public:
  DoorBellRing();
  virtual ~DoorBellRing();

  DoorBellRing(const DoorBellRing& from);

  inline DoorBellRing& operator=(const DoorBellRing& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DoorBellRing& default_instance();

  static inline const DoorBellRing* internal_default_instance() {
    return reinterpret_cast<const DoorBellRing*>(
               &_DoorBellRing_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(DoorBellRing* other);

  // implements Message ----------------------------------------------

  inline DoorBellRing* New() const PROTOBUF_FINAL { return New(NULL); }

  DoorBellRing* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DoorBellRing& from);
  void MergeFrom(const DoorBellRing& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(DoorBellRing* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:NetProto.Pw.DoorBellRing)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct protobuf_emergency_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class BirdVoice : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.Pw.BirdVoice) */ {
 public:
  BirdVoice();
  virtual ~BirdVoice();

  BirdVoice(const BirdVoice& from);

  inline BirdVoice& operator=(const BirdVoice& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BirdVoice& default_instance();

  static inline const BirdVoice* internal_default_instance() {
    return reinterpret_cast<const BirdVoice*>(
               &_BirdVoice_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(BirdVoice* other);

  // implements Message ----------------------------------------------

  inline BirdVoice* New() const PROTOBUF_FINAL { return New(NULL); }

  BirdVoice* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BirdVoice& from);
  void MergeFrom(const BirdVoice& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(BirdVoice* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:NetProto.Pw.BirdVoice)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct protobuf_emergency_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class BirdVisit : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.Pw.BirdVisit) */ {
 public:
  BirdVisit();
  virtual ~BirdVisit();

  BirdVisit(const BirdVisit& from);

  inline BirdVisit& operator=(const BirdVisit& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BirdVisit& default_instance();

  static inline const BirdVisit* internal_default_instance() {
    return reinterpret_cast<const BirdVisit*>(
               &_BirdVisit_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(BirdVisit* other);

  // implements Message ----------------------------------------------

  inline BirdVisit* New() const PROTOBUF_FINAL { return New(NULL); }

  BirdVisit* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BirdVisit& from);
  void MergeFrom(const BirdVisit& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(BirdVisit* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool taking_seed = 1;
  void clear_taking_seed();
  static const int kTakingSeedFieldNumber = 1;
  bool taking_seed() const;
  void set_taking_seed(bool value);

  // @@protoc_insertion_point(class_scope:NetProto.Pw.BirdVisit)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool taking_seed_;
  mutable int _cached_size_;
  friend struct protobuf_emergency_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class BirdLeave : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.Pw.BirdLeave) */ {
 public:
  BirdLeave();
  virtual ~BirdLeave();

  BirdLeave(const BirdLeave& from);

  inline BirdLeave& operator=(const BirdLeave& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BirdLeave& default_instance();

  static inline const BirdLeave* internal_default_instance() {
    return reinterpret_cast<const BirdLeave*>(
               &_BirdLeave_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(BirdLeave* other);

  // implements Message ----------------------------------------------

  inline BirdLeave* New() const PROTOBUF_FINAL { return New(NULL); }

  BirdLeave* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BirdLeave& from);
  void MergeFrom(const BirdLeave& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(BirdLeave* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool leave_feather = 1;
  void clear_leave_feather();
  static const int kLeaveFeatherFieldNumber = 1;
  bool leave_feather() const;
  void set_leave_feather(bool value);

  // @@protoc_insertion_point(class_scope:NetProto.Pw.BirdLeave)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool leave_feather_;
  mutable int _cached_size_;
  friend struct protobuf_emergency_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class EventData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.Pw.EventData) */ {
 public:
  EventData();
  virtual ~EventData();

  EventData(const EventData& from);

  inline EventData& operator=(const EventData& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EventData& default_instance();

  static inline const EventData* internal_default_instance() {
    return reinterpret_cast<const EventData*>(
               &_EventData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(EventData* other);

  // implements Message ----------------------------------------------

  inline EventData* New() const PROTOBUF_FINAL { return New(NULL); }

  EventData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const EventData& from);
  void MergeFrom(const EventData& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(EventData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .NetProto.Pw.DoorBellRing door_beel = 1;
  bool has_door_beel() const;
  void clear_door_beel();
  static const int kDoorBeelFieldNumber = 1;
  const ::NetProto::Pw::DoorBellRing& door_beel() const;
  ::NetProto::Pw::DoorBellRing* mutable_door_beel();
  ::NetProto::Pw::DoorBellRing* release_door_beel();
  void set_allocated_door_beel(::NetProto::Pw::DoorBellRing* door_beel);

  // .NetProto.Pw.BirdVoice bird_voice = 2;
  bool has_bird_voice() const;
  void clear_bird_voice();
  static const int kBirdVoiceFieldNumber = 2;
  const ::NetProto::Pw::BirdVoice& bird_voice() const;
  ::NetProto::Pw::BirdVoice* mutable_bird_voice();
  ::NetProto::Pw::BirdVoice* release_bird_voice();
  void set_allocated_bird_voice(::NetProto::Pw::BirdVoice* bird_voice);

  // .NetProto.Pw.BirdVisit bird_visit = 3;
  bool has_bird_visit() const;
  void clear_bird_visit();
  static const int kBirdVisitFieldNumber = 3;
  const ::NetProto::Pw::BirdVisit& bird_visit() const;
  ::NetProto::Pw::BirdVisit* mutable_bird_visit();
  ::NetProto::Pw::BirdVisit* release_bird_visit();
  void set_allocated_bird_visit(::NetProto::Pw::BirdVisit* bird_visit);

  // .NetProto.Pw.BirdLeave bird_leave = 4;
  bool has_bird_leave() const;
  void clear_bird_leave();
  static const int kBirdLeaveFieldNumber = 4;
  const ::NetProto::Pw::BirdLeave& bird_leave() const;
  ::NetProto::Pw::BirdLeave* mutable_bird_leave();
  ::NetProto::Pw::BirdLeave* release_bird_leave();
  void set_allocated_bird_leave(::NetProto::Pw::BirdLeave* bird_leave);

  // @@protoc_insertion_point(class_scope:NetProto.Pw.EventData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::NetProto::Pw::DoorBellRing* door_beel_;
  ::NetProto::Pw::BirdVoice* bird_voice_;
  ::NetProto::Pw::BirdVisit* bird_visit_;
  ::NetProto::Pw::BirdLeave* bird_leave_;
  mutable int _cached_size_;
  friend struct protobuf_emergency_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class EmergencyEvent : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.Pw.EmergencyEvent) */ {
 public:
  EmergencyEvent();
  virtual ~EmergencyEvent();

  EmergencyEvent(const EmergencyEvent& from);

  inline EmergencyEvent& operator=(const EmergencyEvent& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EmergencyEvent& default_instance();

  static inline const EmergencyEvent* internal_default_instance() {
    return reinterpret_cast<const EmergencyEvent*>(
               &_EmergencyEvent_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    5;

  void Swap(EmergencyEvent* other);

  // implements Message ----------------------------------------------

  inline EmergencyEvent* New() const PROTOBUF_FINAL { return New(NULL); }

  EmergencyEvent* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const EmergencyEvent& from);
  void MergeFrom(const EmergencyEvent& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(EmergencyEvent* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .NetProto.Pw.EventData data = 2;
  bool has_data() const;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::NetProto::Pw::EventData& data() const;
  ::NetProto::Pw::EventData* mutable_data();
  ::NetProto::Pw::EventData* release_data();
  void set_allocated_data(::NetProto::Pw::EventData* data);

  // .NetProto.Pw.EventType type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::NetProto::Pw::EventType type() const;
  void set_type(::NetProto::Pw::EventType value);

  // @@protoc_insertion_point(class_scope:NetProto.Pw.EmergencyEvent)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::NetProto::Pw::EventData* data_;
  int type_;
  mutable int _cached_size_;
  friend struct protobuf_emergency_5fevent_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// DoorBellRing

// -------------------------------------------------------------------

// BirdVoice

// -------------------------------------------------------------------

// BirdVisit

// bool taking_seed = 1;
inline void BirdVisit::clear_taking_seed() {
  taking_seed_ = false;
}
inline bool BirdVisit::taking_seed() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.BirdVisit.taking_seed)
  return taking_seed_;
}
inline void BirdVisit::set_taking_seed(bool value) {
  
  taking_seed_ = value;
  // @@protoc_insertion_point(field_set:NetProto.Pw.BirdVisit.taking_seed)
}

// -------------------------------------------------------------------

// BirdLeave

// bool leave_feather = 1;
inline void BirdLeave::clear_leave_feather() {
  leave_feather_ = false;
}
inline bool BirdLeave::leave_feather() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.BirdLeave.leave_feather)
  return leave_feather_;
}
inline void BirdLeave::set_leave_feather(bool value) {
  
  leave_feather_ = value;
  // @@protoc_insertion_point(field_set:NetProto.Pw.BirdLeave.leave_feather)
}

// -------------------------------------------------------------------

// EventData

// .NetProto.Pw.DoorBellRing door_beel = 1;
inline bool EventData::has_door_beel() const {
  return this != internal_default_instance() && door_beel_ != NULL;
}
inline void EventData::clear_door_beel() {
  if (GetArenaNoVirtual() == NULL && door_beel_ != NULL) delete door_beel_;
  door_beel_ = NULL;
}
inline const ::NetProto::Pw::DoorBellRing& EventData::door_beel() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.EventData.door_beel)
  return door_beel_ != NULL ? *door_beel_
                         : *::NetProto::Pw::DoorBellRing::internal_default_instance();
}
inline ::NetProto::Pw::DoorBellRing* EventData::mutable_door_beel() {
  
  if (door_beel_ == NULL) {
    door_beel_ = new ::NetProto::Pw::DoorBellRing;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.Pw.EventData.door_beel)
  return door_beel_;
}
inline ::NetProto::Pw::DoorBellRing* EventData::release_door_beel() {
  // @@protoc_insertion_point(field_release:NetProto.Pw.EventData.door_beel)
  
  ::NetProto::Pw::DoorBellRing* temp = door_beel_;
  door_beel_ = NULL;
  return temp;
}
inline void EventData::set_allocated_door_beel(::NetProto::Pw::DoorBellRing* door_beel) {
  delete door_beel_;
  door_beel_ = door_beel;
  if (door_beel) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.Pw.EventData.door_beel)
}

// .NetProto.Pw.BirdVoice bird_voice = 2;
inline bool EventData::has_bird_voice() const {
  return this != internal_default_instance() && bird_voice_ != NULL;
}
inline void EventData::clear_bird_voice() {
  if (GetArenaNoVirtual() == NULL && bird_voice_ != NULL) delete bird_voice_;
  bird_voice_ = NULL;
}
inline const ::NetProto::Pw::BirdVoice& EventData::bird_voice() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.EventData.bird_voice)
  return bird_voice_ != NULL ? *bird_voice_
                         : *::NetProto::Pw::BirdVoice::internal_default_instance();
}
inline ::NetProto::Pw::BirdVoice* EventData::mutable_bird_voice() {
  
  if (bird_voice_ == NULL) {
    bird_voice_ = new ::NetProto::Pw::BirdVoice;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.Pw.EventData.bird_voice)
  return bird_voice_;
}
inline ::NetProto::Pw::BirdVoice* EventData::release_bird_voice() {
  // @@protoc_insertion_point(field_release:NetProto.Pw.EventData.bird_voice)
  
  ::NetProto::Pw::BirdVoice* temp = bird_voice_;
  bird_voice_ = NULL;
  return temp;
}
inline void EventData::set_allocated_bird_voice(::NetProto::Pw::BirdVoice* bird_voice) {
  delete bird_voice_;
  bird_voice_ = bird_voice;
  if (bird_voice) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.Pw.EventData.bird_voice)
}

// .NetProto.Pw.BirdVisit bird_visit = 3;
inline bool EventData::has_bird_visit() const {
  return this != internal_default_instance() && bird_visit_ != NULL;
}
inline void EventData::clear_bird_visit() {
  if (GetArenaNoVirtual() == NULL && bird_visit_ != NULL) delete bird_visit_;
  bird_visit_ = NULL;
}
inline const ::NetProto::Pw::BirdVisit& EventData::bird_visit() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.EventData.bird_visit)
  return bird_visit_ != NULL ? *bird_visit_
                         : *::NetProto::Pw::BirdVisit::internal_default_instance();
}
inline ::NetProto::Pw::BirdVisit* EventData::mutable_bird_visit() {
  
  if (bird_visit_ == NULL) {
    bird_visit_ = new ::NetProto::Pw::BirdVisit;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.Pw.EventData.bird_visit)
  return bird_visit_;
}
inline ::NetProto::Pw::BirdVisit* EventData::release_bird_visit() {
  // @@protoc_insertion_point(field_release:NetProto.Pw.EventData.bird_visit)
  
  ::NetProto::Pw::BirdVisit* temp = bird_visit_;
  bird_visit_ = NULL;
  return temp;
}
inline void EventData::set_allocated_bird_visit(::NetProto::Pw::BirdVisit* bird_visit) {
  delete bird_visit_;
  bird_visit_ = bird_visit;
  if (bird_visit) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.Pw.EventData.bird_visit)
}

// .NetProto.Pw.BirdLeave bird_leave = 4;
inline bool EventData::has_bird_leave() const {
  return this != internal_default_instance() && bird_leave_ != NULL;
}
inline void EventData::clear_bird_leave() {
  if (GetArenaNoVirtual() == NULL && bird_leave_ != NULL) delete bird_leave_;
  bird_leave_ = NULL;
}
inline const ::NetProto::Pw::BirdLeave& EventData::bird_leave() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.EventData.bird_leave)
  return bird_leave_ != NULL ? *bird_leave_
                         : *::NetProto::Pw::BirdLeave::internal_default_instance();
}
inline ::NetProto::Pw::BirdLeave* EventData::mutable_bird_leave() {
  
  if (bird_leave_ == NULL) {
    bird_leave_ = new ::NetProto::Pw::BirdLeave;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.Pw.EventData.bird_leave)
  return bird_leave_;
}
inline ::NetProto::Pw::BirdLeave* EventData::release_bird_leave() {
  // @@protoc_insertion_point(field_release:NetProto.Pw.EventData.bird_leave)
  
  ::NetProto::Pw::BirdLeave* temp = bird_leave_;
  bird_leave_ = NULL;
  return temp;
}
inline void EventData::set_allocated_bird_leave(::NetProto::Pw::BirdLeave* bird_leave) {
  delete bird_leave_;
  bird_leave_ = bird_leave;
  if (bird_leave) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.Pw.EventData.bird_leave)
}

// -------------------------------------------------------------------

// EmergencyEvent

// .NetProto.Pw.EventType type = 1;
inline void EmergencyEvent::clear_type() {
  type_ = 0;
}
inline ::NetProto::Pw::EventType EmergencyEvent::type() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.EmergencyEvent.type)
  return static_cast< ::NetProto::Pw::EventType >(type_);
}
inline void EmergencyEvent::set_type(::NetProto::Pw::EventType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:NetProto.Pw.EmergencyEvent.type)
}

// .NetProto.Pw.EventData data = 2;
inline bool EmergencyEvent::has_data() const {
  return this != internal_default_instance() && data_ != NULL;
}
inline void EmergencyEvent::clear_data() {
  if (GetArenaNoVirtual() == NULL && data_ != NULL) delete data_;
  data_ = NULL;
}
inline const ::NetProto::Pw::EventData& EmergencyEvent::data() const {
  // @@protoc_insertion_point(field_get:NetProto.Pw.EmergencyEvent.data)
  return data_ != NULL ? *data_
                         : *::NetProto::Pw::EventData::internal_default_instance();
}
inline ::NetProto::Pw::EventData* EmergencyEvent::mutable_data() {
  
  if (data_ == NULL) {
    data_ = new ::NetProto::Pw::EventData;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.Pw.EmergencyEvent.data)
  return data_;
}
inline ::NetProto::Pw::EventData* EmergencyEvent::release_data() {
  // @@protoc_insertion_point(field_release:NetProto.Pw.EmergencyEvent.data)
  
  ::NetProto::Pw::EventData* temp = data_;
  data_ = NULL;
  return temp;
}
inline void EmergencyEvent::set_allocated_data(::NetProto::Pw::EventData* data) {
  delete data_;
  data_ = data;
  if (data) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.Pw.EmergencyEvent.data)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace Pw
}  // namespace NetProto

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::NetProto::Pw::EventType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::Pw::EventType>() {
  return ::NetProto::Pw::EventType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_emergency_5fevent_2eproto__INCLUDED
