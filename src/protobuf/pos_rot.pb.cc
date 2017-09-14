// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pos_rot.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "pos_rot.pb.h"

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
class PosRotDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<PosRot> {
} _PosRot_default_instance_;

namespace protobuf_pos_5frot_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

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
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PosRot, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PosRot, rotation_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PosRot, position_),
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, -1, sizeof(PosRot)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_PosRot_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "pos_rot.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
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
  _PosRot_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::NetProto::protobuf_quaternion_2eproto::InitDefaults();
  ::NetProto::protobuf_vector3_2eproto::InitDefaults();
  _PosRot_default_instance_.DefaultConstruct();
  _PosRot_default_instance_.get_mutable()->rotation_ = const_cast< ::NetProto::Quaternion*>(
      ::NetProto::Quaternion::internal_default_instance());
  _PosRot_default_instance_.get_mutable()->position_ = const_cast< ::NetProto::Vector3*>(
      ::NetProto::Vector3::internal_default_instance());
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\rpos_rot.proto\022\010NetProto\032\020quaternion.pr"
      "oto\032\rvector3.proto\"U\n\006PosRot\022&\n\010rotation"
      "\030\001 \001(\0132\024.NetProto.Quaternion\022#\n\010position"
      "\030\002 \001(\0132\021.NetProto.Vector3b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 153);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "pos_rot.proto", &protobuf_RegisterTypes);
  ::NetProto::protobuf_quaternion_2eproto::AddDescriptors();
  ::NetProto::protobuf_vector3_2eproto::AddDescriptors();
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

}  // namespace protobuf_pos_5frot_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PosRot::kRotationFieldNumber;
const int PosRot::kPositionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PosRot::PosRot()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_pos_5frot_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:NetProto.PosRot)
}
PosRot::PosRot(const PosRot& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_rotation()) {
    rotation_ = new ::NetProto::Quaternion(*from.rotation_);
  } else {
    rotation_ = NULL;
  }
  if (from.has_position()) {
    position_ = new ::NetProto::Vector3(*from.position_);
  } else {
    position_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:NetProto.PosRot)
}

void PosRot::SharedCtor() {
  ::memset(&rotation_, 0, reinterpret_cast<char*>(&position_) -
    reinterpret_cast<char*>(&rotation_) + sizeof(position_));
  _cached_size_ = 0;
}

PosRot::~PosRot() {
  // @@protoc_insertion_point(destructor:NetProto.PosRot)
  SharedDtor();
}

void PosRot::SharedDtor() {
  if (this != internal_default_instance()) {
    delete rotation_;
  }
  if (this != internal_default_instance()) {
    delete position_;
  }
}

void PosRot::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PosRot::descriptor() {
  protobuf_pos_5frot_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_pos_5frot_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PosRot& PosRot::default_instance() {
  protobuf_pos_5frot_2eproto::InitDefaults();
  return *internal_default_instance();
}

PosRot* PosRot::New(::google::protobuf::Arena* arena) const {
  PosRot* n = new PosRot;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PosRot::Clear() {
// @@protoc_insertion_point(message_clear_start:NetProto.PosRot)
  if (GetArenaNoVirtual() == NULL && rotation_ != NULL) {
    delete rotation_;
  }
  rotation_ = NULL;
  if (GetArenaNoVirtual() == NULL && position_ != NULL) {
    delete position_;
  }
  position_ = NULL;
}

bool PosRot::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NetProto.PosRot)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .NetProto.Quaternion rotation = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_rotation()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .NetProto.Vector3 position = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_position()));
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
  // @@protoc_insertion_point(parse_success:NetProto.PosRot)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NetProto.PosRot)
  return false;
#undef DO_
}

void PosRot::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NetProto.PosRot)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .NetProto.Quaternion rotation = 1;
  if (this->has_rotation()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->rotation_, output);
  }

  // .NetProto.Vector3 position = 2;
  if (this->has_position()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, *this->position_, output);
  }

  // @@protoc_insertion_point(serialize_end:NetProto.PosRot)
}

::google::protobuf::uint8* PosRot::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:NetProto.PosRot)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .NetProto.Quaternion rotation = 1;
  if (this->has_rotation()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, *this->rotation_, deterministic, target);
  }

  // .NetProto.Vector3 position = 2;
  if (this->has_position()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        2, *this->position_, deterministic, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:NetProto.PosRot)
  return target;
}

size_t PosRot::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NetProto.PosRot)
  size_t total_size = 0;

  // .NetProto.Quaternion rotation = 1;
  if (this->has_rotation()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->rotation_);
  }

  // .NetProto.Vector3 position = 2;
  if (this->has_position()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->position_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PosRot::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NetProto.PosRot)
  GOOGLE_DCHECK_NE(&from, this);
  const PosRot* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PosRot>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NetProto.PosRot)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NetProto.PosRot)
    MergeFrom(*source);
  }
}

void PosRot::MergeFrom(const PosRot& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NetProto.PosRot)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_rotation()) {
    mutable_rotation()->::NetProto::Quaternion::MergeFrom(from.rotation());
  }
  if (from.has_position()) {
    mutable_position()->::NetProto::Vector3::MergeFrom(from.position());
  }
}

void PosRot::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NetProto.PosRot)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PosRot::CopyFrom(const PosRot& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NetProto.PosRot)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PosRot::IsInitialized() const {
  return true;
}

void PosRot::Swap(PosRot* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PosRot::InternalSwap(PosRot* other) {
  std::swap(rotation_, other->rotation_);
  std::swap(position_, other->position_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PosRot::GetMetadata() const {
  protobuf_pos_5frot_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_pos_5frot_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PosRot

// .NetProto.Quaternion rotation = 1;
bool PosRot::has_rotation() const {
  return this != internal_default_instance() && rotation_ != NULL;
}
void PosRot::clear_rotation() {
  if (GetArenaNoVirtual() == NULL && rotation_ != NULL) delete rotation_;
  rotation_ = NULL;
}
const ::NetProto::Quaternion& PosRot::rotation() const {
  // @@protoc_insertion_point(field_get:NetProto.PosRot.rotation)
  return rotation_ != NULL ? *rotation_
                         : *::NetProto::Quaternion::internal_default_instance();
}
::NetProto::Quaternion* PosRot::mutable_rotation() {
  
  if (rotation_ == NULL) {
    rotation_ = new ::NetProto::Quaternion;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.PosRot.rotation)
  return rotation_;
}
::NetProto::Quaternion* PosRot::release_rotation() {
  // @@protoc_insertion_point(field_release:NetProto.PosRot.rotation)
  
  ::NetProto::Quaternion* temp = rotation_;
  rotation_ = NULL;
  return temp;
}
void PosRot::set_allocated_rotation(::NetProto::Quaternion* rotation) {
  delete rotation_;
  rotation_ = rotation;
  if (rotation) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.PosRot.rotation)
}

// .NetProto.Vector3 position = 2;
bool PosRot::has_position() const {
  return this != internal_default_instance() && position_ != NULL;
}
void PosRot::clear_position() {
  if (GetArenaNoVirtual() == NULL && position_ != NULL) delete position_;
  position_ = NULL;
}
const ::NetProto::Vector3& PosRot::position() const {
  // @@protoc_insertion_point(field_get:NetProto.PosRot.position)
  return position_ != NULL ? *position_
                         : *::NetProto::Vector3::internal_default_instance();
}
::NetProto::Vector3* PosRot::mutable_position() {
  
  if (position_ == NULL) {
    position_ = new ::NetProto::Vector3;
  }
  // @@protoc_insertion_point(field_mutable:NetProto.PosRot.position)
  return position_;
}
::NetProto::Vector3* PosRot::release_position() {
  // @@protoc_insertion_point(field_release:NetProto.PosRot.position)
  
  ::NetProto::Vector3* temp = position_;
  position_ = NULL;
  return temp;
}
void PosRot::set_allocated_position(::NetProto::Vector3* position) {
  delete position_;
  position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NetProto.PosRot.position)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace NetProto

// @@protoc_insertion_point(global_scope)
