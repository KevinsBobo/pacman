#pragma once

#define SINGLE_INSTANCE(T)\
T* T::Instance(bool bRelease)\
{\
  static T* m_pApp = NULL;\
  if(!bRelease)\
  {\
    static int nNum = 0;\
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