// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: role_status_event.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "role_status_event.pb.h"

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

namespace protobuf_role_5fstatus_5fevent_2eproto {


namespace {

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

const ::google::protobuf::uint32 TableStruct::offsets[] = { ~0u };
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;
namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "role_status_event.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void TableStruct::Shutdown() {
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\027role_status_event.proto\022\010NetProto*\340\004\n\017"
      "RoleStatusEvent\022\010\n\004Open\020\000\022\t\n\005Close\020\001\022\n\n\006"
      "Ignite\020\002\022\013\n\007Put_out\020\003\022\t\n\005Drink\020\004\022\013\n\007NoDr"
      "ink\020\005\022\007\n\003Eat\020\006\022\t\n\005NoEat\020\007\022\t\n\005Taste\020\010\022\013\n\007"
      "NoTaste\020\t\022\007\n\003Sit\020\n\022\t\n\005NoSit\020\013\022\013\n\007SitEdge"
      "\020\014\022\r\n\tNoSitEdge\020\r\022\013\n\007LyingOn\020\016\022\r\n\tNoLyin"
      "gOn\020\017\022\n\n\006Taking\020\020\022\014\n\010NoTaking\020\021\022\007\n\003See\020\022"
      "\022\t\n\005NoSee\020\023\022\014\n\010Internet\020\024\022\016\n\nNoInternet\020"
      "\025\022\r\n\tListening\020\026\022\017\n\013NoListening\020\027\022\013\n\007Bat"
      "hing\020\030\022\r\n\tNoBathing\020\031\022\010\n\004Daze\020\032\022\n\n\006NoDaz"
      "e\020\033\022\014\n\010RestMind\020\034\022\016\n\nNoRestMind\020\035\022\t\n\005Sle"
      "ep\020\036\022\013\n\007NoSleep\020\037\022\t\n\005Stand\020 \022\013\n\007NoStand\020"
      "!\022\n\n\006Follow\020\"\022\014\n\010NoFollow\020#\022\t\n\005Stare\020$\022\013"
      "\n\007NoStare\020%\022\013\n\007Emotion\020&\022\014\n\010Changing\020\'\022\013"
      "\n\007Changed\020(\022\t\n\005Dress\020)\022\014\n\010Recharge\020*\022\016\n\n"
      "NoRecharge\020+\022\016\n\nRandomWalk\020,\022\020\n\014NoRandom"
      "Walk\020-b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 654);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "role_status_event.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_role_5fstatus_5fevent_2eproto

const ::google::protobuf::EnumDescriptor* RoleStatusEvent_descriptor() {
  protobuf_role_5fstatus_5fevent_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_role_5fstatus_5fevent_2eproto::file_level_enum_descriptors[0];
}
bool RoleStatusEvent_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace NetProto

// @@protoc_insertion_point(global_scope)