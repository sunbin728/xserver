// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: time_info.proto

#ifndef PROTOBUF_time_5finfo_2eproto__INCLUDED
#define PROTOBUF_time_5finfo_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace NetProto {
class TimeInfo;
class TimeInfoDefaultTypeInternal;
extern TimeInfoDefaultTypeInternal _TimeInfo_default_instance_;
class TimeInfoStruct;
class TimeInfoStructDefaultTypeInternal;
extern TimeInfoStructDefaultTypeInternal _TimeInfoStruct_default_instance_;
}  // namespace NetProto

namespace NetProto {

namespace protobuf_time_5finfo_2eproto {
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
}  // namespace protobuf_time_5finfo_2eproto

// ===================================================================

class TimeInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.TimeInfo) */ {
 public:
  TimeInfo();
  virtual ~TimeInfo();

  TimeInfo(const TimeInfo& from);

  inline TimeInfo& operator=(const TimeInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TimeInfo& default_instance();

  static inline const TimeInfo* internal_default_instance() {
    return reinterpret_cast<const TimeInfo*>(
               &_TimeInfo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(TimeInfo* other);

  // implements Message ----------------------------------------------

  inline TimeInfo* New() const PROTOBUF_FINAL { return New(NULL); }

  TimeInfo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TimeInfo& from);
  void MergeFrom(const TimeInfo& from);
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
  void InternalSwap(TimeInfo* other);
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

  // string pw_time = 3;
  void clear_pw_time();
  static const int kPwTimeFieldNumber = 3;
  const ::std::string& pw_time() const;
  void set_pw_time(const ::std::string& value);
  #if LANG_CXX11
  void set_pw_time(::std::string&& value);
  #endif
  void set_pw_time(const char* value);
  void set_pw_time(const char* value, size_t size);
  ::std::string* mutable_pw_time();
  ::std::string* release_pw_time();
  void set_allocated_pw_time(::std::string* pw_time);

  // uint32 multiple = 2;
  void clear_multiple();
  static const int kMultipleFieldNumber = 2;
  ::google::protobuf::uint32 multiple() const;
  void set_multiple(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetProto.TimeInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr pw_time_;
  ::google::protobuf::uint32 multiple_;
  mutable int _cached_size_;
  friend struct protobuf_time_5finfo_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class TimeInfoStruct : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.TimeInfoStruct) */ {
 public:
  TimeInfoStruct();
  virtual ~TimeInfoStruct();

  TimeInfoStruct(const TimeInfoStruct& from);

  inline TimeInfoStruct& operator=(const TimeInfoStruct& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TimeInfoStruct& default_instance();

  static inline const TimeInfoStruct* internal_default_instance() {
    return reinterpret_cast<const TimeInfoStruct*>(
               &_TimeInfoStruct_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(TimeInfoStruct* other);

  // implements Message ----------------------------------------------

  inline TimeInfoStruct* New() const PROTOBUF_FINAL { return New(NULL); }

  TimeInfoStruct* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TimeInfoStruct& from);
  void MergeFrom(const TimeInfoStruct& from);
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
  void InternalSwap(TimeInfoStruct* other);
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

  // uint32 year = 1;
  void clear_year();
  static const int kYearFieldNumber = 1;
  ::google::protobuf::uint32 year() const;
  void set_year(::google::protobuf::uint32 value);

  // uint32 month = 2;
  void clear_month();
  static const int kMonthFieldNumber = 2;
  ::google::protobuf::uint32 month() const;
  void set_month(::google::protobuf::uint32 value);

  // uint32 day = 3;
  void clear_day();
  static const int kDayFieldNumber = 3;
  ::google::protobuf::uint32 day() const;
  void set_day(::google::protobuf::uint32 value);

  // uint32 hour = 4;
  void clear_hour();
  static const int kHourFieldNumber = 4;
  ::google::protobuf::uint32 hour() const;
  void set_hour(::google::protobuf::uint32 value);

  // uint32 min = 5;
  void clear_min();
  static const int kMinFieldNumber = 5;
  ::google::protobuf::uint32 min() const;
  void set_min(::google::protobuf::uint32 value);

  // uint32 sec = 6;
  void clear_sec();
  static const int kSecFieldNumber = 6;
  ::google::protobuf::uint32 sec() const;
  void set_sec(::google::protobuf::uint32 value);

  // uint32 multiple = 7;
  void clear_multiple();
  static const int kMultipleFieldNumber = 7;
  ::google::protobuf::uint32 multiple() const;
  void set_multiple(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetProto.TimeInfoStruct)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 year_;
  ::google::protobuf::uint32 month_;
  ::google::protobuf::uint32 day_;
  ::google::protobuf::uint32 hour_;
  ::google::protobuf::uint32 min_;
  ::google::protobuf::uint32 sec_;
  ::google::protobuf::uint32 multiple_;
  mutable int _cached_size_;
  friend struct protobuf_time_5finfo_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TimeInfo

// string pw_time = 3;
inline void TimeInfo::clear_pw_time() {
  pw_time_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TimeInfo::pw_time() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfo.pw_time)
  return pw_time_.GetNoArena();
}
inline void TimeInfo::set_pw_time(const ::std::string& value) {
  
  pw_time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.TimeInfo.pw_time)
}
#if LANG_CXX11
inline void TimeInfo::set_pw_time(::std::string&& value) {
  
  pw_time_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.TimeInfo.pw_time)
}
#endif
inline void TimeInfo::set_pw_time(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  pw_time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.TimeInfo.pw_time)
}
inline void TimeInfo::set_pw_time(const char* value, size_t size) {
  
  pw_time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.TimeInfo.pw_time)
}
inline ::std::string* TimeInfo::mutable_pw_time() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.TimeInfo.pw_time)
  return pw_time_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TimeInfo::release_pw_time() {
  // @@protoc_insertion_point(field_release:NetProto.TimeInfo.pw_time)
  
  return pw_time_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TimeInfo::set_allocated_pw_time(::std::string* pw_time) {
  if (pw_time != NULL) {
    
  } else {
    
  }
  pw_time_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), pw_time);
  // @@protoc_insertion_point(field_set_allocated:NetProto.TimeInfo.pw_time)
}

// uint32 multiple = 2;
inline void TimeInfo::clear_multiple() {
  multiple_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfo::multiple() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfo.multiple)
  return multiple_;
}
inline void TimeInfo::set_multiple(::google::protobuf::uint32 value) {
  
  multiple_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfo.multiple)
}

// -------------------------------------------------------------------

// TimeInfoStruct

// uint32 year = 1;
inline void TimeInfoStruct::clear_year() {
  year_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfoStruct::year() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfoStruct.year)
  return year_;
}
inline void TimeInfoStruct::set_year(::google::protobuf::uint32 value) {
  
  year_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfoStruct.year)
}

// uint32 month = 2;
inline void TimeInfoStruct::clear_month() {
  month_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfoStruct::month() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfoStruct.month)
  return month_;
}
inline void TimeInfoStruct::set_month(::google::protobuf::uint32 value) {
  
  month_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfoStruct.month)
}

// uint32 day = 3;
inline void TimeInfoStruct::clear_day() {
  day_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfoStruct::day() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfoStruct.day)
  return day_;
}
inline void TimeInfoStruct::set_day(::google::protobuf::uint32 value) {
  
  day_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfoStruct.day)
}

// uint32 hour = 4;
inline void TimeInfoStruct::clear_hour() {
  hour_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfoStruct::hour() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfoStruct.hour)
  return hour_;
}
inline void TimeInfoStruct::set_hour(::google::protobuf::uint32 value) {
  
  hour_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfoStruct.hour)
}

// uint32 min = 5;
inline void TimeInfoStruct::clear_min() {
  min_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfoStruct::min() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfoStruct.min)
  return min_;
}
inline void TimeInfoStruct::set_min(::google::protobuf::uint32 value) {
  
  min_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfoStruct.min)
}

// uint32 sec = 6;
inline void TimeInfoStruct::clear_sec() {
  sec_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfoStruct::sec() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfoStruct.sec)
  return sec_;
}
inline void TimeInfoStruct::set_sec(::google::protobuf::uint32 value) {
  
  sec_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfoStruct.sec)
}

// uint32 multiple = 7;
inline void TimeInfoStruct::clear_multiple() {
  multiple_ = 0u;
}
inline ::google::protobuf::uint32 TimeInfoStruct::multiple() const {
  // @@protoc_insertion_point(field_get:NetProto.TimeInfoStruct.multiple)
  return multiple_;
}
inline void TimeInfoStruct::set_multiple(::google::protobuf::uint32 value) {
  
  multiple_ = value;
  // @@protoc_insertion_point(field_set:NetProto.TimeInfoStruct.multiple)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_time_5finfo_2eproto__INCLUDED