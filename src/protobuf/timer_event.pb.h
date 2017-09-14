// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: timer_event.proto

#ifndef PROTOBUF_timer_5fevent_2eproto__INCLUDED
#define PROTOBUF_timer_5fevent_2eproto__INCLUDED

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
class TimerEvent;
class TimerEventDefaultTypeInternal;
extern TimerEventDefaultTypeInternal _TimerEvent_default_instance_;
}  // namespace NetProto

namespace NetProto {

namespace protobuf_timer_5fevent_2eproto {
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
}  // namespace protobuf_timer_5fevent_2eproto

enum TimerEvent_TimerType {
  TimerEvent_TimerType_Timer_Thirsty = 0,
  TimerEvent_TimerType_Timer_Hunger = 1,
  TimerEvent_TimerType_Timer_Tired = 2,
  TimerEvent_TimerType_Timer_Ill = 3,
  TimerEvent_TimerType_TimerEvent_TimerType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  TimerEvent_TimerType_TimerEvent_TimerType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool TimerEvent_TimerType_IsValid(int value);
const TimerEvent_TimerType TimerEvent_TimerType_TimerType_MIN = TimerEvent_TimerType_Timer_Thirsty;
const TimerEvent_TimerType TimerEvent_TimerType_TimerType_MAX = TimerEvent_TimerType_Timer_Ill;
const int TimerEvent_TimerType_TimerType_ARRAYSIZE = TimerEvent_TimerType_TimerType_MAX + 1;

const ::google::protobuf::EnumDescriptor* TimerEvent_TimerType_descriptor();
inline const ::std::string& TimerEvent_TimerType_Name(TimerEvent_TimerType value) {
  return ::google::protobuf::internal::NameOfEnum(
    TimerEvent_TimerType_descriptor(), value);
}
inline bool TimerEvent_TimerType_Parse(
    const ::std::string& name, TimerEvent_TimerType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TimerEvent_TimerType>(
    TimerEvent_TimerType_descriptor(), name, value);
}
// ===================================================================

class TimerEvent : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.TimerEvent) */ {
 public:
  TimerEvent();
  virtual ~TimerEvent();

  TimerEvent(const TimerEvent& from);

  inline TimerEvent& operator=(const TimerEvent& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TimerEvent& default_instance();

  static inline const TimerEvent* internal_default_instance() {
    return reinterpret_cast<const TimerEvent*>(
               &_TimerEvent_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(TimerEvent* other);

  // implements Message ----------------------------------------------

  inline TimerEvent* New() const PROTOBUF_FINAL { return New(NULL); }

  TimerEvent* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TimerEvent& from);
  void MergeFrom(const TimerEvent& from);
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
  void InternalSwap(TimerEvent* other);
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

  typedef TimerEvent_TimerType TimerType;
  static const TimerType Timer_Thirsty =
    TimerEvent_TimerType_Timer_Thirsty;
  static const TimerType Timer_Hunger =
    TimerEvent_TimerType_Timer_Hunger;
  static const TimerType Timer_Tired =
    TimerEvent_TimerType_Timer_Tired;
  static const TimerType Timer_Ill =
    TimerEvent_TimerType_Timer_Ill;
  static inline bool TimerType_IsValid(int value) {
    return TimerEvent_TimerType_IsValid(value);
  }
  static const TimerType TimerType_MIN =
    TimerEvent_TimerType_TimerType_MIN;
  static const TimerType TimerType_MAX =
    TimerEvent_TimerType_TimerType_MAX;
  static const int TimerType_ARRAYSIZE =
    TimerEvent_TimerType_TimerType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  TimerType_descriptor() {
    return TimerEvent_TimerType_descriptor();
  }
  static inline const ::std::string& TimerType_Name(TimerType value) {
    return TimerEvent_TimerType_Name(value);
  }
  static inline bool TimerType_Parse(const ::std::string& name,
      TimerType* value) {
    return TimerEvent_TimerType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // string time = 1;
  void clear_time();
  static const int kTimeFieldNumber = 1;
  const ::std::string& time() const;
  void set_time(const ::std::string& value);
  #if LANG_CXX11
  void set_time(::std::string&& value);
  #endif
  void set_time(const char* value);
  void set_time(const char* value, size_t size);
  ::std::string* mutable_time();
  ::std::string* release_time();
  void set_allocated_time(::std::string* time);

  // .NetProto.TimerEvent.TimerType type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::NetProto::TimerEvent_TimerType type() const;
  void set_type(::NetProto::TimerEvent_TimerType value);

  // @@protoc_insertion_point(class_scope:NetProto.TimerEvent)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr time_;
  int type_;
  mutable int _cached_size_;
  friend struct protobuf_timer_5fevent_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TimerEvent

// string time = 1;
inline void TimerEvent::clear_time() {
  time_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TimerEvent::time() const {
  // @@protoc_insertion_point(field_get:NetProto.TimerEvent.time)
  return time_.GetNoArena();
}
inline void TimerEvent::set_time(const ::std::string& value) {
  
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.TimerEvent.time)
}
#if LANG_CXX11
inline void TimerEvent::set_time(::std::string&& value) {
  
  time_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.TimerEvent.time)
}
#endif
inline void TimerEvent::set_time(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.TimerEvent.time)
}
inline void TimerEvent::set_time(const char* value, size_t size) {
  
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.TimerEvent.time)
}
inline ::std::string* TimerEvent::mutable_time() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.TimerEvent.time)
  return time_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TimerEvent::release_time() {
  // @@protoc_insertion_point(field_release:NetProto.TimerEvent.time)
  
  return time_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TimerEvent::set_allocated_time(::std::string* time) {
  if (time != NULL) {
    
  } else {
    
  }
  time_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), time);
  // @@protoc_insertion_point(field_set_allocated:NetProto.TimerEvent.time)
}

// .NetProto.TimerEvent.TimerType type = 2;
inline void TimerEvent::clear_type() {
  type_ = 0;
}
inline ::NetProto::TimerEvent_TimerType TimerEvent::type() const {
  // @@protoc_insertion_point(field_get:NetProto.TimerEvent.type)
  return static_cast< ::NetProto::TimerEvent_TimerType >(type_);
}
inline void TimerEvent::set_type(::NetProto::TimerEvent_TimerType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimerEvent.type)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::NetProto::TimerEvent_TimerType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::TimerEvent_TimerType>() {
  return ::NetProto::TimerEvent_TimerType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_timer_5fevent_2eproto__INCLUDED