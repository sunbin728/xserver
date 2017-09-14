// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vector3.proto

#ifndef PROTOBUF_vector3_2eproto__INCLUDED
#define PROTOBUF_vector3_2eproto__INCLUDED

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
class Vector3;
class Vector3DefaultTypeInternal;
extern Vector3DefaultTypeInternal _Vector3_default_instance_;
}  // namespace NetProto

namespace NetProto {

namespace protobuf_vector3_2eproto {
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
}  // namespace protobuf_vector3_2eproto

// ===================================================================

class Vector3 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.Vector3) */ {
 public:
  Vector3();
  virtual ~Vector3();

  Vector3(const Vector3& from);

  inline Vector3& operator=(const Vector3& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Vector3& default_instance();

  static inline const Vector3* internal_default_instance() {
    return reinterpret_cast<const Vector3*>(
               &_Vector3_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Vector3* other);

  // implements Message ----------------------------------------------

  inline Vector3* New() const PROTOBUF_FINAL { return New(NULL); }

  Vector3* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Vector3& from);
  void MergeFrom(const Vector3& from);
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
  void InternalSwap(Vector3* other);
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

  // float x = 1;
  void clear_x();
  static const int kXFieldNumber = 1;
  float x() const;
  void set_x(float value);

  // float y = 2;
  void clear_y();
  static const int kYFieldNumber = 2;
  float y() const;
  void set_y(float value);

  // float z = 3;
  void clear_z();
  static const int kZFieldNumber = 3;
  float z() const;
  void set_z(float value);

  // @@protoc_insertion_point(class_scope:NetProto.Vector3)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  float x_;
  float y_;
  float z_;
  mutable int _cached_size_;
  friend struct protobuf_vector3_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Vector3

// float x = 1;
inline void Vector3::clear_x() {
  x_ = 0;
}
inline float Vector3::x() const {
  // @@protoc_insertion_point(field_get:NetProto.Vector3.x)
  return x_;
}
inline void Vector3::set_x(float value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:NetProto.Vector3.x)
}

// float y = 2;
inline void Vector3::clear_y() {
  y_ = 0;
}
inline float Vector3::y() const {
  // @@protoc_insertion_point(field_get:NetProto.Vector3.y)
  return y_;
}
inline void Vector3::set_y(float value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:NetProto.Vector3.y)
}

// float z = 3;
inline void Vector3::clear_z() {
  z_ = 0;
}
inline float Vector3::z() const {
  // @@protoc_insertion_point(field_get:NetProto.Vector3.z)
  return z_;
}
inline void Vector3::set_z(float value) {
  
  z_ = value;
  // @@protoc_insertion_point(field_set:NetProto.Vector3.z)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_vector3_2eproto__INCLUDED