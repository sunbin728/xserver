// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: getexpress.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "getexpress.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace NetProto {
class GetExpressReqDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<GetExpressReq> {
} _GetExpressReq_default_instance_;
class ExpressRespDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<ExpressResp> {
} _ExpressResp_default_instance_;

namespace protobuf_getexpress_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[2];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] = {
  { NULL, NULL, 0, -1, -1, false },
  { NULL, NULL, 0, -1, -1, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetExpressReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetExpressReq, express_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpressResp, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpressResp, obj_uuid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpressResp, item_id_),
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, -1, sizeof(GetExpressReq)},
  { 6, -1, sizeof(ExpressResp)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_GetExpressReq_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_ExpressResp_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "getexpress.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

}  // namespace

void TableStruct::Shutdown() {
  _GetExpressReq_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
  _ExpressResp_default_instance_.Shutdown();
  delete file_level_metadata[1].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _GetExpressReq_default_instance_.DefaultConstruct();
  _ExpressResp_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\020getexpress.proto\022\010NetProto\" \n\rGetExpre"
      "ssReq\022\017\n\007express\030\001 \001(\t\"0\n\013ExpressResp\022\020\n"
      "\010obj_uuid\030\001 \001(\t\022\017\n\007item_id\030\002 \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 120);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "getexpress.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_getexpress_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GetExpressReq::kExpressFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GetExpressReq::GetExpressReq()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_getexpress_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:NetProto.GetExpressReq)
}
GetExpressReq::GetExpressReq(const GetExpressReq& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  express_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.express().size() > 0) {
    express_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.express_);
  }
  // @@protoc_insertion_point(copy_constructor:NetProto.GetExpressReq)
}

void GetExpressReq::SharedCtor() {
  express_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

GetExpressReq::~GetExpressReq() {
  // @@protoc_insertion_point(destructor:NetProto.GetExpressReq)
  SharedDtor();
}

void GetExpressReq::SharedDtor() {
  express_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void GetExpressReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetExpressReq::descriptor() {
  protobuf_getexpress_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_getexpress_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GetExpressReq& GetExpressReq::default_instance() {
  protobuf_getexpress_2eproto::InitDefaults();
  return *internal_default_instance();
}

GetExpressReq* GetExpressReq::New(::google::protobuf::Arena* arena) const {
  GetExpressReq* n = new GetExpressReq;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GetExpressReq::Clear() {
// @@protoc_insertion_point(message_clear_start:NetProto.GetExpressReq)
  express_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool GetExpressReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NetProto.GetExpressReq)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string express = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_express()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->express().data(), this->express().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "NetProto.GetExpressReq.express"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:NetProto.GetExpressReq)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NetProto.GetExpressReq)
  return false;
#undef DO_
}

void GetExpressReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NetProto.GetExpressReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string express = 1;
  if (this->express().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->express().data(), this->express().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.GetExpressReq.express");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->express(), output);
  }

  // @@protoc_insertion_point(serialize_end:NetProto.GetExpressReq)
}

::google::protobuf::uint8* GetExpressReq::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:NetProto.GetExpressReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string express = 1;
  if (this->express().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->express().data(), this->express().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.GetExpressReq.express");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->express(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:NetProto.GetExpressReq)
  return target;
}

size_t GetExpressReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NetProto.GetExpressReq)
  size_t total_size = 0;

  // string express = 1;
  if (this->express().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->express());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetExpressReq::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NetProto.GetExpressReq)
  GOOGLE_DCHECK_NE(&from, this);
  const GetExpressReq* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GetExpressReq>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NetProto.GetExpressReq)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NetProto.GetExpressReq)
    MergeFrom(*source);
  }
}

void GetExpressReq::MergeFrom(const GetExpressReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NetProto.GetExpressReq)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.express().size() > 0) {

    express_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.express_);
  }
}

void GetExpressReq::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NetProto.GetExpressReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetExpressReq::CopyFrom(const GetExpressReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NetProto.GetExpressReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetExpressReq::IsInitialized() const {
  return true;
}

void GetExpressReq::Swap(GetExpressReq* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GetExpressReq::InternalSwap(GetExpressReq* other) {
  express_.Swap(&other->express_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GetExpressReq::GetMetadata() const {
  protobuf_getexpress_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_getexpress_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GetExpressReq

// string express = 1;
void GetExpressReq::clear_express() {
  express_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& GetExpressReq::express() const {
  // @@protoc_insertion_point(field_get:NetProto.GetExpressReq.express)
  return express_.GetNoArena();
}
void GetExpressReq::set_express(const ::std::string& value) {
  
  express_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.GetExpressReq.express)
}
#if LANG_CXX11
void GetExpressReq::set_express(::std::string&& value) {
  
  express_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.GetExpressReq.express)
}
#endif
void GetExpressReq::set_express(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  express_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.GetExpressReq.express)
}
void GetExpressReq::set_express(const char* value, size_t size) {
  
  express_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.GetExpressReq.express)
}
::std::string* GetExpressReq::mutable_express() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.GetExpressReq.express)
  return express_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* GetExpressReq::release_express() {
  // @@protoc_insertion_point(field_release:NetProto.GetExpressReq.express)
  
  return express_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void GetExpressReq::set_allocated_express(::std::string* express) {
  if (express != NULL) {
    
  } else {
    
  }
  express_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), express);
  // @@protoc_insertion_point(field_set_allocated:NetProto.GetExpressReq.express)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ExpressResp::kObjUuidFieldNumber;
const int ExpressResp::kItemIdFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ExpressResp::ExpressResp()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_getexpress_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:NetProto.ExpressResp)
}
ExpressResp::ExpressResp(const ExpressResp& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  obj_uuid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.obj_uuid().size() > 0) {
    obj_uuid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.obj_uuid_);
  }
  item_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.item_id().size() > 0) {
    item_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.item_id_);
  }
  // @@protoc_insertion_point(copy_constructor:NetProto.ExpressResp)
}

void ExpressResp::SharedCtor() {
  obj_uuid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  item_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

ExpressResp::~ExpressResp() {
  // @@protoc_insertion_point(destructor:NetProto.ExpressResp)
  SharedDtor();
}

void ExpressResp::SharedDtor() {
  obj_uuid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  item_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ExpressResp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ExpressResp::descriptor() {
  protobuf_getexpress_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_getexpress_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ExpressResp& ExpressResp::default_instance() {
  protobuf_getexpress_2eproto::InitDefaults();
  return *internal_default_instance();
}

ExpressResp* ExpressResp::New(::google::protobuf::Arena* arena) const {
  ExpressResp* n = new ExpressResp;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ExpressResp::Clear() {
// @@protoc_insertion_point(message_clear_start:NetProto.ExpressResp)
  obj_uuid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  item_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool ExpressResp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NetProto.ExpressResp)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string obj_uuid = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_obj_uuid()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->obj_uuid().data(), this->obj_uuid().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "NetProto.ExpressResp.obj_uuid"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string item_id = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_item_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->item_id().data(), this->item_id().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "NetProto.ExpressResp.item_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:NetProto.ExpressResp)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NetProto.ExpressResp)
  return false;
#undef DO_
}

void ExpressResp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NetProto.ExpressResp)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string obj_uuid = 1;
  if (this->obj_uuid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->obj_uuid().data(), this->obj_uuid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ExpressResp.obj_uuid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->obj_uuid(), output);
  }

  // string item_id = 2;
  if (this->item_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->item_id().data(), this->item_id().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ExpressResp.item_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->item_id(), output);
  }

  // @@protoc_insertion_point(serialize_end:NetProto.ExpressResp)
}

::google::protobuf::uint8* ExpressResp::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:NetProto.ExpressResp)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string obj_uuid = 1;
  if (this->obj_uuid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->obj_uuid().data(), this->obj_uuid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ExpressResp.obj_uuid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->obj_uuid(), target);
  }

  // string item_id = 2;
  if (this->item_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->item_id().data(), this->item_id().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ExpressResp.item_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->item_id(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:NetProto.ExpressResp)
  return target;
}

size_t ExpressResp::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NetProto.ExpressResp)
  size_t total_size = 0;

  // string obj_uuid = 1;
  if (this->obj_uuid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->obj_uuid());
  }

  // string item_id = 2;
  if (this->item_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->item_id());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ExpressResp::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NetProto.ExpressResp)
  GOOGLE_DCHECK_NE(&from, this);
  const ExpressResp* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ExpressResp>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NetProto.ExpressResp)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NetProto.ExpressResp)
    MergeFrom(*source);
  }
}

void ExpressResp::MergeFrom(const ExpressResp& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NetProto.ExpressResp)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.obj_uuid().size() > 0) {

    obj_uuid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.obj_uuid_);
  }
  if (from.item_id().size() > 0) {

    item_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.item_id_);
  }
}

void ExpressResp::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NetProto.ExpressResp)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ExpressResp::CopyFrom(const ExpressResp& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NetProto.ExpressResp)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ExpressResp::IsInitialized() const {
  return true;
}

void ExpressResp::Swap(ExpressResp* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ExpressResp::InternalSwap(ExpressResp* other) {
  obj_uuid_.Swap(&other->obj_uuid_);
  item_id_.Swap(&other->item_id_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ExpressResp::GetMetadata() const {
  protobuf_getexpress_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_getexpress_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ExpressResp

// string obj_uuid = 1;
void ExpressResp::clear_obj_uuid() {
  obj_uuid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& ExpressResp::obj_uuid() const {
  // @@protoc_insertion_point(field_get:NetProto.ExpressResp.obj_uuid)
  return obj_uuid_.GetNoArena();
}
void ExpressResp::set_obj_uuid(const ::std::string& value) {
  
  obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.ExpressResp.obj_uuid)
}
#if LANG_CXX11
void ExpressResp::set_obj_uuid(::std::string&& value) {
  
  obj_uuid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.ExpressResp.obj_uuid)
}
#endif
void ExpressResp::set_obj_uuid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.ExpressResp.obj_uuid)
}
void ExpressResp::set_obj_uuid(const char* value, size_t size) {
  
  obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.ExpressResp.obj_uuid)
}
::std::string* ExpressResp::mutable_obj_uuid() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.ExpressResp.obj_uuid)
  return obj_uuid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* ExpressResp::release_obj_uuid() {
  // @@protoc_insertion_point(field_release:NetProto.ExpressResp.obj_uuid)
  
  return obj_uuid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void ExpressResp::set_allocated_obj_uuid(::std::string* obj_uuid) {
  if (obj_uuid != NULL) {
    
  } else {
    
  }
  obj_uuid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), obj_uuid);
  // @@protoc_insertion_point(field_set_allocated:NetProto.ExpressResp.obj_uuid)
}

// string item_id = 2;
void ExpressResp::clear_item_id() {
  item_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& ExpressResp::item_id() const {
  // @@protoc_insertion_point(field_get:NetProto.ExpressResp.item_id)
  return item_id_.GetNoArena();
}
void ExpressResp::set_item_id(const ::std::string& value) {
  
  item_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.ExpressResp.item_id)
}
#if LANG_CXX11
void ExpressResp::set_item_id(::std::string&& value) {
  
  item_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.ExpressResp.item_id)
}
#endif
void ExpressResp::set_item_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  item_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.ExpressResp.item_id)
}
void ExpressResp::set_item_id(const char* value, size_t size) {
  
  item_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.ExpressResp.item_id)
}
::std::string* ExpressResp::mutable_item_id() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.ExpressResp.item_id)
  return item_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* ExpressResp::release_item_id() {
  // @@protoc_insertion_point(field_release:NetProto.ExpressResp.item_id)
  
  return item_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void ExpressResp::set_allocated_item_id(::std::string* item_id) {
  if (item_id != NULL) {
    
  } else {
    
  }
  item_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), item_id);
  // @@protoc_insertion_point(field_set_allocated:NetProto.ExpressResp.item_id)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace NetProto

// @@protoc_insertion_point(global_scope)
