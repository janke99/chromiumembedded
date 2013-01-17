// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
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

#include "libcef_dll/cpptoc/drag_data_cpptoc.h"
#include "libcef_dll/transfer_util.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK drag_data_is_link(struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefDragDataCppToC::Get(self)->IsLink();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK drag_data_is_fragment(struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefDragDataCppToC::Get(self)->IsFragment();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK drag_data_is_file(struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefDragDataCppToC::Get(self)->IsFile();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK drag_data_get_link_url(
    struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDragDataCppToC::Get(self)->GetLinkURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK drag_data_get_link_title(
    struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDragDataCppToC::Get(self)->GetLinkTitle();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK drag_data_get_link_metadata(
    struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDragDataCppToC::Get(self)->GetLinkMetadata();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK drag_data_get_fragment_text(
    struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDragDataCppToC::Get(self)->GetFragmentText();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK drag_data_get_fragment_html(
    struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDragDataCppToC::Get(self)->GetFragmentHtml();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK drag_data_get_fragment_base_url(
    struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDragDataCppToC::Get(self)->GetFragmentBaseURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK drag_data_get_file_name(
    struct _cef_drag_data_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefDragDataCppToC::Get(self)->GetFileName();

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK drag_data_get_file_names(struct _cef_drag_data_t* self,
    cef_string_list_t names) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: names; type: string_vec_byref
  DCHECK(names);
  if (!names)
    return 0;

  // Translate param: names; type: string_vec_byref
  std::vector<CefString> namesList;
  transfer_string_list_contents(names, namesList);

  // Execute
  bool _retval = CefDragDataCppToC::Get(self)->GetFileNames(
      namesList);

  // Restore param: names; type: string_vec_byref
  cef_string_list_clear(names);
  transfer_string_list_contents(namesList, names);

  // Return type: bool
  return _retval;
}


// CONSTRUCTOR - Do not edit by hand.

CefDragDataCppToC::CefDragDataCppToC(CefDragData* cls)
    : CefCppToC<CefDragDataCppToC, CefDragData, cef_drag_data_t>(cls) {
  struct_.struct_.is_link = drag_data_is_link;
  struct_.struct_.is_fragment = drag_data_is_fragment;
  struct_.struct_.is_file = drag_data_is_file;
  struct_.struct_.get_link_url = drag_data_get_link_url;
  struct_.struct_.get_link_title = drag_data_get_link_title;
  struct_.struct_.get_link_metadata = drag_data_get_link_metadata;
  struct_.struct_.get_fragment_text = drag_data_get_fragment_text;
  struct_.struct_.get_fragment_html = drag_data_get_fragment_html;
  struct_.struct_.get_fragment_base_url = drag_data_get_fragment_base_url;
  struct_.struct_.get_file_name = drag_data_get_file_name;
  struct_.struct_.get_file_names = drag_data_get_file_names;
}

#ifndef NDEBUG
template<> long CefCppToC<CefDragDataCppToC, CefDragData,
    cef_drag_data_t>::DebugObjCt = 0;
#endif

