// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: obj_property_value.proto

#ifndef PROTOBUF_obj_5fproperty_5fvalue_2eproto__INCLUDED
#define PROTOBUF_obj_5fproperty_5fvalue_2eproto__INCLUDED

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
#include "scene_obj.pb.h"
// @@protoc_insertion_point(includes)
namespace NetProto {
class ObjPropertyValue;
class ObjPropertyValueDefaultTypeInternal;
extern ObjPropertyValueDefaultTypeInternal _ObjPropertyValue_default_instance_;
class SceneObj;
class SceneObjDefaultTypeInternal;
extern SceneObjDefaultTypeInternal _SceneObj_default_instance_;
}  // namespace NetProto

namespace NetProto {

namespace protobuf_obj_5fproperty_5fvalue_2eproto {
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
}  // namespace protobuf_obj_5fproperty_5fvalue_2eproto

// ===================================================================

class ObjPropertyValue : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.ObjPropertyValue) */ {
 public:
  ObjPropertyValue();
  virtual ~ObjPropertyValue();

  ObjPropertyValue(const ObjPropertyValue& from);

  inline ObjPropertyValue& operator=(const ObjPropertyValue& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ObjPropertyValue& default_instance();

  static inline const ObjPropertyValue* internal_default_instance() {
    return reinterpret_cast<const ObjPropertyValue*>(
               &_ObjPropertyValue_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ObjPropertyValue* other);

  // implements Message ----------------------------------------------

  inline ObjPropertyValue* New() const PROTOBUF_FINAL { return New(NULL); }

  ObjPropertyValue* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ObjPropertyValue& from);
  void MergeFrom(const ObjPropertyValue& from);
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
  void InternalSwap(ObjPropertyValue* other);
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

  // string property = 2;
  void clear_property();
  static const int kPropertyFieldNumber = 2;
  const ::std::string& property() const;
  void set_property(const ::std::string& value);
  #if LANG_CXX11
  void set_property(::std::string&& value);
  #endif
  void set_property(const char* value);
  void set_property(const char* value, size_t size);
  ::std::string* mutable_property();
  ::std::string* release_property();
  void set_allocated_property(::std::string* property);

  // string value = 3;
  void clear_value();
  static const int kValueFieldNumber = 3;
  const ::std::string& value() const;
  void set_value(const ::std::string& value);
  #if LANG_CXX11
  void set_value(::std::string&& value);
  #endif
  void set_value(const char* value);
  void set_value(const char* value, size_t size);
  ::std::string* mutable_value();
  ::std::string* release_value();
  void set_allocated_value(::std::string* value);

  // .NetProto.SceneObj obj = 1;
  bool has_obj() const;
  void clear_obj();
  static const int kObjFieldNumber = 1;
  const ::NetProto::SceneObj& obj() const;
  ::NetProto::SceneObj* mutable_obj();
  ::NetProto::SceneObj* release_obj();
  void set_allocated_obj(::NetProto::SceneObj* obj);

  // @@protoc_insertion_point(class_scope:NetProto.ObjPropertyValue)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr property_;
  ::google::protobuf::internal::ArenaStringPtr value_;
  ::NetProto::SceneObj* obj_;
  mutable int _cached_size_;
  friend struct protobuf_obj_5fproperty_5fvalue_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ObjPropertyValue

// .NetProto.SceneObj obj = 1;
inline bool ObjPropertyValue::has_obj() const {
  return this != internal_default_instance() && obj_ != NULL;
}
inline void ObjPropertyValue::clear_obj() {
  if (GetArenaNoVirtual() == NULL && obj_ != NULL) delete obj_;
  obj_ = NULL;
}
inline const ::NetProto::SceneObj& ObjPropertyValue::obj() const {
  // @@protoc_insertion_point(field_get:NetProto.ObjPropertyValue.obj)
  return obj_ != NULL ? *obj_
                         : *::NetProto::SceneObj::internal_default_instance();
}
inline ::NetProto::SceneObj* ObjPropertyValue::mutable_obj() {
  
  if (obj_ == NULL) {
    obj_ = new ::NetProto::SceneObj;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.ObjPropertyValue.obj)
  return obj_;
}
inline ::NetProto::SceneObj* ObjPropertyValue::release_obj() {
  // @@protoc_insertion_point(field_release:NetProto.ObjPropertyValue.obj)
  
  ::NetProto::SceneObj* temp = obj_;
  obj_ = NULL;
  return temp;
}
inline void ObjPropertyValue::set_allocated_obj(::NetProto::SceneObj* obj) {
  delete obj_;
  obj_ = obj;
  if (obj) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.ObjPropertyValue.obj)
}

// string property = 2;
inline void ObjPropertyValue::clear_property() {
  property_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ObjPropertyValue::property() const {
  // @@protoc_insertion_point(field_get:NetProto.ObjPropertyValue.property)
  return property_.GetNoArena();
}
inline void ObjPropertyValue::set_property(const ::std::string& value) {
  
  property_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.ObjPropertyValue.property)
}
#if LANG_CXX11
inline void ObjPropertyValue::set_property(::std::string&& value) {
  
  property_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.ObjPropertyValue.property)
}
#endif
inline void ObjPropertyValue::set_property(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  property_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.ObjPropertyValue.property)
}
inline void ObjPropertyValue::set_property(const char* value, size_t size) {
  
  property_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.ObjPropertyValue.property)
}
inline ::std::string* ObjPropertyValue::mutable_property() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.ObjPropertyValue.property)
  return property_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ObjPropertyValue::release_property() {
  // @@protoc_insertion_point(field_release:NetProto.ObjPropertyValue.property)
  
  return property_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ObjPropertyValue::set_allocated_property(::std::string* property) {
  if (property != NULL) {
    
  } else {
    
  }
  property_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), property);
  // @@protoc_insertion_point(field_set_allocated:NetProto.ObjPropertyValue.property)
}

// string value = 3;
inline void ObjPropertyValue::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ObjPropertyValue::value() const {
  // @@protoc_insertion_point(field_get:NetProto.ObjPropertyValue.value)
  return value_.GetNoArena();
}
inline void ObjPropertyValue::set_value(const ::std::string& value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.ObjPropertyValue.value)
}
#if LANG_CXX11
inline void ObjPropertyValue::set_value(::std::string&& value) {
  
  value_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.ObjPropertyValue.value)
}
#endif
inline void ObjPropertyValue::set_value(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.ObjPropertyValue.value)
}
inline void ObjPropertyValue::set_value(const char* value, size_t size) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.ObjPropertyValue.value)
}
inline ::std::string* ObjPropertyValue::mutable_value() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.ObjPropertyValue.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ObjPropertyValue::release_value() {
  // @@protoc_insertion_point(field_release:NetProto.ObjPropertyValue.value)
  
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ObjPropertyValue::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    
  } else {
    
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:NetProto.ObjPropertyValue.value)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_obj_5fproperty_5fvalue_2eproto__INCLUDED
