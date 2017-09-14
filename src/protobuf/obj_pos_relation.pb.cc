// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: obj_pos_relation.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "obj_pos_relation.pb.h"

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
class ObjPosRelationDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<ObjPosRelation> {
} _ObjPosRelation_default_instance_;

namespace protobuf_obj_5fpos_5frelation_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

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
};

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjPosRelation, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjPosRelation, obj_uuid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjPosRelation, ref_obj_uuid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ObjPosRelation, relation_),
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, -1, sizeof(ObjPosRelation)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_ObjPosRelation_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "obj_pos_relation.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace

void TableStruct::Shutdown() {
  _ObjPosRelation_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::google::protobuf::protobuf_google_2fprotobuf_2fany_2eproto::InitDefaults();
  _ObjPosRelation_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\026obj_pos_relation.proto\022\010NetProto\032\031goog"
      "le/protobuf/any.proto\"J\n\016ObjPosRelation\022"
      "\020\n\010obj_uuid\030\001 \001(\t\022\024\n\014ref_obj_uuid\030\002 \001(\t\022"
      "\020\n\010relation\030\003 \001(\r*H\n\017PosRelationType\022\010\n\004"
      "None\020\000\022\007\n\002On\020\350\007\022\t\n\004Down\020\320\017\022\n\n\005Aside\020\270\027\022\013"
      "\n\006Inside\020\240\037b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 219);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "obj_pos_relation.proto", &protobuf_RegisterTypes);
  ::google::protobuf::protobuf_google_2fprotobuf_2fany_2eproto::AddDescriptors();
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

}  // namespace protobuf_obj_5fpos_5frelation_2eproto

const ::google::protobuf::EnumDescriptor* PosRelationType_descriptor() {
  protobuf_obj_5fpos_5frelation_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_obj_5fpos_5frelation_2eproto::file_level_enum_descriptors[0];
}
bool PosRelationType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1000:
    case 2000:
    case 3000:
    case 4000:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ObjPosRelation::kObjUuidFieldNumber;
const int ObjPosRelation::kRefObjUuidFieldNumber;
const int ObjPosRelation::kRelationFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ObjPosRelation::ObjPosRelation()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_obj_5fpos_5frelation_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:NetProto.ObjPosRelation)
}
ObjPosRelation::ObjPosRelation(const ObjPosRelation& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  obj_uuid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.obj_uuid().size() > 0) {
    obj_uuid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.obj_uuid_);
  }
  ref_obj_uuid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.ref_obj_uuid().size() > 0) {
    ref_obj_uuid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ref_obj_uuid_);
  }
  relation_ = from.relation_;
  // @@protoc_insertion_point(copy_constructor:NetProto.ObjPosRelation)
}

void ObjPosRelation::SharedCtor() {
  obj_uuid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ref_obj_uuid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  relation_ = 0u;
  _cached_size_ = 0;
}

ObjPosRelation::~ObjPosRelation() {
  // @@protoc_insertion_point(destructor:NetProto.ObjPosRelation)
  SharedDtor();
}

void ObjPosRelation::SharedDtor() {
  obj_uuid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ref_obj_uuid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ObjPosRelation::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ObjPosRelation::descriptor() {
  protobuf_obj_5fpos_5frelation_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_obj_5fpos_5frelation_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ObjPosRelation& ObjPosRelation::default_instance() {
  protobuf_obj_5fpos_5frelation_2eproto::InitDefaults();
  return *internal_default_instance();
}

ObjPosRelation* ObjPosRelation::New(::google::protobuf::Arena* arena) const {
  ObjPosRelation* n = new ObjPosRelation;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ObjPosRelation::Clear() {
// @@protoc_insertion_point(message_clear_start:NetProto.ObjPosRelation)
  obj_uuid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ref_obj_uuid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  relation_ = 0u;
}

bool ObjPosRelation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NetProto.ObjPosRelation)
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
            "NetProto.ObjPosRelation.obj_uuid"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string ref_obj_uuid = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ref_obj_uuid()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->ref_obj_uuid().data(), this->ref_obj_uuid().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "NetProto.ObjPosRelation.ref_obj_uuid"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 relation = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &relation_)));
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
  // @@protoc_insertion_point(parse_success:NetProto.ObjPosRelation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NetProto.ObjPosRelation)
  return false;
#undef DO_
}

void ObjPosRelation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NetProto.ObjPosRelation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string obj_uuid = 1;
  if (this->obj_uuid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->obj_uuid().data(), this->obj_uuid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ObjPosRelation.obj_uuid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->obj_uuid(), output);
  }

  // string ref_obj_uuid = 2;
  if (this->ref_obj_uuid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ref_obj_uuid().data(), this->ref_obj_uuid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ObjPosRelation.ref_obj_uuid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->ref_obj_uuid(), output);
  }

  // uint32 relation = 3;
  if (this->relation() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->relation(), output);
  }

  // @@protoc_insertion_point(serialize_end:NetProto.ObjPosRelation)
}

::google::protobuf::uint8* ObjPosRelation::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:NetProto.ObjPosRelation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string obj_uuid = 1;
  if (this->obj_uuid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->obj_uuid().data(), this->obj_uuid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ObjPosRelation.obj_uuid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->obj_uuid(), target);
  }

  // string ref_obj_uuid = 2;
  if (this->ref_obj_uuid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ref_obj_uuid().data(), this->ref_obj_uuid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "NetProto.ObjPosRelation.ref_obj_uuid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->ref_obj_uuid(), target);
  }

  // uint32 relation = 3;
  if (this->relation() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->relation(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:NetProto.ObjPosRelation)
  return target;
}

size_t ObjPosRelation::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NetProto.ObjPosRelation)
  size_t total_size = 0;

  // string obj_uuid = 1;
  if (this->obj_uuid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->obj_uuid());
  }

  // string ref_obj_uuid = 2;
  if (this->ref_obj_uuid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->ref_obj_uuid());
  }

  // uint32 relation = 3;
  if (this->relation() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->relation());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ObjPosRelation::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NetProto.ObjPosRelation)
  GOOGLE_DCHECK_NE(&from, this);
  const ObjPosRelation* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ObjPosRelation>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NetProto.ObjPosRelation)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NetProto.ObjPosRelation)
    MergeFrom(*source);
  }
}

void ObjPosRelation::MergeFrom(const ObjPosRelation& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NetProto.ObjPosRelation)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.obj_uuid().size() > 0) {

    obj_uuid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.obj_uuid_);
  }
  if (from.ref_obj_uuid().size() > 0) {

    ref_obj_uuid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ref_obj_uuid_);
  }
  if (from.relation() != 0) {
    set_relation(from.relation());
  }
}

void ObjPosRelation::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NetProto.ObjPosRelation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ObjPosRelation::CopyFrom(const ObjPosRelation& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NetProto.ObjPosRelation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObjPosRelation::IsInitialized() const {
  return true;
}

void ObjPosRelation::Swap(ObjPosRelation* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ObjPosRelation::InternalSwap(ObjPosRelation* other) {
  obj_uuid_.Swap(&other->obj_uuid_);
  ref_obj_uuid_.Swap(&other->ref_obj_uuid_);
  std::swap(relation_, other->relation_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ObjPosRelation::GetMetadata() const {
  protobuf_obj_5fpos_5frelation_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_obj_5fpos_5frelation_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ObjPosRelation

// string obj_uuid = 1;
void ObjPosRelation::clear_obj_uuid() {
  obj_uuid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& ObjPosRelation::obj_uuid() const {
  // @@protoc_insertion_point(field_get:NetProto.ObjPosRelation.obj_uuid)
  return obj_uuid_.GetNoArena();
}
void ObjPosRelation::set_obj_uuid(const ::std::string& value) {
  
  obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.ObjPosRelation.obj_uuid)
}
#if LANG_CXX11
void ObjPosRelation::set_obj_uuid(::std::string&& value) {
  
  obj_uuid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.ObjPosRelation.obj_uuid)
}
#endif
void ObjPosRelation::set_obj_uuid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.ObjPosRelation.obj_uuid)
}
void ObjPosRelation::set_obj_uuid(const char* value, size_t size) {
  
  obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.ObjPosRelation.obj_uuid)
}
::std::string* ObjPosRelation::mutable_obj_uuid() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.ObjPosRelation.obj_uuid)
  return obj_uuid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* ObjPosRelation::release_obj_uuid() {
  // @@protoc_insertion_point(field_release:NetProto.ObjPosRelation.obj_uuid)
  
  return obj_uuid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void ObjPosRelation::set_allocated_obj_uuid(::std::string* obj_uuid) {
  if (obj_uuid != NULL) {
    
  } else {
    
  }
  obj_uuid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), obj_uuid);
  // @@protoc_insertion_point(field_set_allocated:NetProto.ObjPosRelation.obj_uuid)
}

// string ref_obj_uuid = 2;
void ObjPosRelation::clear_ref_obj_uuid() {
  ref_obj_uuid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& ObjPosRelation::ref_obj_uuid() const {
  // @@protoc_insertion_point(field_get:NetProto.ObjPosRelation.ref_obj_uuid)
  return ref_obj_uuid_.GetNoArena();
}
void ObjPosRelation::set_ref_obj_uuid(const ::std::string& value) {
  
  ref_obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.ObjPosRelation.ref_obj_uuid)
}
#if LANG_CXX11
void ObjPosRelation::set_ref_obj_uuid(::std::string&& value) {
  
  ref_obj_uuid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.ObjPosRelation.ref_obj_uuid)
}
#endif
void ObjPosRelation::set_ref_obj_uuid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  ref_obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.ObjPosRelation.ref_obj_uuid)
}
void ObjPosRelation::set_ref_obj_uuid(const char* value, size_t size) {
  
  ref_obj_uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.ObjPosRelation.ref_obj_uuid)
}
::std::string* ObjPosRelation::mutable_ref_obj_uuid() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.ObjPosRelation.ref_obj_uuid)
  return ref_obj_uuid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* ObjPosRelation::release_ref_obj_uuid() {
  // @@protoc_insertion_point(field_release:NetProto.ObjPosRelation.ref_obj_uuid)
  
  return ref_obj_uuid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void ObjPosRelation::set_allocated_ref_obj_uuid(::std::string* ref_obj_uuid) {
  if (ref_obj_uuid != NULL) {
    
  } else {
    
  }
  ref_obj_uuid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ref_obj_uuid);
  // @@protoc_insertion_point(field_set_allocated:NetProto.ObjPosRelation.ref_obj_uuid)
}

// uint32 relation = 3;
void ObjPosRelation::clear_relation() {
  relation_ = 0u;
}
::google::protobuf::uint32 ObjPosRelation::relation() const {
  // @@protoc_insertion_point(field_get:NetProto.ObjPosRelation.relation)
  return relation_;
}
void ObjPosRelation::set_relation(::google::protobuf::uint32 value) {
  
  relation_ = value;
  // @@protoc_insertion_point(field_set:NetProto.ObjPosRelation.relation)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace NetProto

// @@protoc_insertion_point(global_scope)
