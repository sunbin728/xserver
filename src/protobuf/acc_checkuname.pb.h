// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: acc_checkuname.proto

#ifndef PROTOBUF_acc_5fcheckuname_2eproto__INCLUDED
#define PROTOBUF_acc_5fcheckuname_2eproto__INCLUDED

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
#include "msg_head.pb.h"
// @@protoc_insertion_point(includes)
namespace protocol {
class CheckUnameReq;
class CheckUnameReqDefaultTypeInternal;
extern CheckUnameReqDefaultTypeInternal _CheckUnameReq_default_instance_;
class CheckUnameResp;
class CheckUnameRespDefaultTypeInternal;
extern CheckUnameRespDefaultTypeInternal _CheckUnameResp_default_instance_;
class MsgHead;
class MsgHeadDefaultTypeInternal;
extern MsgHeadDefaultTypeInternal _MsgHead_default_instance_;
}  // namespace protocol

namespace protocol {

namespace protobuf_acc_5fcheckuname_2eproto {
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
}  // namespace protobuf_acc_5fcheckuname_2eproto

// ===================================================================

class CheckUnameReq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.CheckUnameReq) */ {
 public:
  CheckUnameReq();
  virtual ~CheckUnameReq();

  CheckUnameReq(const CheckUnameReq& from);

  inline CheckUnameReq& operator=(const CheckUnameReq& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CheckUnameReq& default_instance();

  static inline const CheckUnameReq* internal_default_instance() {
    return reinterpret_cast<const CheckUnameReq*>(
               &_CheckUnameReq_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(CheckUnameReq* other);

  // implements Message ----------------------------------------------

  inline CheckUnameReq* New() const PROTOBUF_FINAL { return New(NULL); }

  CheckUnameReq* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CheckUnameReq& from);
  void MergeFrom(const CheckUnameReq& from);
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
  void InternalSwap(CheckUnameReq* other);
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

  // string Seq = 2;
  void clear_seq();
  static const int kSeqFieldNumber = 2;
  const ::std::string& seq() const;
  void set_seq(const ::std::string& value);
  #if LANG_CXX11
  void set_seq(::std::string&& value);
  #endif
  void set_seq(const char* value);
  void set_seq(const char* value, size_t size);
  ::std::string* mutable_seq();
  ::std::string* release_seq();
  void set_allocated_seq(::std::string* seq);

  // string Appid = 3;
  void clear_appid();
  static const int kAppidFieldNumber = 3;
  const ::std::string& appid() const;
  void set_appid(const ::std::string& value);
  #if LANG_CXX11
  void set_appid(::std::string&& value);
  #endif
  void set_appid(const char* value);
  void set_appid(const char* value, size_t size);
  ::std::string* mutable_appid();
  ::std::string* release_appid();
  void set_allocated_appid(::std::string* appid);

  // string Uname = 4;
  void clear_uname();
  static const int kUnameFieldNumber = 4;
  const ::std::string& uname() const;
  void set_uname(const ::std::string& value);
  #if LANG_CXX11
  void set_uname(::std::string&& value);
  #endif
  void set_uname(const char* value);
  void set_uname(const char* value, size_t size);
  ::std::string* mutable_uname();
  ::std::string* release_uname();
  void set_allocated_uname(::std::string* uname);

  // .protocol.MsgHead Header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  const ::protocol::MsgHead& header() const;
  ::protocol::MsgHead* mutable_header();
  ::protocol::MsgHead* release_header();
  void set_allocated_header(::protocol::MsgHead* header);

  // @@protoc_insertion_point(class_scope:protocol.CheckUnameReq)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr seq_;
  ::google::protobuf::internal::ArenaStringPtr appid_;
  ::google::protobuf::internal::ArenaStringPtr uname_;
  ::protocol::MsgHead* header_;
  mutable int _cached_size_;
  friend struct protobuf_acc_5fcheckuname_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class CheckUnameResp : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.CheckUnameResp) */ {
 public:
  CheckUnameResp();
  virtual ~CheckUnameResp();

  CheckUnameResp(const CheckUnameResp& from);

  inline CheckUnameResp& operator=(const CheckUnameResp& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CheckUnameResp& default_instance();

  static inline const CheckUnameResp* internal_default_instance() {
    return reinterpret_cast<const CheckUnameResp*>(
               &_CheckUnameResp_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(CheckUnameResp* other);

  // implements Message ----------------------------------------------

  inline CheckUnameResp* New() const PROTOBUF_FINAL { return New(NULL); }

  CheckUnameResp* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CheckUnameResp& from);
  void MergeFrom(const CheckUnameResp& from);
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
  void InternalSwap(CheckUnameResp* other);
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

  // string Seq = 2;
  void clear_seq();
  static const int kSeqFieldNumber = 2;
  const ::std::string& seq() const;
  void set_seq(const ::std::string& value);
  #if LANG_CXX11
  void set_seq(::std::string&& value);
  #endif
  void set_seq(const char* value);
  void set_seq(const char* value, size_t size);
  ::std::string* mutable_seq();
  ::std::string* release_seq();
  void set_allocated_seq(::std::string* seq);

  // string Msg = 4;
  void clear_msg();
  static const int kMsgFieldNumber = 4;
  const ::std::string& msg() const;
  void set_msg(const ::std::string& value);
  #if LANG_CXX11
  void set_msg(::std::string&& value);
  #endif
  void set_msg(const char* value);
  void set_msg(const char* value, size_t size);
  ::std::string* mutable_msg();
  ::std::string* release_msg();
  void set_allocated_msg(::std::string* msg);

  // string Uname = 5;
  void clear_uname();
  static const int kUnameFieldNumber = 5;
  const ::std::string& uname() const;
  void set_uname(const ::std::string& value);
  #if LANG_CXX11
  void set_uname(::std::string&& value);
  #endif
  void set_uname(const char* value);
  void set_uname(const char* value, size_t size);
  ::std::string* mutable_uname();
  ::std::string* release_uname();
  void set_allocated_uname(::std::string* uname);

  // .protocol.MsgHead Header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  const ::protocol::MsgHead& header() const;
  ::protocol::MsgHead* mutable_header();
  ::protocol::MsgHead* release_header();
  void set_allocated_header(::protocol::MsgHead* header);

  // int64 Result = 3;
  void clear_result();
  static const int kResultFieldNumber = 3;
  ::google::protobuf::int64 result() const;
  void set_result(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:protocol.CheckUnameResp)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr seq_;
  ::google::protobuf::internal::ArenaStringPtr msg_;
  ::google::protobuf::internal::ArenaStringPtr uname_;
  ::protocol::MsgHead* header_;
  ::google::protobuf::int64 result_;
  mutable int _cached_size_;
  friend struct protobuf_acc_5fcheckuname_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// CheckUnameReq

// .protocol.MsgHead Header = 1;
inline bool CheckUnameReq::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline void CheckUnameReq::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) delete header_;
  header_ = NULL;
}
inline const ::protocol::MsgHead& CheckUnameReq::header() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameReq.Header)
  return header_ != NULL ? *header_
                         : *::protocol::MsgHead::internal_default_instance();
}
inline ::protocol::MsgHead* CheckUnameReq::mutable_header() {
  
  if (header_ == NULL) {
    header_ = new ::protocol::MsgHead;
  }
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameReq.Header)
  return header_;
}
inline ::protocol::MsgHead* CheckUnameReq::release_header() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameReq.Header)
  
  ::protocol::MsgHead* temp = header_;
  header_ = NULL;
  return temp;
}
inline void CheckUnameReq::set_allocated_header(::protocol::MsgHead* header) {
  delete header_;
  header_ = header;
  if (header) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameReq.Header)
}

// string Seq = 2;
inline void CheckUnameReq::clear_seq() {
  seq_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CheckUnameReq::seq() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameReq.Seq)
  return seq_.GetNoArena();
}
inline void CheckUnameReq::set_seq(const ::std::string& value) {
  
  seq_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protocol.CheckUnameReq.Seq)
}
#if LANG_CXX11
inline void CheckUnameReq::set_seq(::std::string&& value) {
  
  seq_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.CheckUnameReq.Seq)
}
#endif
inline void CheckUnameReq::set_seq(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  seq_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.CheckUnameReq.Seq)
}
inline void CheckUnameReq::set_seq(const char* value, size_t size) {
  
  seq_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.CheckUnameReq.Seq)
}
inline ::std::string* CheckUnameReq::mutable_seq() {
  
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameReq.Seq)
  return seq_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CheckUnameReq::release_seq() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameReq.Seq)
  
  return seq_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CheckUnameReq::set_allocated_seq(::std::string* seq) {
  if (seq != NULL) {
    
  } else {
    
  }
  seq_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), seq);
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameReq.Seq)
}

// string Appid = 3;
inline void CheckUnameReq::clear_appid() {
  appid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CheckUnameReq::appid() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameReq.Appid)
  return appid_.GetNoArena();
}
inline void CheckUnameReq::set_appid(const ::std::string& value) {
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protocol.CheckUnameReq.Appid)
}
#if LANG_CXX11
inline void CheckUnameReq::set_appid(::std::string&& value) {
  
  appid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.CheckUnameReq.Appid)
}
#endif
inline void CheckUnameReq::set_appid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.CheckUnameReq.Appid)
}
inline void CheckUnameReq::set_appid(const char* value, size_t size) {
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.CheckUnameReq.Appid)
}
inline ::std::string* CheckUnameReq::mutable_appid() {
  
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameReq.Appid)
  return appid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CheckUnameReq::release_appid() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameReq.Appid)
  
  return appid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CheckUnameReq::set_allocated_appid(::std::string* appid) {
  if (appid != NULL) {
    
  } else {
    
  }
  appid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), appid);
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameReq.Appid)
}

// string Uname = 4;
inline void CheckUnameReq::clear_uname() {
  uname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CheckUnameReq::uname() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameReq.Uname)
  return uname_.GetNoArena();
}
inline void CheckUnameReq::set_uname(const ::std::string& value) {
  
  uname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protocol.CheckUnameReq.Uname)
}
#if LANG_CXX11
inline void CheckUnameReq::set_uname(::std::string&& value) {
  
  uname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.CheckUnameReq.Uname)
}
#endif
inline void CheckUnameReq::set_uname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  uname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.CheckUnameReq.Uname)
}
inline void CheckUnameReq::set_uname(const char* value, size_t size) {
  
  uname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.CheckUnameReq.Uname)
}
inline ::std::string* CheckUnameReq::mutable_uname() {
  
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameReq.Uname)
  return uname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CheckUnameReq::release_uname() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameReq.Uname)
  
  return uname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CheckUnameReq::set_allocated_uname(::std::string* uname) {
  if (uname != NULL) {
    
  } else {
    
  }
  uname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), uname);
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameReq.Uname)
}

// -------------------------------------------------------------------

// CheckUnameResp

// .protocol.MsgHead Header = 1;
inline bool CheckUnameResp::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline void CheckUnameResp::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) delete header_;
  header_ = NULL;
}
inline const ::protocol::MsgHead& CheckUnameResp::header() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameResp.Header)
  return header_ != NULL ? *header_
                         : *::protocol::MsgHead::internal_default_instance();
}
inline ::protocol::MsgHead* CheckUnameResp::mutable_header() {
  
  if (header_ == NULL) {
    header_ = new ::protocol::MsgHead;
  }
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameResp.Header)
  return header_;
}
inline ::protocol::MsgHead* CheckUnameResp::release_header() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameResp.Header)
  
  ::protocol::MsgHead* temp = header_;
  header_ = NULL;
  return temp;
}
inline void CheckUnameResp::set_allocated_header(::protocol::MsgHead* header) {
  delete header_;
  header_ = header;
  if (header) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameResp.Header)
}

// string Seq = 2;
inline void CheckUnameResp::clear_seq() {
  seq_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CheckUnameResp::seq() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameResp.Seq)
  return seq_.GetNoArena();
}
inline void CheckUnameResp::set_seq(const ::std::string& value) {
  
  seq_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protocol.CheckUnameResp.Seq)
}
#if LANG_CXX11
inline void CheckUnameResp::set_seq(::std::string&& value) {
  
  seq_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.CheckUnameResp.Seq)
}
#endif
inline void CheckUnameResp::set_seq(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  seq_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.CheckUnameResp.Seq)
}
inline void CheckUnameResp::set_seq(const char* value, size_t size) {
  
  seq_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.CheckUnameResp.Seq)
}
inline ::std::string* CheckUnameResp::mutable_seq() {
  
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameResp.Seq)
  return seq_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CheckUnameResp::release_seq() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameResp.Seq)
  
  return seq_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CheckUnameResp::set_allocated_seq(::std::string* seq) {
  if (seq != NULL) {
    
  } else {
    
  }
  seq_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), seq);
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameResp.Seq)
}

// int64 Result = 3;
inline void CheckUnameResp::clear_result() {
  result_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 CheckUnameResp::result() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameResp.Result)
  return result_;
}
inline void CheckUnameResp::set_result(::google::protobuf::int64 value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:protocol.CheckUnameResp.Result)
}

// string Msg = 4;
inline void CheckUnameResp::clear_msg() {
  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CheckUnameResp::msg() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameResp.Msg)
  return msg_.GetNoArena();
}
inline void CheckUnameResp::set_msg(const ::std::string& value) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protocol.CheckUnameResp.Msg)
}
#if LANG_CXX11
inline void CheckUnameResp::set_msg(::std::string&& value) {
  
  msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.CheckUnameResp.Msg)
}
#endif
inline void CheckUnameResp::set_msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.CheckUnameResp.Msg)
}
inline void CheckUnameResp::set_msg(const char* value, size_t size) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.CheckUnameResp.Msg)
}
inline ::std::string* CheckUnameResp::mutable_msg() {
  
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameResp.Msg)
  return msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CheckUnameResp::release_msg() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameResp.Msg)
  
  return msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CheckUnameResp::set_allocated_msg(::std::string* msg) {
  if (msg != NULL) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameResp.Msg)
}

// string Uname = 5;
inline void CheckUnameResp::clear_uname() {
  uname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CheckUnameResp::uname() const {
  // @@protoc_insertion_point(field_get:protocol.CheckUnameResp.Uname)
  return uname_.GetNoArena();
}
inline void CheckUnameResp::set_uname(const ::std::string& value) {
  
  uname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protocol.CheckUnameResp.Uname)
}
#if LANG_CXX11
inline void CheckUnameResp::set_uname(::std::string&& value) {
  
  uname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.CheckUnameResp.Uname)
}
#endif
inline void CheckUnameResp::set_uname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  uname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.CheckUnameResp.Uname)
}
inline void CheckUnameResp::set_uname(const char* value, size_t size) {
  
  uname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.CheckUnameResp.Uname)
}
inline ::std::string* CheckUnameResp::mutable_uname() {
  
  // @@protoc_insertion_point(field_mutable:protocol.CheckUnameResp.Uname)
  return uname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CheckUnameResp::release_uname() {
  // @@protoc_insertion_point(field_release:protocol.CheckUnameResp.Uname)
  
  return uname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CheckUnameResp::set_allocated_uname(::std::string* uname) {
  if (uname != NULL) {
    
  } else {
    
  }
  uname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), uname);
  // @@protoc_insertion_point(field_set_allocated:protocol.CheckUnameResp.Uname)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace protocol

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_acc_5fcheckuname_2eproto__INCLUDED