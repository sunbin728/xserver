// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: player_login.proto

#ifndef PROTOBUF_player_5flogin_2eproto__INCLUDED
#define PROTOBUF_player_5flogin_2eproto__INCLUDED

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
#include "robot_info.pb.h"
#include "msg_head.pb.h"
// @@protoc_insertion_point(includes)
namespace NetProto {
class MsgHead;
class MsgHeadDefaultTypeInternal;
extern MsgHeadDefaultTypeInternal _MsgHead_default_instance_;
class RobotInfo;
class RobotInfoDefaultTypeInternal;
extern RobotInfoDefaultTypeInternal _RobotInfo_default_instance_;
class RobotOffline;
class RobotOfflineDefaultTypeInternal;
extern RobotOfflineDefaultTypeInternal _RobotOffline_default_instance_;
namespace CS {
class GetRobotSceneMapData;
class GetRobotSceneMapDataDefaultTypeInternal;
extern GetRobotSceneMapDataDefaultTypeInternal _GetRobotSceneMapData_default_instance_;
class OnlineLoginReq;
class OnlineLoginReqDefaultTypeInternal;
extern OnlineLoginReqDefaultTypeInternal _OnlineLoginReq_default_instance_;
class OnlineLoginResp;
class OnlineLoginRespDefaultTypeInternal;
extern OnlineLoginRespDefaultTypeInternal _OnlineLoginResp_default_instance_;
}  // namespace CS
}  // namespace NetProto

namespace NetProto {
namespace CS {

namespace protobuf_player_5flogin_2eproto {
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
}  // namespace protobuf_player_5flogin_2eproto

// ===================================================================

class OnlineLoginReq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.CS.OnlineLoginReq) */ {
 public:
  OnlineLoginReq();
  virtual ~OnlineLoginReq();

  OnlineLoginReq(const OnlineLoginReq& from);

  inline OnlineLoginReq& operator=(const OnlineLoginReq& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const OnlineLoginReq& default_instance();

  static inline const OnlineLoginReq* internal_default_instance() {
    return reinterpret_cast<const OnlineLoginReq*>(
               &_OnlineLoginReq_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(OnlineLoginReq* other);

  // implements Message ----------------------------------------------

  inline OnlineLoginReq* New() const PROTOBUF_FINAL { return New(NULL); }

  OnlineLoginReq* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const OnlineLoginReq& from);
  void MergeFrom(const OnlineLoginReq& from);
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
  void InternalSwap(OnlineLoginReq* other);
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

  // string session_id = 20;
  void clear_session_id();
  static const int kSessionIdFieldNumber = 20;
  const ::std::string& session_id() const;
  void set_session_id(const ::std::string& value);
  #if LANG_CXX11
  void set_session_id(::std::string&& value);
  #endif
  void set_session_id(const char* value);
  void set_session_id(const char* value, size_t size);
  ::std::string* mutable_session_id();
  ::std::string* release_session_id();
  void set_allocated_session_id(::std::string* session_id);

  // uint32 user_id = 10;
  void clear_user_id();
  static const int kUserIdFieldNumber = 10;
  ::google::protobuf::uint32 user_id() const;
  void set_user_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetProto.CS.OnlineLoginReq)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr session_id_;
  ::google::protobuf::uint32 user_id_;
  mutable int _cached_size_;
  friend struct protobuf_player_5flogin_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class OnlineLoginResp : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.CS.OnlineLoginResp) */ {
 public:
  OnlineLoginResp();
  virtual ~OnlineLoginResp();

  OnlineLoginResp(const OnlineLoginResp& from);

  inline OnlineLoginResp& operator=(const OnlineLoginResp& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const OnlineLoginResp& default_instance();

  static inline const OnlineLoginResp* internal_default_instance() {
    return reinterpret_cast<const OnlineLoginResp*>(
               &_OnlineLoginResp_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(OnlineLoginResp* other);

  // implements Message ----------------------------------------------

  inline OnlineLoginResp* New() const PROTOBUF_FINAL { return New(NULL); }

  OnlineLoginResp* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const OnlineLoginResp& from);
  void MergeFrom(const OnlineLoginResp& from);
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
  void InternalSwap(OnlineLoginResp* other);
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

  // repeated .NetProto.RobotInfo robot_list = 1;
  int robot_list_size() const;
  void clear_robot_list();
  static const int kRobotListFieldNumber = 1;
  const ::NetProto::RobotInfo& robot_list(int index) const;
  ::NetProto::RobotInfo* mutable_robot_list(int index);
  ::NetProto::RobotInfo* add_robot_list();
  ::google::protobuf::RepeatedPtrField< ::NetProto::RobotInfo >*
      mutable_robot_list();
  const ::google::protobuf::RepeatedPtrField< ::NetProto::RobotInfo >&
      robot_list() const;

  // @@protoc_insertion_point(class_scope:NetProto.CS.OnlineLoginResp)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::NetProto::RobotInfo > robot_list_;
  mutable int _cached_size_;
  friend struct protobuf_player_5flogin_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class GetRobotSceneMapData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.CS.GetRobotSceneMapData) */ {
 public:
  GetRobotSceneMapData();
  virtual ~GetRobotSceneMapData();

  GetRobotSceneMapData(const GetRobotSceneMapData& from);

  inline GetRobotSceneMapData& operator=(const GetRobotSceneMapData& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetRobotSceneMapData& default_instance();

  static inline const GetRobotSceneMapData* internal_default_instance() {
    return reinterpret_cast<const GetRobotSceneMapData*>(
               &_GetRobotSceneMapData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(GetRobotSceneMapData* other);

  // implements Message ----------------------------------------------

  inline GetRobotSceneMapData* New() const PROTOBUF_FINAL { return New(NULL); }

  GetRobotSceneMapData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GetRobotSceneMapData& from);
  void MergeFrom(const GetRobotSceneMapData& from);
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
  void InternalSwap(GetRobotSceneMapData* other);
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

  // .NetProto.MsgHead msg_head = 1;
  bool has_msg_head() const;
  void clear_msg_head();
  static const int kMsgHeadFieldNumber = 1;
  const ::NetProto::MsgHead& msg_head() const;
  ::NetProto::MsgHead* mutable_msg_head();
  ::NetProto::MsgHead* release_msg_head();
  void set_allocated_msg_head(::NetProto::MsgHead* msg_head);

  // uint32 map_id = 2;
  void clear_map_id();
  static const int kMapIdFieldNumber = 2;
  ::google::protobuf::uint32 map_id() const;
  void set_map_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetProto.CS.GetRobotSceneMapData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::NetProto::MsgHead* msg_head_;
  ::google::protobuf::uint32 map_id_;
  mutable int _cached_size_;
  friend struct protobuf_player_5flogin_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// OnlineLoginReq

// uint32 user_id = 10;
inline void OnlineLoginReq::clear_user_id() {
  user_id_ = 0u;
}
inline ::google::protobuf::uint32 OnlineLoginReq::user_id() const {
  // @@protoc_insertion_point(field_get:NetProto.CS.OnlineLoginReq.user_id)
  return user_id_;
}
inline void OnlineLoginReq::set_user_id(::google::protobuf::uint32 value) {
  
  user_id_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CS.OnlineLoginReq.user_id)
}

// string session_id = 20;
inline void OnlineLoginReq::clear_session_id() {
  session_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& OnlineLoginReq::session_id() const {
  // @@protoc_insertion_point(field_get:NetProto.CS.OnlineLoginReq.session_id)
  return session_id_.GetNoArena();
}
inline void OnlineLoginReq::set_session_id(const ::std::string& value) {
  
  session_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.CS.OnlineLoginReq.session_id)
}
#if LANG_CXX11
inline void OnlineLoginReq::set_session_id(::std::string&& value) {
  
  session_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.CS.OnlineLoginReq.session_id)
}
#endif
inline void OnlineLoginReq::set_session_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  session_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.CS.OnlineLoginReq.session_id)
}
inline void OnlineLoginReq::set_session_id(const char* value, size_t size) {
  
  session_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.CS.OnlineLoginReq.session_id)
}
inline ::std::string* OnlineLoginReq::mutable_session_id() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.CS.OnlineLoginReq.session_id)
  return session_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* OnlineLoginReq::release_session_id() {
  // @@protoc_insertion_point(field_release:NetProto.CS.OnlineLoginReq.session_id)
  
  return session_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void OnlineLoginReq::set_allocated_session_id(::std::string* session_id) {
  if (session_id != NULL) {
    
  } else {
    
  }
  session_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), session_id);
  // @@protoc_insertion_point(field_set_allocated:NetProto.CS.OnlineLoginReq.session_id)
}

// -------------------------------------------------------------------

// OnlineLoginResp

// repeated .NetProto.RobotInfo robot_list = 1;
inline int OnlineLoginResp::robot_list_size() const {
  return robot_list_.size();
}
inline void OnlineLoginResp::clear_robot_list() {
  robot_list_.Clear();
}
inline const ::NetProto::RobotInfo& OnlineLoginResp::robot_list(int index) const {
  // @@protoc_insertion_point(field_get:NetProto.CS.OnlineLoginResp.robot_list)
  return robot_list_.Get(index);
}
inline ::NetProto::RobotInfo* OnlineLoginResp::mutable_robot_list(int index) {
  // @@protoc_insertion_point(field_mutable:NetProto.CS.OnlineLoginResp.robot_list)
  return robot_list_.Mutable(index);
}
inline ::NetProto::RobotInfo* OnlineLoginResp::add_robot_list() {
  // @@protoc_insertion_point(field_add:NetProto.CS.OnlineLoginResp.robot_list)
  return robot_list_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::NetProto::RobotInfo >*
OnlineLoginResp::mutable_robot_list() {
  // @@protoc_insertion_point(field_mutable_list:NetProto.CS.OnlineLoginResp.robot_list)
  return &robot_list_;
}
inline const ::google::protobuf::RepeatedPtrField< ::NetProto::RobotInfo >&
OnlineLoginResp::robot_list() const {
  // @@protoc_insertion_point(field_list:NetProto.CS.OnlineLoginResp.robot_list)
  return robot_list_;
}

// -------------------------------------------------------------------

// GetRobotSceneMapData

// .NetProto.MsgHead msg_head = 1;
inline bool GetRobotSceneMapData::has_msg_head() const {
  return this != internal_default_instance() && msg_head_ != NULL;
}
inline void GetRobotSceneMapData::clear_msg_head() {
  if (GetArenaNoVirtual() == NULL && msg_head_ != NULL) delete msg_head_;
  msg_head_ = NULL;
}
inline const ::NetProto::MsgHead& GetRobotSceneMapData::msg_head() const {
  // @@protoc_insertion_point(field_get:NetProto.CS.GetRobotSceneMapData.msg_head)
  return msg_head_ != NULL ? *msg_head_
                         : *::NetProto::MsgHead::internal_default_instance();
}
inline ::NetProto::MsgHead* GetRobotSceneMapData::mutable_msg_head() {
  
  if (msg_head_ == NULL) {
    msg_head_ = new ::NetProto::MsgHead;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.CS.GetRobotSceneMapData.msg_head)
  return msg_head_;
}
inline ::NetProto::MsgHead* GetRobotSceneMapData::release_msg_head() {
  // @@protoc_insertion_point(field_release:NetProto.CS.GetRobotSceneMapData.msg_head)
  
  ::NetProto::MsgHead* temp = msg_head_;
  msg_head_ = NULL;
  return temp;
}
inline void GetRobotSceneMapData::set_allocated_msg_head(::NetProto::MsgHead* msg_head) {
  delete msg_head_;
  msg_head_ = msg_head;
  if (msg_head) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.CS.GetRobotSceneMapData.msg_head)
}

// uint32 map_id = 2;
inline void GetRobotSceneMapData::clear_map_id() {
  map_id_ = 0u;
}
inline ::google::protobuf::uint32 GetRobotSceneMapData::map_id() const {
  // @@protoc_insertion_point(field_get:NetProto.CS.GetRobotSceneMapData.map_id)
  return map_id_;
}
inline void GetRobotSceneMapData::set_map_id(::google::protobuf::uint32 value) {
  
  map_id_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CS.GetRobotSceneMapData.map_id)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace CS
}  // namespace NetProto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_player_5flogin_2eproto__INCLUDED