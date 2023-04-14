// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Author: kenton@google.com (Kenton Varda) and others
//
// Contains basic types and utilities used by the rest of the library.

#ifndef GOOGLE_PROTOBUF_COMMON_H__
#define GOOGLE_PROTOBUF_COMMON_H__

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "absl/strings/string_view.h"
#include "google/protobuf/stubs/platform_macros.h"
#include "google/protobuf/stubs/port.h"

#if defined(__APPLE__)
#include <TargetConditionals.h>  // for TARGET_OS_IPHONE
#endif

#if defined(__ANDROID__) || defined(GOOGLE_PROTOBUF_OS_ANDROID) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || defined(GOOGLE_PROTOBUF_OS_IPHONE)
#include <pthread.h>
#endif

#include "google/protobuf/port_def.inc"

namespace std {}

namespace google {
namespace protobuf {

// This lives in message_lite.h now, but we leave this here for any users that
// #include common.h and not message_lite.h.
PROTOBUF_EXPORT void ShutdownProtobufLibrary();

namespace internal {

// Strongly references the given variable such that the linker will be forced
// to pull in this variable's translation unit.
template <typename T>
void StrongReference(const T& var) {
  auto volatile unused = &var;
  (void)&unused;  // Use address to avoid an extra load of "unused".
}

}  // namespace internal
}  // namespace protobuf
}  // namespace google

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_COMMON_H__
