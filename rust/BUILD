# Protobuf Rust runtime packages.

load("@rules_rust//rust:defs.bzl", "rust_library", "rust_test")
load("@rules_proto//proto:defs.bzl", "proto_lang_toolchain")

package(default_visibility = ["//src/google/protobuf:__subpackages__"])

rust_library(
    name = "protobuf",
    srcs = ["lib.rs"],
    deps = ["//rust/upb_backend:upb"],
)

rust_test(
    name = "protobuf_test",
    crate = ":protobuf",
    tags = [
        "not_build:arm",
        "notsan",
    ],
)

# TODO(b/270125787): Move to the right location once rust_proto_library is no longer experimental.
proto_lang_toolchain(
    name = "proto_lang_toolchain",
    command_line = "--rust_out=experimental-codegen=enabled:$(OUT)",
    progress_message = "Generating Rust proto_library %{label}",
    runtime = ":protobuf",
    visibility = ["//visibility:public"],
)