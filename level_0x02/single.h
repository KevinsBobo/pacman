#pragma once

#define SINGLE_INSTANCE(T)\
T* T::Instance(bool bRelease)\
{\
  static int nNum = 0;\
  static T* m_pApp = NULL;\
  if(!bRelease)\
  {\
    ++nNum;\
    if(m_pApp == NULL)\
    {\
      m_pApp = new T();\
    }\
  }\
  else\
  {\
    if(--nNum == 0 && m_pApp != NULL)\
    {\
      delete m_pApp;\
      m_pApp = NULL;\
    }\
  }\
  return m_pApp;\
}

#define SINGLE_INSTANCE_STAT(T)\
  static T* Instance(bool bRelease = false)

#define CREATE_SINGLE_OBJ_PRESTATE(T) class CGet##T;

#define CREATE_SINGLE_OBJ(T)\
  class CGet##T\
  {\
  public:\
    CGet##T();\
    ~CGet##T();\
    T* get();\
  private:\
    T* m_singleObj;\
  };

#define CREATE_SINGLE_OBJ_REALIZE(T)\
  CGet##T::CGet##T()\
  {\
    m_singleObj = T::Instance();\
  }\
  CGet##T::~CGet##T()\
  {\
    T::Instance(true);\
    m_singleObj = NULL;\
  }\
  T* CGet##T::get()\
  {\
    return m_singleObj;\
  }
