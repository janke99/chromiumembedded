// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/run_file_dialog_callback_cpptoc.h"
#include "libcef_dll/ctocpp/browser_host_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK run_file_dialog_callback_cont(
    struct _cef_run_file_dialog_callback_t* self,
    struct _cef_browser_host_t* browser_host, cef_string_list_t file_paths) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser_host; type: refptr_diff
  DCHECK(browser_host);
  if (!browser_host)
    return;
  // Verify param: file_paths; type: string_vec_byref_const
  DCHECK(file_paths);
  if (!file_paths)
    return;

  // Translate param: file_paths; type: string_vec_byref_const
  std::vector<CefString> file_pathsList;
  transfer_string_list_contents(file_paths, file_pathsList);

  // Execute
  CefRunFileDialogCallbackCppToC::Get(self)->OnFileDialogDismissed(
      CefBrowserHostCToCpp::Wrap(browser_host),
      file_pathsList);
}


// CONSTRUCTOR - Do not edit by hand.

CefRunFileDialogCallbackCppToC::CefRunFileDialogCallbackCppToC(
    CefRunFileDialogCallback* cls)
    : CefCppToC<CefRunFileDialogCallbackCppToC, CefRunFileDialogCallback,
        cef_run_file_dialog_callback_t>(cls) {
  struct_.struct_.cont = run_file_dialog_callback_cont;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefRunFileDialogCallbackCppToC,
    CefRunFileDialogCallback, cef_run_file_dialog_callback_t>::DebugObjCt = 0;
#endif

