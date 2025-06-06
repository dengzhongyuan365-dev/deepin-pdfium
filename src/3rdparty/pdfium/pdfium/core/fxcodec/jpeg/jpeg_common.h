// Copyright 2020 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FXCODEC_JPEG_JPEG_COMMON_H_
#define CORE_FXCODEC_JPEG_JPEG_COMMON_H_

// Common code for interacting with libjpeg shared by other files in
// core/fxcodec/jpeg/. Not intended to be included in headers.

#include <stdio.h>

extern "C" {

#include <jerror.h>
#include <jpeglib.h>

void src_do_nothing(jpeg_decompress_struct* cinfo);
boolean src_fill_buffer(j_decompress_ptr cinfo);
boolean src_resync(j_decompress_ptr cinfo, int desired);
void error_do_nothing(j_common_ptr cinfo);
void error_do_nothing_int(j_common_ptr cinfo, int);
void error_do_nothing_char(j_common_ptr cinfo, char*);

}  // extern "C"

#endif  // CORE_FXCODEC_JPEG_JPEG_COMMON_H_
