// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/post_data_cpptoc.h"
#include "libcef_dll/cpptoc/request_cpptoc.h"
#include "libcef_dll/transfer_util.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_request_t* cef_request_create()
{
  CefRefPtr<CefRequest> impl = CefRequest::CreateRequest();
  if(impl.get())
    return CefRequestCppToC::Wrap(impl);
  return NULL;
}


// MEMBER FUNCTIONS - Body may be edited by hand.

cef_string_userfree_t CEF_CALLBACK request_get_url(struct _cef_request_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefString urlStr = CefRequestCppToC::Get(self)->GetURL();
  return urlStr.DetachToUserFree();
}

void CEF_CALLBACK request_set_url(struct _cef_request_t* self,
    const cef_string_t* url)
{
  DCHECK(self);
  if(!self)
    return;

  CefRequestCppToC::Get(self)->SetURL(CefString(url));
}

cef_string_userfree_t CEF_CALLBACK request_get_method(
    struct _cef_request_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefString methodStr = CefRequestCppToC::Get(self)->GetMethod();
  return methodStr.DetachToUserFree();
}

void CEF_CALLBACK request_set_method(struct _cef_request_t* self,
    const cef_string_t* method)
{
  DCHECK(self);
  if(!self)
    return;

  CefRequestCppToC::Get(self)->SetMethod(CefString(method));
}

struct _cef_post_data_t* CEF_CALLBACK request_get_post_data(
    struct _cef_request_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefRefPtr<CefPostData> postDataPtr =
      CefRequestCppToC::Get(self)->GetPostData();
  if(!postDataPtr.get())
    return NULL;

  return CefPostDataCppToC::Wrap(postDataPtr);
}

void CEF_CALLBACK request_set_post_data(struct _cef_request_t* self,
    struct _cef_post_data_t* postData)
{
  DCHECK(self);
  if(!self)
    return;

  CefRefPtr<CefPostData> postDataPtr;
  if(postData)
    postDataPtr = CefPostDataCppToC::Unwrap(postData);
  
  CefRequestCppToC::Get(self)->SetPostData(postDataPtr);
}

void CEF_CALLBACK request_get_header_map(struct _cef_request_t* self,
    cef_string_map_t headerMap)
{
  DCHECK(self);
  if(!self)
    return;

  CefRequest::HeaderMap map;
  CefRequestCppToC::Get(self)->GetHeaderMap(map);
  transfer_string_map_contents(map, headerMap);
}

void CEF_CALLBACK request_set_header_map(struct _cef_request_t* self,
    cef_string_map_t headerMap)
{
  DCHECK(self);
  if(!self)
    return;

  CefRequest::HeaderMap map;
  if(headerMap)
    transfer_string_map_contents(headerMap, map);

  CefRequestCppToC::Get(self)->SetHeaderMap(map);
}

void CEF_CALLBACK request_set(struct _cef_request_t* self,
    const cef_string_t* url, const cef_string_t* method,
    struct _cef_post_data_t* postData, cef_string_map_t headerMap)
{
  DCHECK(self);
  if(!self)
    return;

  CefRefPtr<CefPostData> postDataPtr;
  CefRequest::HeaderMap map;

  if(postData)
    postDataPtr = CefPostDataCppToC::Unwrap(postData);
  if(headerMap)
    transfer_string_map_contents(headerMap, map);

  CefRequestCppToC::Get(self)->Set(CefString(url), CefString(method),
      postDataPtr, map);
}

enum cef_weburlrequest_flags_t CEF_CALLBACK request_get_flags(
    struct _cef_request_t* self)
{
  DCHECK(self);
  if(!self)
    return WUR_FLAG_NONE;

  return CefRequestCppToC::Get(self)->GetFlags();
}

void CEF_CALLBACK request_set_flags(struct _cef_request_t* self,
    enum cef_weburlrequest_flags_t flags)
{
  DCHECK(self);
  if(!self)
    return;

  CefRequestCppToC::Get(self)->SetFlags(flags);
}

cef_string_userfree_t CEF_CALLBACK request_get_first_party_for_cookies(
    struct _cef_request_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefString urlStr = CefRequestCppToC::Get(self)->GetFirstPartyForCookies();
  return urlStr.DetachToUserFree();
}

void CEF_CALLBACK request_set_first_party_for_cookies(
    struct _cef_request_t* self, const cef_string_t* url)
{
  DCHECK(self);
  if(!self)
    return;

  CefRequestCppToC::Get(self)->SetFirstPartyForCookies(CefString(url));
}


// CONSTRUCTOR - Do not edit by hand.

CefRequestCppToC::CefRequestCppToC(CefRequest* cls)
    : CefCppToC<CefRequestCppToC, CefRequest, cef_request_t>(cls)
{
  struct_.struct_.get_url = request_get_url;
  struct_.struct_.set_url = request_set_url;
  struct_.struct_.get_method = request_get_method;
  struct_.struct_.set_method = request_set_method;
  struct_.struct_.get_post_data = request_get_post_data;
  struct_.struct_.set_post_data = request_set_post_data;
  struct_.struct_.get_header_map = request_get_header_map;
  struct_.struct_.set_header_map = request_set_header_map;
  struct_.struct_.set = request_set;
  struct_.struct_.get_flags = request_get_flags;
  struct_.struct_.set_flags = request_set_flags;
  struct_.struct_.get_first_party_for_cookies =
      request_get_first_party_for_cookies;
  struct_.struct_.set_first_party_for_cookies =
      request_set_first_party_for_cookies;
}

#ifndef NDEBUG
template<> long CefCppToC<CefRequestCppToC, CefRequest,
    cef_request_t>::DebugObjCt = 0;
#endif

