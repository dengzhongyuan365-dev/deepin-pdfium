// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FXJS_IJS_EVENT_CONTEXT_H_
#define FXJS_IJS_EVENT_CONTEXT_H_

#include "core/fxcrt/fx_string.h"
#include "core/fxcrt/fx_system.h"
#include "fxjs/ijs_runtime.h"
#include "base/optional.h"

class CPDF_Bookmark;
class CPDF_FormField;
class CPDFSDK_Annot;
class CPDFSDK_FormFillEnvironment;

// Records the details of an event and triggers JS execution for it. There
// can be more than one of these at any given time, as JS callbacks to C++
// may trigger new events on top of one another.
class IJS_EventContext {
 public:
  virtual ~IJS_EventContext() = default;

  virtual Optional<IJS_Runtime::JS_Error> RunScript(
      const WideString& script) = 0;

  virtual void OnApp_Init() = 0;

  virtual void OnDoc_Open(CPDFSDK_FormFillEnvironment* pFormFillEnv,
                          const WideString& strTargetName) = 0;
  virtual void OnDoc_WillPrint(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnDoc_DidPrint(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnDoc_WillSave(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnDoc_DidSave(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnDoc_WillClose(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;

  virtual void OnPage_Open(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnPage_Close(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnPage_InView(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnPage_OutView(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;

  virtual void OnField_MouseDown(bool bModifier,
                                 bool bShift,
                                 CPDF_FormField* pTarget) = 0;
  virtual void OnField_MouseEnter(bool bModifier,
                                  bool bShift,
                                  CPDF_FormField* pTarget) = 0;
  virtual void OnField_MouseExit(bool bModifier,
                                 bool bShift,
                                 CPDF_FormField* pTarget) = 0;
  virtual void OnField_MouseUp(bool bModifier,
                               bool bShift,
                               CPDF_FormField* pTarget) = 0;
  virtual void OnField_Focus(bool bModifier,
                             bool bShift,
                             CPDF_FormField* pTarget,
                             WideString* Value) = 0;
  virtual void OnField_Blur(bool bModifier,
                            bool bShift,
                            CPDF_FormField* pTarget,
                            WideString* Value) = 0;
  virtual void OnField_Calculate(CPDF_FormField* pSource,
                                 CPDF_FormField* pTarget,
                                 WideString* Value,
                                 bool* bRc) = 0;
  virtual void OnField_Format(CPDF_FormField* pTarget, WideString* Value) = 0;
  virtual void OnField_Keystroke(WideString* strChange,
                                 const WideString& strChangeEx,
                                 bool KeyDown,
                                 bool bModifier,
                                 int* nSelEnd,
                                 int* nSelStart,
                                 bool bShift,
                                 CPDF_FormField* pTarget,
                                 WideString* Value,
                                 bool bWillCommit,
                                 bool bFieldFull,
                                 bool* bRc) = 0;
  virtual void OnField_Validate(WideString* strChange,
                                const WideString& strChangeEx,
                                bool bKeyDown,
                                bool bModifier,
                                bool bShift,
                                CPDF_FormField* pTarget,
                                WideString* Value,
                                bool* bRc) = 0;

  virtual void OnScreen_Focus(bool bModifier,
                              bool bShift,
                              CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_Blur(bool bModifier,
                             bool bShift,
                             CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_Open(bool bModifier,
                             bool bShift,
                             CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_Close(bool bModifier,
                              bool bShift,
                              CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_MouseDown(bool bModifier,
                                  bool bShift,
                                  CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_MouseUp(bool bModifier,
                                bool bShift,
                                CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_MouseEnter(bool bModifier,
                                   bool bShift,
                                   CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_MouseExit(bool bModifier,
                                  bool bShift,
                                  CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_InView(bool bModifier,
                               bool bShift,
                               CPDFSDK_Annot* pScreen) = 0;
  virtual void OnScreen_OutView(bool bModifier,
                                bool bShift,
                                CPDFSDK_Annot* pScreen) = 0;

  virtual void OnBookmark_MouseUp(CPDF_Bookmark* pBookMark) = 0;
  virtual void OnLink_MouseUp(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;

  virtual void OnMenu_Exec(CPDFSDK_FormFillEnvironment* pFormFillEnv,
                           const WideString&) = 0;
  virtual void OnBatchExec(CPDFSDK_FormFillEnvironment* pFormFillEnv) = 0;
  virtual void OnConsole_Exec() = 0;
  virtual void OnExternal_Exec() = 0;
};

#endif  // FXJS_IJS_EVENT_CONTEXT_H_
